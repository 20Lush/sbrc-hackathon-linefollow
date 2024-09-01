
#pragma once

namespace SBRC {
    
    class Encoder {
        public:
            void Init(unsigned char pin);

            void Update();

            unsigned long GetElapsedTicks();

            unsigned int GetTickRate();

            void Zero();

        private:
            unsigned char m_pin;
            unsigned long m_ticks;

    };
}
