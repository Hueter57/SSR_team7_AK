#include "ak/device/CytronMD.hpp"

ak::device::CytronMD::CytronMD(uint8_t dir_pin, uint8_t pwm_pin, uint8_t pwmch)
    : dir_pin(dir_pin), pwm_pin(pwm_pin), pwm_ch(pwmch) {
}

auto ak::device::CytronMD::setup() -> void {
    pinMode(this->dir_pin, OUTPUT);
    pinMode(this->pwm_pin, OUTPUT);
    ledcSetup(this->pwm_ch, PWM_FREQUANCY, PWM_RESOLUTION_BITS);
    ledcAttachPin(this->pwm_pin, this->pwm_ch);
    this->stop();
}

auto ak::device::CytronMD::stop() -> void {
    digitalWrite(this->dir_pin, LOW);
    ledcWrite(this->pwm_ch, 0);
}

auto ak::device::CytronMD::set_value(const ak::output::data::CytronMD &value) -> void {
    digitalWrite(this->dir_pin, value.dir);
    ledcWrite(this->pwm_ch, value.pwm);
}
