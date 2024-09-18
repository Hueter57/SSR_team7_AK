#pragma once

#include "ak/output/data/CytronMD.hpp"

namespace ak::output {
class Data {
public:
    data::CytronMD stearing_right_front;
    data::CytronMD stearing_left_front;
    data::CytronMD stearing_back;
};
}  // namespace ak::output