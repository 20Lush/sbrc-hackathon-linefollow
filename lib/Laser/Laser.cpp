#include "Arduino.h"
#include "Laser.hpp"

SBRC::Laser::Laser() {}

void SBRC::Laser::Init(unsigned char pin) {
    m_pin = pin;

    pinMode(m_pin, OUTPUT);
}

void SBRC::Laser::TurnOn() {
    m_on = true;
    digitalWrite(m_pin, HIGH);
}

void SBRC::Laser::TurnOff() {
    m_on = false;
    digitalWrite(m_pin, LOW);
}

bool SBRC::Laser::GetState() {
    return m_on;
}