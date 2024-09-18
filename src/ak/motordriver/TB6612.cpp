#include "ak/motordriver/TB6612.hpp"

ak::motordriver::TB6612::TB6612(uint8_t pwm_pin1, uint8_t pwm_pin2, uint8_t pwm_ch1, uint8_t pwm_ch2)
    : pwm_pin1(pwm_pin1), pwm_pin2(pwm_pin2), pwm_ch1(pwm_ch1), pwm_ch2(pwm_ch2) {
}

auto ak::motordriver::TB6612::setup() -> void {
    pinMode(this->pwm_pin1, OUTPUT);
    pinMode(this->pwm_pin2, OUTPUT);
    ledcSetup(this->pwm_ch1, PWM_FREQUANCY, PWM_RESOLUTION_BITS);
    ledcSetup(this->pwm_ch2, PWM_FREQUANCY, PWM_RESOLUTION_BITS);
    ledcAttachPin(this->pwm_pin1, this->pwm_ch1);
    ledcAttachPin(this->pwm_pin2, this->pwm_ch2);

    this->stop();
}

auto ak::motordriver::TB6612::stop() -> void {
    digitalWrite(this->pwm_pin1, HIGH);
    digitalWrite(this->pwm_pin2, HIGH);
}

auto ak::motordriver::TB6612::set_value(const ak::output::data::TB6612 &value) -> void {
    ledcWrite(this->pwm_ch1, value.pwm1);
    ledcWrite(this->pwm_ch2, value.pwm2);
}
