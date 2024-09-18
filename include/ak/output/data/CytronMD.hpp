#pragma once

#include <cstdint>

#include "ak/output/data/CytronMD.hpp"

namespace ak::output::data {
struct CytronMD
{
    uint8_t dir;
    uint8_t pwm;
};
}  // namespace ak::output::data