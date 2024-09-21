#pragma once

#include <Arduino.h>

namespace ak::output {
struct Servo
{
    uint32_t duty;

    static auto stop() -> Servo;
};
}  // namespace ak::output
