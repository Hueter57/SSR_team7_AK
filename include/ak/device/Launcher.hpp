#pragma once

#include "ak/device/Servo.hpp"
#include "ak/device/TB6612.hpp"
#include "ak/output/Launcher.hpp"

namespace ak::device {
class Launcher {
public:
    TB6612 ball_compressor;
    TB6612 angle_of_fire;
    Servo  trigger;

    auto setup() -> void;
    auto stop() -> void;
    auto set_value(const ak::output::Launcher &value) -> void;
};
}  // namespace ak::device