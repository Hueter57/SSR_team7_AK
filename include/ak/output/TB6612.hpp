#pragma once

#include <Arduino.h>

namespace ak::output {
struct TB6612
{
    uint8_t dir1;
    uint8_t dir2;
    uint8_t pwm;

    constexpr static auto stop() -> TB6612;
};
}  // namespace ak::output

constexpr auto ak::output::TB6612::stop() -> ak::output::TB6612 {
    return TB6612{0, 0, 0};
}
