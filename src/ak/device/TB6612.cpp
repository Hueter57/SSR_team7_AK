#include "ak/device/TB6612.hpp"

ak::device::TB6612::TB6612(uint8_t dir_pin1, uint8_t dir_pin2, uint8_t pwm_pin, uint8_t pwm_ch)
    : dir_pin1(dir_pin1), dir_pin2(dir_pin2), pwm_pin(pwm_pin), pwm_ch(pwm_ch) {
}

auto ak::device::TB6612::setup() -> void {
    pinMode(this->pwm_pin, OUTPUT);
    pinMode(this->dir_pin1, OUTPUT);
    pinMode(this->dir_pin2, OUTPUT);
    ledcSetup(this->pwm_ch, PWM_FREQUANCY, PWM_RESOLUTION_BITS);
    ledcAttachPin(this->pwm_pin, this->pwm_ch);

    this->stop();
}

auto ak::device::TB6612::stop() -> void {
    this->set_value(ak::output::TB6612::stop());
}

auto ak::device::TB6612::set_value(const ak::output::TB6612 &value) -> void {
    digitalWrite(this->dir_pin1, value.dir1);
    digitalWrite(this->dir_pin2, value.dir2);
    ledcWrite(this->pwm_ch, value.pwm);
}
