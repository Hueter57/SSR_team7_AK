#include "ak/device/Launcher.hpp"

auto ak::device::Launcher::setup() -> void {
    this->angle_of_fire.setup();
    this->ball_compressor.setup();
    this->trigger.setup();
}

auto ak::device::Launcher::stop() -> void {
    this->angle_of_fire.stop();
    this->ball_compressor.stop();
    this->trigger.stop();
}

auto ak::device::Launcher::set_value(const ak::output::Launcher &value) -> void {
    this->angle_of_fire.set_value(value.angle_of_fire);
    this->ball_compressor.set_value(value.ball_compressor);
    this->trigger.set_value(value.trigger);
}