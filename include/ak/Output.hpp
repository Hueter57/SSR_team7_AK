#pragma once

#include "ak/output/Arm.hpp"
#include "ak/output/Launcher.hpp"
#include "ak/output/Stearing.hpp"

namespace ak {
struct Output
{
    output::Arm      arm;
    output::Launcher launcher;
    output::Stearing stearing;
};
}  // namespace ak
