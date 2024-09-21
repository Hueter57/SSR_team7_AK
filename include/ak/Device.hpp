#pragma once

#include <DFPlayerMini_Fast.h>

#include "ak/Assign.hpp"
#include "ak/Input.hpp"
#include "ak/Output.hpp"
#include "ak/device/Arm.hpp"
#include "ak/device/Controller.hpp"
#include "ak/device/Launcher.hpp"
#include "ak/device/Stearing.hpp"

namespace ak {
class Device {
private:
    device::Arm        arm;
    device::Controller controller;
    device::Launcher   launcher;
    device::Stearing   stearing;
    HardwareSerial     serial_for_sound_player;
    DFPlayerMini_Fast  sound_player;

    static constexpr uint8_t  SOUND_PLAYER_UART_NUM      = 2;
    static constexpr uint32_t SOUND_PLAYER_UART_BAUDRATE = 9600;
    static constexpr uint8_t  SOUND_PLAYER_VOLUME        = 1;

public:
    Device();
    Device(device::Arm arm, device::Controller controller, device::Launcher launcher, device::Stearing stearing);
    auto setup() -> void;
    auto stop() -> void;
    auto get_input() const -> Input;
    auto set_value(const Output &value) -> void;
    auto controller_attach_on_recieved(void (*on_recieved)()) -> void;
    auto controller_attach_on_connected(void (*on_connected)()) -> void;
    auto controller_attach_on_disconnected(void (*on_disconnected)()) -> void;
};
}  // namespace ak