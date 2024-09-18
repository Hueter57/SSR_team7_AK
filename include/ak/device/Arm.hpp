#pragma once

#include "ak/Assign.hpp"
#include "ak/device/Servo.hpp"
#include "ak/output/Arm.hpp"

namespace ak::device {
class Arm {
private:
    Servo lift;
    Servo hand;

public:
    Arm();
    Arm(Servo lift, Servo hand);
    auto setup() -> void;
    auto stop() -> void;
    auto set_value(const ak::output::Arm &value) -> void;
};
}  // namespace ak::device