#pragma once

#include <Arduino.h>

namespace ak::output {
struct Servo
{
    uint32_t duty;

    constexpr static auto stop() -> Servo;
};
}  // namespace ak::output

constexpr auto ak::output::Servo::stop() -> ak::output::Servo {
    return Servo{0};
}
