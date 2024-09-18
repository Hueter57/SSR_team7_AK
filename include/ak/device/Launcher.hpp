#pragma once

#include "ak/Assign.hpp"
#include "ak/device/Servo.hpp"
#include "ak/device/TB6612.hpp"
#include "ak/output/Launcher.hpp"

namespace ak::device {
class Launcher {
private:
    TB6612 angle_of_fire;
    TB6612 ball_compressor;
    Servo  trigger;

public:
    Launcher();
    Launcher(TB6612 angle_of_fire, TB6612 ball_compressor, Servo trigger);
    auto setup() -> void;
    auto stop() -> void;
    auto set_value(const ak::output::Launcher &value) -> void;
};
}  // namespace ak::device