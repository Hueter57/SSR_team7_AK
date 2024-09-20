#include "ak/device/Launcher.hpp"

ak::device::Launcher::Launcher()
    : angle_of_fire(ak::assign::ANGLE_OF_FIRE_DIR_PIN1, ak::assign::ANGLE_OF_FIRE_DIR_PIN2,
                    ak::assign::ANGLE_OF_FIRE_PWM_PIN, ak::assign::ANGLE_OF_FIRE_PWM_CH),
      ball_compressor(ak::assign::BALL_COMPRESSOR_DIR_PIN1, ak::assign::BALL_COMPRESSOR_DIR_PIN2,
                      ak::assign::BALL_COMPRESSOR_PWM_PIN, ak::assign::BALL_COMPRESSOR_PWM_CH),
      trigger(ak::assign::TRIGGER_PIN, ak::assign::TRIGGER_CH) {
}

ak::device::Launcher::Launcher(ak::device::TB6612 angle_of_fire, ak::device::TB6612 ball_compressor,
                               ak::device::Servo trigger)
    : angle_of_fire(angle_of_fire), ball_compressor(ball_compressor), trigger(trigger) {
}

auto ak::device::Launcher::setup() -> void {
    this->angle_of_fire.setup();
    this->ball_compressor.setup();
    this->trigger.setup();

    this->stop();
}

auto ak::device::Launcher::stop() -> void {
    this->set_value(ak::output::Launcher::stop());
}

auto ak::device::Launcher::set_value(const ak::output::Launcher &value) -> void {
    this->angle_of_fire.set_value(value.angle_of_fire);
    this->ball_compressor.set_value(value.ball_compressor);
    this->trigger.set_value(value.trigger);
}