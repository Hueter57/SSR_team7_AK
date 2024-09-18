#pragma once

#include <cstdint>

#include "ak/output/CytronMD.hpp"

namespace ak::output {
struct CytronMD
{
    uint8_t dir;
    uint8_t pwm;
};
}  // namespace ak::output