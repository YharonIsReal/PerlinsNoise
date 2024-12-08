#ifndef PERLINS_NOISE_H
#define PERLINS_NOISE_H

#include <cmath>

class PerlinsNoise {
public:
    // Constructor with seed
    PerlinsNoise(int seed = 0);

    // 2D Perlin noise
    float noise2D(float x, float y);

private:
    int _seed; // Store the user-provided seed

    // Utility functions
    float fade(float t);
    float lerp(float a, float b, float t);
    float dotGridGradient(int ix, int iy, float x, float y);
    int hash(int x, int y);
    void getGradient(int hash, float& gradX, float& gradY);
};

#endif // PERLIN_NOISE_H