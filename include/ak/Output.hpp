#pragma once

#include "ak/output/Arm.hpp"
#include "ak/output/Launcher.hpp"
#include "ak/output/Stearing.hpp"
#include "ak/output/TrackId.hpp"

namespace ak {
struct Output
{
    output::Arm      arm;
    output::Launcher launcher;
    output::Stearing stearing;
    output::TrackId  sound_track_id;

    static auto stop() -> Output;
};
}  // namespace ak
