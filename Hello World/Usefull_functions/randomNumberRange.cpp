#include <cstdlib>


// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // static used for efficiency
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

// How does this work?