#include <Adafruit_GFX.h>
#include <KS0108_GLCD.h>

// Font that works
#include <Fonts/FreeSerif12pt7b.h> 
// Initialize the display
KS0108_GLCD display = KS0108_GLCD(A0, A1, A2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);

#define BACKLIGHT_PIN 13 // Define the pin for backlight


void setup() {
  Serial.begin(9600); // Initialize Serial for debugging

  // Initialize the display
  if (!display.begin(KS0108_CS_ACTIVE_HIGH)) {
    Serial.println(F("Display initialization failed!"));
    while (true);
  }

  display.clearDisplay(); // Clear the display

  // Initialize the backlight pin
  pinMode(BACKLIGHT_PIN, OUTPUT);
  digitalWrite(BACKLIGHT_PIN, HIGH); // Turn on the backlight initially
}

void loop() {
  // Turn on the backlight
  digitalWrite(BACKLIGHT_PIN, HIGH);

  // Set the current font
  display.setFont(&FreeSerif12pt7b);

  // Clear the display and display the text
  display.clearDisplay();
  display.setTextColor(KS0108_ON);
  display.setCursor(10, 35); // Adjust based on font size
  display.print(F("Hello World!"));
  display.display();
  delay(1000); // Wait for 500 ms

  // Turn off the backlight
  digitalWrite(BACKLIGHT_PIN, LOW);

  // Clear the display to make it blink
  display.clearDisplay();
  display.display();
  delay(300); // Wait for 500 ms
}
