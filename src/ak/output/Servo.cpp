#include "ak/output/Servo.hpp"

auto ak::output::Servo::stop() -> ak::output::Servo {
    return Servo{0};
}