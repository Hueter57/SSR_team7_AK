#pragma once

#include "ak/output/TrackId.hpp"

namespace ak::output {
enum class TrackId
{
    NONE               = 0,
    RESTART            = 1,
    HAND_OPEN          = 2,
    LIFT_UP            = 3,
    ANGLE_OF_FIRE      = 4,
    FIRE               = 5,
    MOVE               = 6,
    SOUNDONLY_UP       = 7,
    SOUNDONLY_DOWN     = 8,
    SOUNDONLY_LEFT     = 9,
    SOUNDONLY_RIGHT    = 10,
    SOUNDONLY_TRIANGLE = 11,
    SOUNDONLY_CROSS    = 12,
    SOUNDONLY_SQUARE   = 13,
    SOUNDONLY_CIRCLE   = 14,
    SOUNDONLY_L1       = 15,
    SOUNDONLY_R1       = 16,
};
}  // namespace ak::output