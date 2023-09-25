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

static uint8_t beginHue = 0;

int deltaHue = 1; //控制流速

void loop()
{
  fill_rainbow(leds, NUM_LEDS, beginHue, deltaHue);
  FastLED.show();
  beginHue += 2;
  if (beginHue == 256)
  {
    beginHue = 0;
  }
}
