#include <Arduino.h>

#include <ESP32Servo.h>

#include "ak/Input.hpp"
#include "ak/Ps3State.hpp"
#include "ak/motordriver/CytronMD.hpp"
#include "ak/motordriver/TB6612.hpp"

using ak::Input;
using ak::motordriver::CytronMD;
using ak::motordriver::TB6612;

CytronMD omniMotor1;
CytronMD omniMotor2;
CytronMD omniMotor3;

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
