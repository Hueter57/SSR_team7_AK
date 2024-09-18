#include "ak/System.hpp"

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
    {  // arm
        // l1ボタンで開いたり閉じたり
        if (input.button.l1) {
            output.arm.hand.pulse_width_us = this->pulse_width_arm_hand_open;
        } else {
            output.arm.hand.pulse_width_us = this->pulse_width_arm_hand_close;
        }
        // r1ボタンでリフトを上下
        if (input.button.r1) {
            output.arm.lift.pulse_width_us = this->pulse_width_arm_lift_up;
        } else {
            output.arm.lift.pulse_width_us = this->pulse_width_arm_lift_down;
        }
    }

    {  // launcher
        const auto f_a = this->forward_launcher_angle_of_fire;
        const auto f_c = this->forward_launcher_ball_compressor;

        // コンプレッサーは回しっぱなし
        output.launcher.ball_compressor = {.pwm1 = static_cast<uint8_t>(f_c ? 255 : 0),
                                           .pwm2 = static_cast<uint8_t>(f_c ? 0 : 255)};
        // upボタンとdownボタンで発射角度を調整
        const auto angle_of_fire_up   = input.button.up && f_a || input.button.down && !f_a;
        const auto angle_of_fire_down = input.button.down && f_a || input.button.up && !f_a;
        if (angle_of_fire_up) {
            output.launcher.angle_of_fire = {.pwm1 = 255, .pwm2 = 0};
        } else if (angle_of_fire_down) {
            output.launcher.angle_of_fire = {.pwm1 = 0, .pwm2 = 255};
        } else {
            output.launcher.angle_of_fire = {.pwm1 = 255, .pwm2 = 255};
        }
        // circleボタンで発射
        if (input.button.circle) {
            output.launcher.trigger.pulse_width_us = this->pulse_width_launcher_trigger_on;
        } else {
            output.launcher.trigger.pulse_width_us = this->pulse_width_launcher_trigger_off;
        }
    }

    {  // stearing
        constexpr float ANGLE_OFFSET_RF = 2.0f * PI / 3.0f;
        constexpr float ANGLE_OFFSET_LF = -2.0f * PI / 3.0f;
        constexpr float ANGLE_OFFSET_BK = 0.0f;

        const auto lx = input.analog.stick.lx;
        const auto ly = input.analog.stick.ly;
        const auto rx = input.analog.stick.rx;
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
    return output;
}