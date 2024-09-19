#pragma once

#include "ak/output/CytronMD.hpp"

namespace ak::output {
struct Stearing
{
    CytronMD right_front;
    CytronMD left_front;
    CytronMD back;

    static auto stop() -> Stearing;
};
}  // namespace ak::output