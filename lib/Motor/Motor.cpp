#include "Motor.hpp"
#include "Map.hpp"

SBRC::Motor::Motor() {
    m_Servo = Servo();
}

void SBRC::Motor::Init(unsigned char pin) {

    m_pin = pin;

    m_Servo.attach(pin);

}

unsigned int SBRC::Motor::GetMicroseconds() {

    m_microseconds = SBRC::Map<unsigned int, float>(m_power_percent, MIN_PERCENTAGE, MAX_PERCENTAGE, MIN_MICROSECONDS, MAX_MICROSECONDS);

    return m_microseconds;
}

void SBRC::Motor::SetPower(float percentage) {

    m_power_percent = percentage;

    m_microseconds = GetMicroseconds();

    m_Servo.writeMicroseconds(m_microseconds);

}

float SBRC::Motor::GetPower() {
    return m_power_percent;
}