#pragma once

#include "ak/device/CytronMD.hpp"
#include "ak/output/Stearing.hpp"

namespace ak::device {
class Stearing {
public:
    CytronMD right_front;
    CytronMD left_front;
    CytronMD back;

    auto setup() -> void;
    auto stop() -> void;
    auto set_value(const ak::output::Stearing &value) -> void;
};
}  // namespace ak::device