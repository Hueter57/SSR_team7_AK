#pragma once

#include <Arduino.h>

#include "ak/output/CytronMD.hpp"

namespace ak::output {
struct CytronMD
{
    uint8_t dir;
    uint8_t pwm;

    constexpr static auto stop() -> CytronMD;
};
}  // namespace ak::output

constexpr auto ak::output::CytronMD::stop() -> ak::output::CytronMD {
    return CytronMD{LOW, 0};
}
