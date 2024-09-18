#include "ak/device/Servo.hpp"

ak::device::Servo::Servo(uint8_t pwm_pin, uint8_t pwm_ch) : pwm_pin(pwm_pin), pwm_ch(pwm_ch) {
}

auto ak::device::Servo::setup() -> void {
    pinMode(this->pwm_pin, OUTPUT);
    ledcSetup(this->pwm_ch, PWM_FREQUANCY, PWM_RESOLUTION_BITS);
    ledcAttachPin(this->pwm_pin, this->pwm_ch);
    this->stop();
}

auto ak::device::Servo::stop() -> void {
    ledcWrite(this->pwm_ch, 0);
}

auto ak::device::Servo::set_value(const ak::output::Servo &value) -> void {
    ledcWrite(this->pwm_ch, constrain(value.pulse_width_us, PWM_PULSE_WIDTH_MIN_US, PWM_PULSE_WIDTH_MAX_US));
}