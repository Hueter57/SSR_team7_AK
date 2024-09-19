#include "ak/output/Arm.hpp"

auto ak::output::Arm::stop() -> ak::output::Arm {
    return Arm{Servo::stop(), Servo::stop()};
}