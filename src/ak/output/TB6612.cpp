#include "ak/output/TB6612.hpp"

auto ak::output::TB6612::stop() -> ak::output::TB6612 {
    return TB6612{0, 0};
}