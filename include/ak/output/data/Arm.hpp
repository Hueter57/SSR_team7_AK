#pragma once

#include "ak/output/data/PWMServo.hpp"

namespace ak::output::data {
struct Arm
{
    Servo lift;
    Servo hand;
};
}  // namespace ak::output::data
