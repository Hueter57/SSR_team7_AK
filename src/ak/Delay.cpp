#include "ak/Delay.hpp"

ak::Delay::~Delay() {
    delay(Delay::TIME_MS);
}