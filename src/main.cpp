#include <Arduino.h>

#include "ak/Delay.hpp"
#include "ak/Device.hpp"
#include "ak/Input.hpp"
#include "ak/Output.hpp"
#include "ak/System.hpp"

ak::Device device;
ak::System system;

void setup() {
    device.setup();
    system.init();
    system.set_forward_launcher(true, true);
    system.set_forward_stearing(true, true, true);
    system.set_pulse_width_arm(0, 0, 0, 0);
    system.set_pulse_width_launcher(0, 0);
}

void loop() {
    ak::Delay _;
    auto      input  = device.get_input();
    auto      output = system.update(input);
    device.set_value(output);
}
