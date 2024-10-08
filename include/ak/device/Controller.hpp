#pragma once

#include <Ps3Controller.h>

#include "ak/Input.hpp"

namespace ak::device {
class Controller {
private:
    Ps3Controller ps3;

public:
    Controller();
    auto begin_connection() -> void;
    auto attach_on_recieved(void (*on_recieved)()) -> void;
    auto attach_on_connected(void (*on_connected)()) -> void;
    auto attach_on_disconnected(void (*on_disconnected)()) -> void;
    auto state() const -> const ps3_t &;
    auto event() const -> const ps3_event_t &;
};
}  // namespace ak::device