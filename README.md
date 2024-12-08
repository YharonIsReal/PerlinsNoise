# PerlinsNoise
A simple perlins noise library for arduino

Look at the examples first, here are the things you need to know to use the library:

PerlinsNoise perlin(12345); // You can change the seed here

renderPerlinsNoise(); // Draw the Perlin noise

float noiseValue = PerlinsNoise.noise2D(float x, float y); // Enter your floats instead of x and y
