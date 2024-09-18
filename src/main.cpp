#include <Arduino.h>

#include <ESP32Servo.h>

#include "ak/Ps3State.hpp"
#include "ak/motordriver/TB6612.hpp"

using ak::Input;
using ak::motordriver::TB6612;

TB6612 omniMotor1;
TB6612 omniMotor2;
TB6612 omniMotor3;

TB6612 firingMotor;
TB6612 firingDirectionMotor;
Servo  pushBollServo;

Servo grabbingServo;
Servo liftingServo;

Input input;

void setup() {
}

void loop() {
}
