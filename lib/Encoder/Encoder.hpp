//  ░▒▓███████▓▒░▒▓███████▓▒░░▒▓███████▓▒░ ░▒▓██████▓▒░  
// ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
// ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        
//  ░▒▓██████▓▒░░▒▓███████▓▒░░▒▓███████▓▒░░▒▓█▓▒░        
//        ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        
//        ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
// ░▒▓███████▓▒░░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░  

// The infrared sensor header file. Function prototypes for using the typical IR line following sensor
#pragma once
#include "Laser.hpp"
#include "VisibleSensor.hpp"

namespace SBRC {
    
    class Encoder {
        public:
            void Init(unsigned char laser_pin, unsigned char vis_pin);

            void Update();

            unsigned long GetElapsedTicks();

            unsigned int GetTickRate();

            void Zero();

        private:
            unsigned char m_laser_pin;
            unsigned char m_vis_pin;
            unsigned long m_ticks;
            bool m_is_visible;

            Laser m_laser;
            VisSensor m_vis;


    };
}
