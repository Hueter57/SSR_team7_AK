#include "ak/motordriver/TB6612.hpp"

ak::motordriver::TB6612::TB6612(int pin1, int pin2, int ch1, int ch2) {
    in1Pin = pin1;
    in2Pin = pin2;
    pwmch1 = ch1;
    pwmch2 = ch2;
}

void ak::motordriver::TB6612::setup() {
    pinMode(in1Pin, OUTPUT);
    pinMode(in2Pin, OUTPUT);

    ledcSetup(pwmch1, 12800, 8);
    ledcAttachPin(in1Pin, pwmch1);
    ledcWrite(pwmch1, 0);

    ledcSetup(pwmch2, 12800, 8);
    ledcAttachPin(in2Pin, pwmch2);
    ledcWrite(pwmch2, 0);

    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, HIGH);
}

void ak::motordriver::TB6612::stop() {
    ledcWrite(pwmch1, LOW);
}

void ak::motordriver::TB6612::changeSpeed(int value) {
    speed = value;
    // Serial.print(value);
    if (value > 0) {
        digitalWrite(in2Pin, LOW);
        ledcWrite(pwmch1, value);
    } else if (value < 0) {
        digitalWrite(in1Pin, LOW);
        ledcWrite(pwmch2, -value);
    } else {
        ledcWrite(pwmch1, 0);
        digitalWrite(in1Pin, HIGH);
        digitalWrite(in2Pin, HIGH);
    }
}

auto ak::motordriver::TB6612::serialize() const -> std::array<char, 16> {
    auto result = std::array<char, 16>();
    sprintf(result.data(), "speed: %d", speed);
    return result;
}
