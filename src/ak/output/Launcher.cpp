#include "ak/output/Launcher.hpp"

auto ak::output::Launcher::stop() -> ak::output::Launcher {
    return Launcher{TB6612::stop(), TB6612::stop(), Servo::stop()};
}