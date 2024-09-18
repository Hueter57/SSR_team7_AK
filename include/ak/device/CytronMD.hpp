#pragma once

#include <array>
#include <cstdint>

#include <Arduino.h>

#include "ak/output/CytronMD.hpp"

namespace ak::device {
class CytronMD {
private:
    uint8_t dir_pin;
    uint8_t pwm_pin;
    uint8_t pwm_ch;

    static constexpr uint32_t PWM_FREQUANCY       = 12800;
    static constexpr uint8_t  PWM_RESOLUTION_BITS = 8;

public:
    CytronMD(uint8_t dir_pin, uint8_t pwm_pin, uint8_t pwmch);
    auto setup() -> void;
    auto stop() -> void;
    auto set_value(const ak::output::CytronMD &value) -> void;
};
}  // namespace ak::device