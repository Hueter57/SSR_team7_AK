#pragma once

#include "ak/output/TrackId.hpp"

namespace ak::output {
enum class TrackId
{
    NONE          = 0,
    HAND_OPEN     = 1,
    LIFT_UP       = 2,
    ANGLE_OF_FIRE = 3,
    FIRE          = 4,
    MOVE          = 5
};
}  // namespace ak::output