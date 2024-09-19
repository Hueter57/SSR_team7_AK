#include "ak/System.hpp"

auto ak::System::init() -> void {
    this->stop                   = true;
    this->sound_player_is_active = true;
    this->move_steps             = false;
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
    this->pulse_width_arm_lift_up    = lift_up;
    this->pulse_width_arm_lift_down  = lift_down;
    this->pulse_width_arm_hand_open  = hand_open;
    this->pulse_width_arm_hand_close = hand_close;
}

auto ak::System::set_pulse_width_launcher(int16_t trigger_on, int16_t trigger_off) -> void {
    this->pulse_width_launcher_trigger_on  = trigger_on;
    this->pulse_width_launcher_trigger_off = trigger_off;
}

auto ak::System::update(const ak::Input &input) -> ak::Output {
    auto output = ak::Output();
    if (input.event.button_down.start) {
        this->stop = !this->stop;
    }
    if (input.event.button_down.select) {
        this->sound_player_is_active = !this->sound_player_is_active;
    }
    if (this->stop) {
        return ak::Output::stop();
    }

    {  // arm
        // l1ボタンで開いたり閉じたり
        output.arm.hand.pulse_width_us =
            input.state.button.l1 ? this->pulse_width_arm_hand_open : this->pulse_width_arm_hand_close;
        // r1ボタンでリフトを上下
        output.arm.lift.pulse_width_us =
            input.state.button.r1 ? this->pulse_width_arm_lift_up : this->pulse_width_arm_lift_down;
    }

    {  // launcher
        const auto f_a = this->forward_launcher_angle_of_fire;
        const auto f_c = this->forward_launcher_ball_compressor;

        // upボタンとdownボタンで発射角度を調整
        const auto angle_of_fire_up   = input.state.button.up && f_a || input.state.button.down && !f_a;
        const auto angle_of_fire_down = input.state.button.down && f_a || input.state.button.up && !f_a;
        if (angle_of_fire_up) {
            output.launcher.angle_of_fire = {.pwm1 = 255, .pwm2 = 0};
        } else if (angle_of_fire_down) {
            output.launcher.angle_of_fire = {.pwm1 = 0, .pwm2 = 255};
        } else {
            output.launcher.angle_of_fire = {.pwm1 = 255, .pwm2 = 255};
        }

        // コンプレッサーは回しっぱなし
        output.launcher.ball_compressor = {.pwm1 = static_cast<uint8_t>(f_c ? 255 : 0),
                                           .pwm2 = static_cast<uint8_t>(f_c ? 0 : 255)};

        // circleボタンで発射
        if (input.state.button.circle) {
            output.launcher.trigger.pulse_width_us = this->pulse_width_launcher_trigger_on;
        } else {
            output.launcher.trigger.pulse_width_us = this->pulse_width_launcher_trigger_off;
        }
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

    // 音
    if (sound_player_is_active) {
        using ak::output::TrackId;

        // 大体15秒おきくらい
        if (move_steps % (15000 / Delay::TIME_MS) == 0) {
            output.sound_track_id = TrackId::MOVE;
        }
        output.sound_track_id = input.event.button_down.l1                                   ? TrackId::HAND_OPEN
                                : input.event.button_down.r1                                 ? TrackId::LIFT_UP
                                : input.event.button_down.up || input.event.button_down.down ? TrackId::ANGLE_OF_FIRE
                                                                                             : TrackId::NONE;
    }

    return output;
}