#include "ak/Device.hpp"

ak::Device::Device()
    : arm(), controller(), launcher(), stearing(), serial_for_sound_player(SOUND_PLAYER_UART_NUM), sound_player() {
}

ak::Device::Device(ak::device::Arm arm, ak::device::Controller controller, ak::device::Launcher launcher,
                   ak::device::Stearing stearing)
    : arm(arm), controller(controller), launcher(launcher), stearing(stearing),
      serial_for_sound_player(SOUND_PLAYER_UART_NUM), sound_player() {
}

auto ak::Device::setup() -> void {
    this->controller.begin_connection();
    this->arm.setup();
    this->launcher.setup();
    this->stearing.setup();
    this->serial_for_sound_player.begin(SOUND_PLAYER_UART_BAUDRATE);
    this->sound_player.begin(serial_for_sound_player);
    this->sound_player.volume(SOUND_PLAYER_VOLUME);
    pinMode(assign::STOP_LED_PIN, OUTPUT);
    pinMode(assign::SOUND_PLAYER_LED_PIN, OUTPUT);

    this->stop();
}

auto ak::Device::stop() -> void {
    this->set_value(ak::Output::stop());
}

auto ak::Device::get_input() const -> Input {
    return Input{this->controller.state(), this->controller.event()};
}

auto ak::Device::set_value(const Output &value) -> void {
    this->arm.set_value(value.arm);
    this->launcher.set_value(value.launcher);
    this->stearing.set_value(value.stearing);
    auto id = static_cast<uint8_t>(value.sound_track_id);
    if (id > 0) {
        this->sound_player.play(id);
    }
    digitalWrite(assign::STOP_LED_PIN, value.stop_led);
    digitalWrite(assign::SOUND_PLAYER_LED_PIN, value.sound_player_led);
}

auto ak::Device::controller_attach_on_recieved(void (*on_recieved)()) -> void {
    this->controller.attach_on_recieved(on_recieved);
}

auto ak::Device::controller_attach_on_connected(void (*on_connected)()) -> void {
    this->controller.attach_on_connected(on_connected);
}

auto ak::Device::controller_attach_on_disconnected(void (*on_disconnected)()) -> void {
    this->controller.attach_on_disconnected(on_disconnected);
}
