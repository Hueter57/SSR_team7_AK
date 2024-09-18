#pragma once

#include "ak/output/data/CytronMD.hpp"

namespace ak::output::data {
struct Stearing
{
    CytronMD right_front;
    CytronMD left_front;
    CytronMD back;
};
}  // namespace ak::output::data