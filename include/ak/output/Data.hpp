#pragma once

#include "ak/output/data/Arm.hpp"
#include "ak/output/data/Launcher.hpp"
#include "ak/output/data/Stearing.hpp"

namespace ak::output {
struct Data
{
    data::Arm      arm;
    data::Launcher launcher;
    data::Stearing stearing;
};
}  // namespace ak::output