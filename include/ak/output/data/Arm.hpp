#pragma once

#include "ak/output/data/Servo.hpp"

namespace ak::output::data {
struct Arm
{
    Servo lift;
    Servo hand;
};
}  // namespace ak::output::data
