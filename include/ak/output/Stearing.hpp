#pragma once

#include "ak/output/CytronMD.hpp"

namespace ak::output {
struct Stearing
{
    CytronMD right_front;
    CytronMD left_front;
    CytronMD back;

    constexpr static auto stop() -> Stearing;
};
}  // namespace ak::output

constexpr auto ak::output::Stearing::stop() -> ak::output::Stearing {
    return Stearing{CytronMD::stop(), CytronMD::stop(), CytronMD::stop()};
}
