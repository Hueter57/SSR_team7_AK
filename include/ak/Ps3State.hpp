#pragma once

#include <Ps3Controller.h>

namespace ak {
class Ps3State {
private:
    int x;
    int y;
    int rotate;

    int motorValue1;
    int motorValue2;
    int motorValue3;

public:
    auto getMotorOutput1() -> int;
    auto getMotorOutput2() -> int;
    auto getMotorOutput3() -> int;

    auto update(ps3_t data) -> void;
};
}  // namespace ak