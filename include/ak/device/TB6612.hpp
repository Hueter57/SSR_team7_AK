#pragma once

#include <Arduino.h>

#include "ak/output/TB6612.hpp"

namespace ak::device {
class TB6612 {
private:
    uint8_t dir_pin1;
    uint8_t dir_pin2;
    uint8_t pwm_pin;
    uint8_t pwm_ch;

    static constexpr uint32_t PWM_FREQUANCY       = 12800;
    static constexpr uint8_t  PWM_RESOLUTION_BITS = 8;

public:
    TB6612(uint8_t dir_pin1, uint8_t dir_pin2, uint8_t pwm_pin, uint8_t pwm_ch);
    auto setup() -> void;
    auto stop() -> void;
    auto set_value(const output::TB6612 &value) -> void;
};
}  // namespace ak::device