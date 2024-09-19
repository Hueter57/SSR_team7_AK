#pragma once

#include "ak/output/Servo.hpp"
#include "ak/output/TB6612.hpp"

namespace ak::output {
struct Launcher
{
    TB6612 angle_of_fire;
    TB6612 ball_compressor;
    Servo  trigger;

    static auto stop() -> Launcher;
};
}  // namespace ak::output