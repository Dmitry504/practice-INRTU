#include <FastLED.h> // библиотека

#define LED_COUNT 64
#define LED_PIN 3

CRGB leds[LED_COUNT];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LED_COUNT);
  FastLED.setBrightness(100);// яркость
}

void loop() {
  rainbowCycle(10);// запускаем эффект радуги с задержкой 10 
}

void rainbowCycle(uint8_t delayTime) {
  static uint8_t colorHue = 0; // меняем цвет с помощью переменной

  for (int i = 0; i < LED_COUNT; i++) {
    leds[i] = CHSV(colorHue + (i * 256 / LED_COUNT), 255, 255);
  }
  
  FastLED.show(); // обновляем цвета
  delay(delayTime);
  colorHue++; // меняем переменную цвета
}