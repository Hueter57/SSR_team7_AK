#include "ak/Output.hpp"

auto ak::Output::stop() -> ak::Output {
    return Output{
        output::Arm::stop(), output::Launcher::stop(), output::Stearing::stop(), output::TrackId::NONE, HIGH, LOW};
}