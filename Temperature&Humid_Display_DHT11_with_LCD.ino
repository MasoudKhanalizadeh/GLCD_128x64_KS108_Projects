#include <Adafruit_GFX.h>
#include <KS0108_GLCD.h>
#include <Fonts/FreeSerif12pt7b.h>
#include <DHT.h>

// تنظیمات سنسور DHT
#define DHTPIN A3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// تنظیمات GLCD
KS0108_GLCD display = KS0108_GLCD(A0, A1, A2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
#define BACKLIGHT_PIN 13

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

  display.clearDisplay();
  display.setFont(&FreeSerif12pt7b);
  display.setTextColor(KS0108_ON);

  display.setCursor(0, 20);
  display.print(F("Temp: "));
  display.print(temperature);
  display.print(F(" C"));

  display.setCursor(0, 40);
  display.print(F("Humi: "));
  display.print(humidity);
  display.print(F(" %"));

  display.display();
  delay(2000);
}
