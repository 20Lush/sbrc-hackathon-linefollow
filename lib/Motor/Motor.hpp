//  ░▒▓███████▓▒░▒▓███████▓▒░░▒▓███████▓▒░ ░▒▓██████▓▒░  
// ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
// ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        
//  ░▒▓██████▓▒░░▒▓███████▓▒░░▒▓███████▓▒░░▒▓█▓▒░        
//        ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        
//        ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
// ░▒▓███████▓▒░░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░  

// The Motor module header file. Function prototypes for using a motor, extending Servo.h

#pragma once
#include <Servo.h>

namespace SBRC {
    // Standard motor object, extending the Servo library. I/O is done in percentages, with the back-end using microseconds
    class Motor {
        
        public: 
            /// @brief Motor object constructor. MUST BE INITIALIZED IN SETUP WITH `Init()` !!!
            Motor();

            /// @brief Init function that attaches the Servo subroutine to the designated pin. Goes in setup(), or a function run in setup().
            /// @param pin 
            void Init(unsigned char pin);

            /// @brief Gets the current PPM being sent on the channel
            /// @return unsigned integer probably between 1000-2000
            unsigned int GetMicroseconds();

            /// @brief Sets the power of the motor the instant it is called
            /// @param percentage floating point decimal between -100 and 100
            void SetPower(float percentage);

            /// @brief Gets the current power percentage of the motor
            /// @return percentage floating point decimal between -100 and 100
            float GetPower();

            /// @brief Sets forwards/reverse power bias. Used to correct threshold currents caused by manufacturing defects
            /// @param bias the amount of bias to apply to the motor
            void SetBias(float bias);

        private:
            Servo m_Servo;
            unsigned char m_pin;
            float m_power_percent = 0.0f;
            unsigned int m_microseconds = 1500;
            float m_bias = 0.0f;

            const int MIN_PERCENTAGE = -100;
            const int MAX_PERCENTAGE = 100;
            const unsigned int MIN_MICROSECONDS = 1000;
            const unsigned int MAX_MICROSECONDS = 2000;
            
    };
}