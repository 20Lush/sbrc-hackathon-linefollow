#pragma once
#include "Motor.hpp"
#include "Arduino.h"

namespace SBRC {

    namespace INIT {
        /// @brief Arming routine for the brushed ESC used in Sauceathon-2024
        /// @param right
        /// @param left 
        inline void ArmDualChannelESC(Motor& right, Motor& left) {

            right.SetPower(0);
            left.SetPower(0);

            delay(500);

        }
    }

    const float MOTOR_PWR = 25;
    const float TURN_CTR_STEER = -10;
    const float SOFT_TURN_STEER = 70;

    namespace MOVE{
        /// @brief Moving bot forwards used in Sauceathon-2024
        /// @param right
        /// @param left 
        inline void forwards(Motor& left, Motor& right) {
            right.SetPower(MOTOR_PWR);
            left.SetPower(MOTOR_PWR);
        }

        /// @brief Moving bot backwards used in Sauceathon-2024
        /// @param right
        /// @param left 
        inline void backwards(Motor& left, Motor& right) {
            right.SetPower(-MOTOR_PWR);
            left.SetPower(-MOTOR_PWR);
        }

        /// @brief Parking the bot used in Sauceathon-2024
        /// @param right
        /// @param left 
        inline void stop(Motor& left, Motor& right) {
            right.SetPower(0);
            left.SetPower(0);
        }

        /// @brief Turning bot used in Sauceathon-2024
        /// @param right
        /// @param left 
        inline void left (Motor& left, Motor& right) {
            right.SetPower(MOTOR_PWR);
            left.SetPower(TURN_CTR_STEER);
        }

        /// @brief Turning bot used in Sauceathon-2024
        /// @param right
        /// @param left 
        inline void right (Motor& left, Motor& right) {
            right.SetPower(TURN_CTR_STEER);
            left.SetPower(MOTOR_PWR);
        }
        
        /// @brief Turning bot used in Sauceathon-2024
        /// @param right
        /// @param left 
        inline void softright (Motor& left, Motor& right) {
            right.SetPower(0.0f);
            left.SetPower(SOFT_TURN_STEER);
        }

        /// @brief Turning bot used in Sauceathon-2024
        /// @param right
        /// @param left 
        inline void softleft (Motor& left, Motor& right) {
            right.SetPower(SOFT_TURN_STEER);
            left.SetPower(0.0f);
        }
        


    }

}