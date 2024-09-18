#pragma once

#include <Ps3Controller.h>

#include "ak/input/Data.hpp"

namespace ak {
class Input {
private:
    Ps3Controller         ps3;
    static constexpr char PS3_MAC_ADDRESS[18] = "";

public:
    Input();
    auto begin_connection() -> void;
    auto attach_on_recieved(void (*on_recieved)()) -> void;
    auto attach_on_connected(void (*on_connected)()) -> void;
    auto attach_on_disconnected(void (*on_disconnected)()) -> void;
    auto data() const -> const input::Data &;
};
}  // namespace ak