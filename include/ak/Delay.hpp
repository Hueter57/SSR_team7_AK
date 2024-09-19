#pragma once

#include <Arduino.h>

namespace ak {
class Delay {
public:
    static constexpr uint32_t TIME_MS = 50;
    ~Delay();
};
}  // namespace ak