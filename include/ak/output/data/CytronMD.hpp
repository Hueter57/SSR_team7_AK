#pragma once

#include <cstdint>

#include "ak/motordriver/CytronMD.hpp"

namespace ak::output::data {
class CytronMD {
public:
    uint8_t dir;
    uint8_t pwm;

    auto attach(ak::motordriver::CytronMD &motordriver) -> void;
};
}  // namespace ak::output::data