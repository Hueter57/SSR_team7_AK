#pragma once

#include <Arduino.h>

#include "ak/output/CytronMD.hpp"

namespace ak::output {
struct CytronMD
{
    uint8_t dir;
    uint8_t pwm;

    static auto stop() -> CytronMD;
};
}  // namespace ak::output