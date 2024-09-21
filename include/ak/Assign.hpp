#pragma once

#include <Arduino.h>

namespace ak::assign {
// TODO: 番号の設定
constexpr uint8_t LIFT_PWM_PIN             = 21;
constexpr uint8_t LIFT_PWM_CH              = 0;
constexpr uint8_t HAND_PWM_PIN             = 23;
constexpr uint8_t HAND_PWM_CH              = 1;
constexpr uint8_t ANGLE_OF_FIRE_DIR_PIN1   = 2;
constexpr uint8_t ANGLE_OF_FIRE_DIR_PIN2   = 4;
constexpr uint8_t ANGLE_OF_FIRE_PWM_PIN    = 15;
constexpr uint8_t ANGLE_OF_FIRE_PWM_CH     = 3;
constexpr uint8_t BALL_COMPRESSOR_DIR_PIN1 = 18;
constexpr uint8_t BALL_COMPRESSOR_DIR_PIN2 = 5;
constexpr uint8_t BALL_COMPRESSOR_PWM_PIN  = 19;
constexpr uint8_t BALL_COMPRESSOR_PWM_CH   = 3;
constexpr uint8_t TRIGGER_PIN              = 22;
constexpr uint8_t TRIGGER_CH               = 8;
constexpr uint8_t STR_RIGHT_FRONT_DIR_PIN  = 33;
constexpr uint8_t STR_RIGHT_FRONT_PWM_PIN  = 25;
constexpr uint8_t STR_RIGHT_FRONT_PWM_CH   = 5;
constexpr uint8_t STR_LEFT_FRONT_DIR_PIN   = 14;
constexpr uint8_t STR_LEFT_FRONT_PWM_PIN   = 12;
constexpr uint8_t STR_LEFT_FRONT_PWM_CH    = 6;
constexpr uint8_t STR_BACK_DIR_PIN         = 26;
constexpr uint8_t STR_BACK_PWM_PIN         = 27;
constexpr uint8_t STR_BACK_PWM_CH          = 7;
constexpr uint8_t STOP_LED_PIN             = 13;
constexpr uint8_t SOUND_PLAYER_LED_PIN     = 32;
}  // namespace ak::assign