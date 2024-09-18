#include "ak/device/Stearing.hpp"

ak::device::Stearing::Stearing()
    : right_front(ak::assign::STR_RIGHT_FRONT_DIR_PIN, ak::assign::STR_RIGHT_FRONT_PWM_PIN,
                  ak::assign::STR_RIGHT_FRONT_PWM_CH),
      left_front(ak::assign::STR_LEFT_FRONT_DIR_PIN, ak::assign::STR_LEFT_FRONT_PWM_PIN,
                 ak::assign::STR_LEFT_FRONT_PWM_CH),
      back(ak::assign::STR_BACK_DIR_PIN, ak::assign::STR_BACK_PWM_PIN, ak::assign::STR_BACK_PWM_CH) {
}

ak::device::Stearing::Stearing(ak::device::CytronMD right_front, ak::device::CytronMD left_front,
                               ak::device::CytronMD back)
    : right_front(right_front), left_front(left_front), back(back) {
}

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