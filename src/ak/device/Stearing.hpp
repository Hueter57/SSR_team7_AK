#include "ak/device/Stearing.hpp"

auto ak::device::Stearing::setup() -> void {
    this->right_front.setup();
    this->left_front.setup();
    this->back.setup();
}

auto ak::device::Stearing::stop() -> void {
    this->right_front.stop();
    this->left_front.stop();
    this->back.stop();
}

auto ak::device::Stearing::set_value(const ak::output::Stearing &value) -> void {
    this->right_front.set_value(value.right_front);
    this->left_front.set_value(value.left_front);
    this->back.set_value(value.back);
}