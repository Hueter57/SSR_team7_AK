#pragma once

#include <array>
#include <cstdint>

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
    auto set_value(uint8_t dir, uint8_t pwm) -> void;
};
}  // namespace ak::motordriver