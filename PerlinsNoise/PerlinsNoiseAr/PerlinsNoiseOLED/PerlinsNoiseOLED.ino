#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <PerlinsNoise.h>

// Display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

PerlinsNoise PerlinsNoiseSc(654123); // You can change the seed here

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  // Clear the display buffer
  display.clearDisplay();

  // Draw the Perlin noise
  renderPerlinsNoise();

  // Show the buffer
  display.display();
}

void loop() {
    // Nothing here for now
}

// Function to render Perlin noise on the OLED screen
void renderPerlinsNoise() {
  float scale = 0.1; // Scale factor for Perlin noise
  for (int y = 0; y < SCREEN_HEIGHT; y++) {
    for (int x = 0; x < SCREEN_WIDTH; x++) {
      // Generate Perlin noise value for each pixel
      float noiseValue = PerlinsNoiseSc.noise2D(x * scale, y * scale);

      // Map noise value (-1 to 1) to grayscale (0 to 255)
      int color = map(noiseValue * 255, 0, 255, 0, 1); 

      // Draw pixel on the display
      display.drawPixel(x, y, color);
    }
  }
}