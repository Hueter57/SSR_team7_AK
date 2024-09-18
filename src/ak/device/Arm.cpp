#include "ak/device/Arm.hpp"

auto ak::device::Arm::setup() -> void {
    this->hand.setup();
    this->lift.setup();
    this->stop();
}

auto ak::device::Arm::stop() -> void {
    this->hand.stop();
    this->lift.stop();
}

auto ak::device::Arm::set_value(const ak::output::Arm &value) -> void {
    this->hand.set_value(value.hand);
    this->lift.set_value(value.lift);
}
