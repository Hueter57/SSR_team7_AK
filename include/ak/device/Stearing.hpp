#pragma once

#include "ak/Assign.hpp"
#include "ak/device/CytronMD.hpp"
#include "ak/output/Stearing.hpp"

namespace ak::device {
class Stearing {
private:
    CytronMD right_front;
    CytronMD left_front;
    CytronMD back;

public:
    Stearing();
    Stearing(CytronMD right_front, CytronMD left_front, CytronMD back);
    auto setup() -> void;
    auto stop() -> void;
    auto set_value(const ak::output::Stearing &value) -> void;
};
}  // namespace ak::device