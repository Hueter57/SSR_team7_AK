#include <Arduino.h>

#include "ak/Delay.hpp"
#include "ak/Device.hpp"
#include "ak/Input.hpp"
#include "ak/Output.hpp"
#include "ak/System.hpp"

ak::Device dev;
ak::System sys;

void setup() {
    dev.setup();
    sys.init();
    sys.set_forward_launcher(true, true);
    sys.set_forward_stearing(true, true, true);
    sys.set_pulse_width_arm(0, 0, 0, 0);
    sys.set_pulse_width_launcher(0, 0);
}

void loop() {
    ak::Delay _;
    auto      input  = dev.get_input();
    auto      output = sys.update(input);
    dev.set_value(output);
}
