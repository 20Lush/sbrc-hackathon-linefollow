#include "Arduino.h"
#include "VisibleSensor.hpp"

SBRC::VisSensor::VisSensor() {}

void SBRC::VisSensor::Init(unsigned char pin) {
    m_pin = pin;

    pinMode(m_pin, INPUT);
}

bool SBRC::VisSensor::Read() {
    return static_cast<bool>(digitalRead(m_pin));
}