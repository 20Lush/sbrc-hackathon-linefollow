#include "Encoder.hpp"
#include "Arduino.h"

void SBRC::Encoder::Init(unsigned char laser_pin, unsigned char vis_pin) {
    m_laser_pin = laser_pin;
    m_vis_pin = vis_pin;

    m_laser.Init(m_laser_pin);
    m_vis.Init(m_vis_pin);

    m_laser.TurnOn();
}

void SBRC::Encoder::Update() {

    bool LastVisState = m_is_visible;
    m_is_visible = m_vis.Read();

    // We caught a transition from unblocked to blocked
    if(!m_is_visible && LastVisState) {
        m_ticks++;
    }
    
}

unsigned long SBRC::Encoder::GetElapsedTicks() {
    return m_ticks;
}

void SBRC::Encoder::Zero() {
    m_ticks = 0;
}