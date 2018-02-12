#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class Random
{
        public:
                Random();
                int getIntInRange(int low, int high);

        private:
                std::mt19937 m_randNumGenerator;
};

#endif // RANDOM_H
