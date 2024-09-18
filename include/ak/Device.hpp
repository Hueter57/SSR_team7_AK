#include "ak/Input.hpp"
#include "ak/Output.hpp"
#include "ak/device/Arm.hpp"
#include "ak/device/Controller.hpp"
#include "ak/device/Launcher.hpp"
#include "ak/device/Stearing.hpp"

namespace ak {
class Device {
public:
    device::Arm        arm;
    device::Controller controller;
    device::Launcher   launcher;
    device::Stearing   stearing;

    auto setup() -> void;
    auto stop() -> void;
    auto get_input() const -> const Input &;
    auto set_value(const Output &value) -> void;
};
}  // namespace ak