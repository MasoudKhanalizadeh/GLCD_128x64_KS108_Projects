#include <Adafruit_GFX.h>
#include <KS0108_GLCD.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeSansBold9pt7b.h>
#include <DHT.h>

// DHT sensor settings
#define DHTPIN A3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// GLCD settings
KS0108_GLCD display = KS0108_GLCD(A0, A1, A2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
#define BACKLIGHT_PIN 13

int textX = 128; // Horizontal starting position of the text (off-screen to the right)

void blinkText(const char* text, int x, int y, int blinks, int delayTime1, int delayTime2) {
  for (int i = 0; i < blinks; i++) {
    display.clearDisplay();
    display.setFont(&FreeSansBold9pt7b);
    display.setTextColor(KS0108_ON);
    display.setCursor(x, y);
    display.print(text);
    display.display();
    delay(delayTime1);

    display.clearDisplay();
    display.display();
    delay(delayTime2);
  }
}

void setup() {
  Serial.begin(9600);
  dht.begin();

  if (!display.begin(KS0108_CS_ACTIVE_HIGH)) {
    Serial.println(F("Display initialization failed!"));
    while (true);
  }

  display.clearDisplay();
  pinMode(BACKLIGHT_PIN, OUTPUT);
  digitalWrite(BACKLIGHT_PIN, HIGH);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    display.clearDisplay();
    display.setTextColor(KS0108_ON);
    display.setCursor(0, 35);
    display.print(F("Sensor Error"));
    display.display();
    delay(2000);
    return;
  }

  // Display temperature and humidity
  display.clearDisplay();
  display.setFont(&FreeSansBold12pt7b);
  display.setTextColor(KS0108_ON);

  display.setCursor(0, 20);
  display.print(F("T: "));
  display.print(temperature);
  display.print(F(" C"));

  display.setCursor(0, 40);
  display.print(F("H: "));
  display.print(humidity);
  display.print(F(" %"));

  // Display "Hi Masoud! You can do it Keep going!" as scrolling text
  display.setFont(&FreeSansBold9pt7b);
  display.setTextColor(KS0108_ON);
  display.setCursor(textX, 60);
  display.print(F("Hi Masoud! You can do it Keep going!"));

  display.display();

  // Move text to the left
  textX -= 3; // Speed of text movement (2 pixels per loop)
  if (textX < -180) { // When the text exits the screen, display blinking text
    blinkText("Just Do It!", 20, 30, 3, 1000, 250); // Blinking text
    textX = 128; // Reset the starting position of the scrolling text
  }

  delay(10); // Adjust display speed
}
