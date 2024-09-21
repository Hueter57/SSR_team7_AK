#include <Arduino.h>

#include <Ps3Controller.h>

#include "ak/device/Controller.hpp"

ak::device::Controller::Controller() : ps3() {
}

auto ak::device::Controller::begin_connection() -> void {
    this->ps3.begin("90:34:FC:AA:AB:48");
}

auto ak::device::Controller::attach_on_recieved(void (*on_recieved)()) -> void {
    this->ps3.attach(on_recieved);
}

auto ak::device::Controller::attach_on_connected(void (*on_connected)()) -> void {
    this->ps3.attachOnConnect(on_connected);
}

auto ak::device::Controller::attach_on_disconnected(void (*on_disconnected)()) -> void {
    this->ps3.attachOnDisconnect(on_disconnected);
}

auto ak::device::Controller::state() const -> const ps3_t & {
    return this->ps3.data;
}

auto ak::device::Controller::event() const -> const ps3_event_t & {
    return this->ps3.event;
}
