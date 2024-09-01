#pragma once
#include "Motor.hpp"
#include "Arduino.h"

namespace SBRC {

    namespace INIT {

        /// @brief Arming routine for the brushed ESC used in Sauceathon-2024
        /// @param motor1
        /// @param motor2 
        inline void ArmDualChannelESC(Motor& motor1, Motor& motor2) {

            motor1.SetPower(0);
            motor2.SetPower(0);

            delay(500);

        }
    }

}