#pragma once

#include "ak/output/CytronMD.hpp"

namespace ak::output {
struct Stearing
{
    CytronMD right_front;
    CytronMD left_front;
    CytronMD back;
};
}  // namespace ak::output