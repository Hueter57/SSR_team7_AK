#pragma once

#include "ak/output/Servo.hpp"
#include "ak/output/TB6612.hpp"

namespace ak::output {
struct Launcher
{
    TB6612 angle_of_fire;
    TB6612 ball_compressor;
    Servo  trigger;

    constexpr static auto stop() -> Launcher;
};
}  // namespace ak::output

constexpr auto ak::output::Launcher::stop() -> ak::output::Launcher {
    return Launcher{TB6612::stop(), TB6612::stop(), Servo::stop()};
}
