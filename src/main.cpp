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
#include "Map.hpp"
#include "Encoder.hpp"

// Module object definitions
SBRC::Motor MotorLeft;
SBRC::Motor MotorRight;
SBRC::IRSensor IRSensorLeft_0;
SBRC::IRSensor IRSensorLeft_1;
SBRC::IRSensor IRSensorMid_0;
SBRC::IRSensor IRSensorRight_0;
SBRC::IRSensor IRSensorRight_1;
SBRC::Encoder Encoder_0;

void setup() {

  // Module inits
  MotorLeft.Init(MOTOR_LEFT_PIN);
  MotorRight.Init(MOTOR_RIGHT_PIN);
  IRSensorLeft_0.Init(IR_LEFT_0_PIN);
  IRSensorLeft_1.Init(IR_LEFT_1_PIN);
  IRSensorMid_0.Init(IR_MID_0_PIN);
  IRSensorRight_0.Init(IR_RIGHT_0_PIN);
  IRSensorRight_1.Init(IR_RIGHT_1_PIN);
  Encoder_0.Init(ENC_LSR_PIN, ENC_VIS_PIN);

  // Arming the ESC during setup. Has 500ms blocking delay
  SBRC::INIT::ArmDualChannelESC(MotorLeft, MotorRight);

  Serial.begin(9600);

}

void loop() {
  
  // some PID and general differential control code. We don't want to do if-else bangbang anymore
  
  Encoder_0.Update();

  Serial.println(Encoder_0.GetElapsedTicks());

  bool IR_L0 = IRSensorLeft_0.Read();
  bool IR_L1 = IRSensorLeft_1.Read();
  bool IR_M = IRSensorMid_0.Read();
  bool IR_R0 = IRSensorRight_0.Read();
  bool IR_R1 = IRSensorRight_1.Read();

  using namespace SBRC;

  #define FORWARD_DELAY_MS 500
  #define TURN_DELAY 200

  if(IR_L0) {
    MOVE::left(MotorLeft,MotorRight);
    Serial.println("l0 = left");
    delay(TURN_DELAY);
  }
  else if(IR_L1) {
    MOVE::softleft(MotorLeft, MotorRight);
    Serial.println("l1 = left");   
  }
  else if(IR_R1) {
    MOVE::right(MotorLeft,MotorRight);
    Serial.println("r1 = right");
    delay(TURN_DELAY);
  }
  else if(IR_R0) {
    MOVE::softright(MotorLeft, MotorRight);
    Serial.println("r0 = right");
  }
  else if(IR_R0 && IR_M) {
    MOVE::softright(MotorLeft, MotorRight);
    Serial.println("softright");
    delay(TURN_DELAY);
  }
  else if(IR_L1 && IR_M) {
    MOVE::softleft(MotorLeft, MotorRight);
    Serial.println("softleft");
    delay(TURN_DELAY);
  }
  else if(IR_L1 && IR_R0 && IR_M) {
    MOVE::forwards(MotorLeft, MotorRight);
    Serial.println("fwd");
    delay(FORWARD_DELAY_MS);
  }
  else if(IR_L0 && IR_R1) {
    MOVE::forwards(MotorLeft, MotorRight);
    Serial.println("fwd");
    delay(FORWARD_DELAY_MS);
  }
  else if (IR_L0 && IR_R0){
    MOVE::forwards(MotorLeft, MotorRight);
    Serial.println("fwd");
    delay(FORWARD_DELAY_MS);
  }
  else {
    MOVE::forwards(MotorLeft, MotorRight);
    Serial.println("fwd");
  }
}