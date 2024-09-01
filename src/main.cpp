//  ░▒▓███████▓▒░▒▓███████▓▒░░▒▓███████▓▒░ ░▒▓██████▓▒░  
// ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
// ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        
//  ░▒▓██████▓▒░░▒▓███████▓▒░░▒▓███████▓▒░░▒▓█▓▒░        
//        ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        
//        ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
// ░▒▓███████▓▒░░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░  

// Main function file. Create or use our modules in /lib

// Arduino framework
#include <Arduino.h>

// Project Constants and functions
#include "PinDefs.hpp"
#include "FuncDefs.hpp"

// Modules
#include "Motor.hpp"
#include "InfraredSensor.hpp"

// Module object definitions
SBRC::Motor MotorLeft;
SBRC::Motor MotorRight;
SBRC::IRSensor IRSensorLeft_0;
SBRC::IRSensor IRSensorMid_0;
SBRC::IRSensor IRSensorRight_0;

void setup() {

  // Module inits
  MotorLeft.Init(MOTOR_LEFT_PIN);
  MotorRight.Init(MOTOR_RIGHT_PIN);
  IRSensorLeft_0.Init(IR_LEFT_0_PIN);
  IRSensorMid_0.Init(IR_MID_0_PIN);
  IRSensorRight_0.Init(IR_RIGHT_0_PIN);

  // Arming the ESC during setup. Has 500ms blocking delay
  SBRC::INIT::ArmDualChannelESC(MotorLeft, MotorRight);

}

void loop() {
  
  // some PID and general differential control code. We don't want to do if-else bangbang anymore

}