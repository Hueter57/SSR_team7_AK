#pragma once

#include <array>
#include <cstdint>

#include "ak/output/data/CytronMD.hpp"

namespace ak::motordriver {
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
    auto set_value(const ak::output::data::CytronMD &value) -> void;
};
}  // namespace ak::motordriver