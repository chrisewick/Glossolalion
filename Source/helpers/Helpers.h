#pragma once

#include <stdlib.h>

// A collection of global functions.



float GetRandomNormal() {
    // Returns a randomized value between 0.0f and 1.0f inclusive.
    // Note that this is incredibly crude for the time being because I don't care deeply about it yet.
    // I legit just copied this from stack overflow: https://stackoverflow.com/questions/686353/random-float-number-generation
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

}