#include <Arduino.h>

#include <Ps3Controller.h>

#include "ak/Input.hpp"

ak::Input::Input() : ps3() {
}

auto ak::Input::begin_connection() -> void {
    this->ps3.begin(ak::Input::PS3_MAC_ADDRESS);
}

auto ak::Input::attach_on_recieved(void (*on_recieved)()) -> void {
    this->ps3.attach(on_recieved);
}

auto ak::Input::attach_on_connected(void (*on_connected)()) -> void {
    this->ps3.attachOnConnect(on_connected);
}

auto ak::Input::attach_on_disconnected(void (*on_disconnected)()) -> void {
    this->ps3.attachOnDisconnect(on_disconnected);
}

auto ak::Input::data() const -> const ak::input::Data & {
    return this->ps3.data;
}
