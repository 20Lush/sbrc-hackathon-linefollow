#include "Arduino.h"
#include "InfraredSensor.hpp"

SBRC::IRSensor::IRSensor() {}

void SBRC::IRSensor::Init(unsigned char pin) {
    m_pin = pin;

    pinMode(m_pin, INPUT);
}

bool SBRC::IRSensor::Read() {
    return static_cast<bool>(digitalRead(m_pin));
}