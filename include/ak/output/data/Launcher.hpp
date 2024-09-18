#pragma once

#include "ak/output/data/Servo.hpp"
#include "ak/output/data/TB6612.hpp"

namespace ak::output::data {
struct Launcher
{
    TB6612 ball_compressor;
    TB6612 angle_of_fire;
    Servo  trigger;
};
}  // namespace ak::output::data