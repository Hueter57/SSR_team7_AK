#include "ak/Ps3State.hpp"

auto ak::Ps3State::getMotorOutput1() -> int {
    return 1;
}

auto ak::Ps3State::update(ps3_t data) -> void {
    const auto leftX  = data.analog.stick.lx;
    const auto leftY  = data.analog.stick.ly;
    const auto rightX = data.analog.stick.rx;
    const auto rightY = data.analog.stick.ry;

    auto signLX = leftX > 0 ? 1 : -1;
    rotate      = signLX * constrain(abs(leftX) - 15, 0, 100);
    auto signRX = rightX > 0 ? 1 : -1;
    x           = signRX * constrain(abs(rightX) - 15, 0, 100);
    auto signRY = rightY > 0 ? 1 : -1;
    y           = signRY * constrain(abs(rightY) - 15, 0, 100);

    motorValue1 = x;
    motorValue2 = (int)(-0.5 * x);
}
