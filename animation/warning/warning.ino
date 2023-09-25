#include <FastLED.h>

#define LED_PIN 23   // 定義燈帶資料腳位
#define NUM_LEDS 600 // LED燈數量

CRGBArray<NUM_LEDS> leds;

void setup()
{
  Serial.begin(115200);
  // 如果您的燈帶不是WS2812B，請自行更改您所使用的燈帶型號(備註: WS2815 須將 GRB 改成 RGB)
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2815, LED_PIN, RGB>(leds, NUM_LEDS);

  FastLED.setBrightness(50); // 設置亮度，根據需要調整
}

void loop()
{
  for(int i=0;i<=5;i++) {
    fill_solid(leds, 143, CRGB::Red);
    FastLED.show();
    delay(15);
    fill_solid(leds, 143, CRGB::Black);
    FastLED.show();
    delay(15);
  }

  for(int i=0;i<=5;i++) {
    fill_solid(leds+143, 144, CRGB::Blue);
    FastLED.show();
    delay(15);
    fill_solid(leds+143, 144, CRGB::Black);
    FastLED.show();
    delay(15);
  }
}
