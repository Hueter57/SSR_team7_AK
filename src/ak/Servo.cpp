#include "ak/Servo.hpp"

#include <Arduino.h>

ak::Servo::Servo(uint8_t pwm_pin, uint8_t pwm_ch) : pwm_pin(pwm_pin), pwm_ch(pwm_ch) {
}

auto ak::Servo::setup() -> void {
    pinMode(this->pwm_pin, OUTPUT);
    ledcSetup(this->pwm_ch, PWM_FREQUANCY, PWM_RESOLUTION_BITS);
    ledcAttachPin(this->pwm_pin, this->pwm_ch);
    this->stop();
}

auto ak::Servo::stop() -> void {
    ledcWrite(this->pwm_ch, 0);
}

auto ak::Servo::set_value(const ak::output::data::Servo &value) -> void {
    ledcWrite(this->pwm_ch, constrain(value.pulse_width_us, PWM_PULSE_WIDTH_MIN_US, PWM_PULSE_WIDTH_MAX_US));
}
