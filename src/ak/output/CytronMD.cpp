#include "ak/output/CytronMD.hpp"

auto ak::output::CytronMD::stop() -> ak::output::CytronMD {
    return CytronMD{LOW, 0};
}