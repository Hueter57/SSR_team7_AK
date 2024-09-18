#include "ak/Device.hpp"

ak::Device::Device() : arm(), controller(), launcher(), stearing() {
}

ak::Device::Device(ak::device::Arm arm, ak::device::Controller controller, ak::device::Launcher launcher,
                   ak::device::Stearing stearing)
    : arm(arm), controller(controller), launcher(launcher), stearing(stearing) {
}

auto ak::Device::setup() -> void {
    this->controller.begin_connection();
    this->arm.setup();
    this->launcher.setup();
    this->stearing.setup();
}

auto ak::Device::stop() -> void {
    this->arm.stop();
    this->launcher.stop();
    this->stearing.stop();
}

auto ak::Device::get_input() const -> const Input & {
    return this->controller.data();
}

auto ak::Device::set_value(const Output &value) -> void {
    this->arm.set_value(value.arm);
    this->launcher.set_value(value.launcher);
    this->stearing.set_value(value.stearing);
}