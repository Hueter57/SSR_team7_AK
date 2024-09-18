#pragma once

#include <Arduino.h>
// TB6612使用 Dual DCモータードライブキット用
// TB6612{エンコーダー入力1, エンコーダー入力2, モーター出力指定正, モーター出力指定負}

#include "ak/output/data/TB6612.hpp"

namespace ak::motordriver {
class TB6612 {
public:
    uint8_t pwm_pin1;
    uint8_t pwm_pin2;
    uint8_t pwm_ch1;
    uint8_t pwm_ch2;

    static constexpr uint32_t PWM_FREQUANCY       = 12800;
    static constexpr uint8_t  PWM_RESOLUTION_BITS = 8;

    TB6612(uint8_t pwm_pin1, uint8_t pwm_pin2, uint8_t pwm_ch1, uint8_t pwm_ch2);
    auto setup() -> void;
    auto stop() -> void;
    auto set_value(const output::data::TB6612 &value) -> void;
};
}  // namespace ak::motordriver