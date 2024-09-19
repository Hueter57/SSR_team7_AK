#pragma once

#include <include/ps3.h>

namespace ak {
struct Input
{
    ps3_t       state;
    ps3_event_t event;
};
}  // namespace ak
