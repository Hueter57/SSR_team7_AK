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
    uint8_t          stop_led;
    uint8_t          sound_player_led;

    static auto stop() -> Output;
};
}  // namespace ak
