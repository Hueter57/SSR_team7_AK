#pragma once

#include "ak/output/Servo.hpp"

namespace ak::output {
struct Arm
{
    Servo hand;
    Servo lift;

    constexpr static auto stop() -> Arm;
};
}  // namespace ak::output

constexpr auto ak::output::Arm::stop() -> ak::output::Arm {
    return Arm{Servo::stop(), Servo::stop()};
}
