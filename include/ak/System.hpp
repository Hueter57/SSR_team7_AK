#pragma once

#include <Ps3Controller.h>

#include "ak/Delay.hpp"
#include "ak/Device.hpp"
#include "ak/Input.hpp"
#include "ak/Output.hpp"

namespace ak {
// Input -> Outputの変換を行う。内部状態を持つため、クラスで宣言。
class System {
private:
    bool     stop;
    bool     sound_player_is_active;
    uint32_t move_steps;

    bool    forward_launcher_ball_compressor;
    bool    forward_launcher_angle_of_fire;
    bool    forward_stearing_right_front;
    bool    forward_stearing_left_front;
    bool    forward_stearing_back;
    int16_t angle_arm_lift_up;
    int16_t angle_arm_lift_down;
    int16_t angle_arm_hand_open;
    int16_t angle_arm_hand_close;
    int16_t angle_launcher_trigger_on;
    int16_t angle_launcher_trigger_off;

public:
    auto init() -> void;
    auto set_forward_launcher(bool ball_compressor, bool angle_of_fire) -> void;
    auto set_forward_stearing(bool right_front, bool left_front, bool back) -> void;
    auto set_pulse_width_arm(int16_t lift_up, int16_t lift_down, int16_t hand_open, int16_t hand_close) -> void;
    auto set_pulse_width_launcher(int16_t trigger_on, int16_t trigger_off) -> void;
    auto update(const ak::Input &input) -> ak::Output;
};
}  // namespace ak
