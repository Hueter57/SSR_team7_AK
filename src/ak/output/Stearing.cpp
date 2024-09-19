#include "ak/output/Stearing.hpp"

auto ak::output::Stearing::stop() -> ak::output::Stearing {
    return Stearing{CytronMD::stop(), CytronMD::stop(), CytronMD::stop()};
}