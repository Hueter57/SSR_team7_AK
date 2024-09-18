#pragma once

#include "ak/output/Servo.hpp"
#include "ak/output/TB6612.hpp"

namespace ak::output {
struct Launcher
{
    TB6612 ball_compressor;
    TB6612 angle_of_fire;
    Servo  trigger;
};
}  // namespace ak::output