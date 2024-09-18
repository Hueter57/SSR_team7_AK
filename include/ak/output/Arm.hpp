#pragma once

#include "ak/output/Servo.hpp"

namespace ak::output {
struct Arm
{
    Servo lift;
    Servo hand;
};
}  // namespace ak::output
