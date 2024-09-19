#pragma once

#include <Arduino.h>

namespace ak::output {
struct Servo
{
    int16_t pulse_width_us;

    static auto stop() -> Servo;
};
}  // namespace ak::output
