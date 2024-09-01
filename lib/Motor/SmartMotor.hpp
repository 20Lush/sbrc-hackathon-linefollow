//  ░▒▓███████▓▒░▒▓███████▓▒░░▒▓███████▓▒░ ░▒▓██████▓▒░  
// ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
// ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        
//  ░▒▓██████▓▒░░▒▓███████▓▒░░▒▓███████▓▒░░▒▓█▓▒░        
//        ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        
//        ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
// ░▒▓███████▓▒░░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░  

// SmartMotor header file. Function prototypes for an odometric gear motor

#pragma once
#include "Motor.hpp"
#include "Encoder.hpp"

namespace SBRC {
    enum SmartMotorModes {
        POSITION,
        VELOCITY,
        ACCELERATION
    };

    class SmartMotor : public Motor {

        public:

            SmartMotor();

            unsigned long GetCurrentTicks();

            float GetCurrentDisplacement();

            float GetCurrentVelocity();

            float GetCurrentAcceleration();

            void SetVelocity();

            void SetRamp(float acceleration, float deceleration);

        private:
            SmartMotorModes m_mode;
            Encoder m_encoder;
            unsigned int m_wheel_diameter;
            float m_position;
            float m_velocity;
            float m_acceleration;

            float m_ramp_acceleration;
            float m_ramp_deceleration;
            float m_velocity_max;
            float m_accleration_max;
            
    };
}