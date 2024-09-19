#pragma once

#include "ak/output/Servo.hpp"

namespace ak::output {
struct Arm
{
    Servo hand;
    Servo lift;

    static auto stop() -> Arm;
};
}  // namespace ak::output
