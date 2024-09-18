#include "ak/motordriver/CytronMD.hpp"

#include <Arduino.h>

ak::motordriver::CytronMD::CytronMD(uint8_t dir_pin, uint8_t pwm_pin, uint8_t pwmch)
    : dir_pin(dir_pin), pwm_pin(pwm_pin), pwm_ch(pwmch) {
}

auto ak::motordriver::CytronMD::setup() -> void {
    pinMode(this->dir_pin, OUTPUT);
    pinMode(this->pwm_pin, OUTPUT);
    ledcSetup(this->pwm_ch, PWM_FREQUANCY, PWM_RESOLUTION_BITS);
    ledcAttachPin(this->pwm_pin, this->pwm_ch);
    this->stop();
}

auto ak::motordriver::CytronMD::stop() -> void {
    digitalWrite(dir_pin, LOW);
    ledcWrite(pwm_ch, 0);
}

auto ak::motordriver::CytronMD::set_value(uint8_t dir, uint8_t pwm) -> void {
    digitalWrite(dir_pin, dir);
    ledcWrite(pwm_ch, pwm);
}
