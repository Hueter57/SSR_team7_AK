#pragma once

#include <Arduino.h>

namespace ak::output {
struct TB6612
{
    uint8_t dir1;
    uint8_t dir2;
    uint8_t pwm;

    static auto stop() -> TB6612;
};
}  // namespace ak::output