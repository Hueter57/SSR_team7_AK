#pragma once

#include <Arduino.h>

namespace ak::output {
struct Servo
{
    int16_t pulse_width_us;
};
}  // namespace ak::output
