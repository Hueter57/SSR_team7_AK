#pragma once

#include <Arduino.h>

#include "ak/output/data/Servo.hpp"

namespace ak::device {
class Servo {
private:
    uint8_t pwm_pin;
    uint8_t pwm_ch;

    static constexpr uint32_t PWM_FREQUANCY          = 50;
    static constexpr uint8_t  PWM_RESOLUTION_BITS    = 10;
    static constexpr uint32_t PWM_PULSE_WIDTH_MIN_US = 500;
    static constexpr uint32_t PWM_PULSE_WIDTH_MAX_US = 2400;
    static constexpr int32_t  ANGLE_MIN_DEG          = 0;
    static constexpr int32_t  ANGLE_MAX_DEG          = 180;

public:
    Servo(uint8_t pwm_pin, uint8_t pwm_ch);

    auto setup() -> void;
    auto stop() -> void;
    auto set_value(const output::data::Servo &value) -> void;
};
}  // namespace ak