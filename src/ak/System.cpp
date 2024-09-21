#include "ak/System.hpp"

auto ak::System::init() -> void {
    this->stop                   = true;
    this->sound_player_is_active = true;
    this->move_steps             = 0;
}

auto ak::System::set_forward_launcher(bool ball_compressor, bool angle_of_fire) -> void {
    this->forward_launcher_ball_compressor = ball_compressor;
    this->forward_launcher_angle_of_fire   = angle_of_fire;
}

auto ak::System::set_forward_stearing(bool right_front, bool left_front, bool back) -> void {
    this->forward_stearing_right_front = right_front;
    this->forward_stearing_left_front  = left_front;
    this->forward_stearing_back        = back;
}

auto ak::System::set_pulse_width_arm(int16_t lift_up, int16_t lift_down, int16_t hand_open,
                                     int16_t hand_close) -> void {
    this->angle_arm_lift_up    = lift_up;
    this->angle_arm_lift_down  = lift_down;
    this->angle_arm_hand_open  = hand_open;
    this->angle_arm_hand_close = hand_close;
}

auto ak::System::set_pulse_width_launcher(int16_t trigger_on, int16_t trigger_off) -> void {
    this->angle_launcher_trigger_on  = trigger_on;
    this->angle_launcher_trigger_off = trigger_off;
}

auto ak::System::update(const ak::Input &input) -> ak::Output {
    auto output = ak::Output::stop();

    if (this->stop) {
        if (!input.event.button_down.start) {
            return output;
        }
        this->stop = false;
    } else if (input.event.button_down.start) {
        this->stop = true;
        return output;
    }
    output.stop_led = LOW;

    if (input.event.button_down.select) {
        this->sound_player_is_active = !this->sound_player_is_active;
    }

    const bool sound_only_mode = input.state.button.r2;

    // r2が押されている間(`sound_only_mode` == true)は機体は動かない (音だけ)
    if (!sound_only_mode) {
        {  // arm
            // pwm max: 1024 (大体1000で計算)
            // l1ボタンで開いたり閉じたり
            output.arm.hand.duty = static_cast<uint32_t>(
                map(input.state.button.l1 ? this->angle_arm_hand_open : this->angle_arm_hand_close, 0, 180, 25, 120));
            Serial.printf("%d\n", output.arm.hand.duty);
            // r1ボタンでリフトを上下
            output.arm.lift.duty = static_cast<uint32_t>(
                map(input.state.button.r1 ? this->angle_arm_lift_up : this->angle_arm_lift_down, 0, 180, 25, 120));
        }

        {  // launcher
            using ak::output::TB6612;

            const auto f_a = this->forward_launcher_angle_of_fire;
            const auto f_c = this->forward_launcher_ball_compressor;

            // upボタンとdownボタンで発射角度を調整
            const auto angle_of_fire_up   = input.state.button.up && f_a || input.state.button.down && !f_a;
            const auto angle_of_fire_down = input.state.button.down && f_a || input.state.button.up && !f_a;
            output.launcher.angle_of_fire = angle_of_fire_up     ? TB6612{.dir1 = HIGH, .dir2 = LOW, .pwm = 255}
                                            : angle_of_fire_down ? TB6612{.dir1 = LOW, .dir2 = HIGH, .pwm = 255}
                                                                 : TB6612{.dir1 = HIGH, .dir2 = HIGH, .pwm = 255};

            // コンプレッサーは回しっぱなし
            output.launcher.ball_compressor = {
                .dir1 = static_cast<uint8_t>(f_c), .dir2 = static_cast<uint8_t>(!f_c), .pwm = 255};

            // pwm max: 1024 (大体1000で計算)
            // circleボタンで発射
            output.launcher.trigger.duty = static_cast<uint32_t>(
                map(input.state.button.circle ? this->angle_launcher_trigger_on : this->angle_launcher_trigger_off, 0,
                    180, 25, 120));
        }

        {  // stearing
            constexpr float ANGLE_OFFSET_RF = 2.0f * PI / 3.0f;
            constexpr float ANGLE_OFFSET_LF = -2.0f * PI / 3.0f;
            constexpr float ANGLE_OFFSET_BK = 0.0f;

            const auto lx = input.state.analog.stick.lx;
            const auto ly = input.state.analog.stick.ly;
            const auto rx = input.state.analog.stick.rx;
            if (lx > 10 || ly > 10 || rx > 10) {
                move_steps++;
            } else {
                move_steps = 0;
            }
            // stick value: -127 ~ 127
            auto spd_rf = constrain(lx * std::cos(ANGLE_OFFSET_RF) + ly * std::sin(ANGLE_OFFSET_RF) + rx, -255, 255);
            auto spd_lf = constrain(lx * std::cos(ANGLE_OFFSET_LF) + ly * std::sin(ANGLE_OFFSET_LF) + rx, -255, 255);
            auto spd_bk = constrain(lx * std::cos(ANGLE_OFFSET_BK) + ly * std::sin(ANGLE_OFFSET_BK) + rx, -255, 255);

            output.stearing.right_front.dir = static_cast<uint8_t>(
                std::signbit(spd_rf) == this->forward_stearing_right_front);  // `forward_*`の値によって方向を変化

            output.stearing.left_front.dir = static_cast<uint8_t>(
                std::signbit(spd_lf) == this->forward_stearing_left_front);  // `forward_*`の値によって方向を変化

            output.stearing.back.dir = static_cast<uint8_t>(
                std::signbit(spd_bk) == this->forward_stearing_back);  // `forward_*`の値によって方向を変化

            output.stearing.right_front.pwm = std::abs(spd_rf);
            output.stearing.left_front.pwm  = std::abs(spd_lf);
            output.stearing.back.pwm        = std::abs(spd_bk);
        }
    }

    // 音
    using ak::output::TrackId;
    if (sound_player_is_active) {
        output.sound_player_led = HIGH;
        if (sound_only_mode) {
            output.sound_track_id = input.event.button_down.up         ? TrackId::SOUNDONLY_UP
                                    : input.event.button_down.down     ? TrackId::SOUNDONLY_DOWN
                                    : input.event.button_down.left     ? TrackId::SOUNDONLY_LEFT
                                    : input.event.button_down.right    ? TrackId::SOUNDONLY_RIGHT
                                    : input.event.button_down.triangle ? TrackId::SOUNDONLY_TRIANGLE
                                    : input.event.button_down.cross    ? TrackId::SOUNDONLY_CROSS
                                    : input.event.button_down.square   ? TrackId::SOUNDONLY_SQUARE
                                    : input.event.button_down.circle   ? TrackId::SOUNDONLY_CIRCLE
                                    : input.event.button_down.l1       ? TrackId::SOUNDONLY_L1
                                    : input.event.button_down.r1       ? TrackId::SOUNDONLY_R1
                                                                       : TrackId::NONE;
        } else {
            // 大体5秒おきくらい
            if (move_steps % (5000 / Delay::TIME_MS) == 0) {
                output.sound_track_id = TrackId::MOVE;
            }
            output.sound_track_id = (input.event.button_down.start && !this->stop) ? TrackId::RESTART
                                    : input.event.button_down.l1                   ? TrackId::HAND_OPEN
                                    : input.event.button_down.r1                   ? TrackId::LIFT_UP
                                    : input.event.button_down.up || input.event.button_down.down
                                        ? TrackId::ANGLE_OF_FIRE
                                        : TrackId::NONE;
        }
    } else {
        output.sound_player_led = LOW;
        output.sound_track_id   = TrackId::NONE;
    }

    return output;
}