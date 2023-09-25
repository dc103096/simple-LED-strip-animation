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

void fadeall()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i].nscale8(235);
  }
}

int num_1;
int num_2;
int px_R;
int px_G;
int px_B;

void loop()
{
  int model = 0;
  int i = 0;
  int j = NUM_LEDS;
  int stop = (NUM_LEDS / 2) + 1;
  int y = 0;
  int x = 0;
  int time = 0;
  int run = 0;
  int end = 0;
  int flower = 0;
  while (true)
  {
    switch (model)
    {
    case 0:
      leds[i] = CRGB::Orange;
      i++;
      leds[j] = CRGB::Orange;
      j--;

      delay(10);
      FastLED.show();
      fadeall();

      if (i == stop)
      {
        model = 1;
        i = stop;
        j = stop;
        y = 0;
      }
      break;
    case 1:
      switch (y)
      {
      case 0:
        if (x == 100)
        {
          y = 1;
        }
        fadeall();
        FastLED.show();
        delay(10);
        x++;
        break;
      case 1:
        if ((time > 100) && (i < NUM_LEDS))
        {
          leds[i] = CRGB::Orange;
          leds[j] = CRGB::Orange;
          fadeall();
        }
        else if (i < NUM_LEDS)
        {
          leds[i] = CRGB::White;
          leds[j] = CRGB::White;
        }
        else
        {
          model = 2;
          break;
        }

        i += 1;
        j -= 1;
        if (time <= 100)
        {
          time += 2;
        }
        FastLED.show();
        delay(time / 10);
        break;
      }
      break;
    case 2:
      if (run == 100)
      {
        model = 3;
        run = 0;
        break;
      }
      flower = random(0, NUM_LEDS);
      leds[flower] = CRGB(255, 255, 255);
      FastLED.show();
      delay(5);
      fadeall();
      run++;
      break;
    case 3:
      if (run == 100)
      {
        end = 1;
      }
      fadeall();
      FastLED.show();
      delay(5);
      run++;
    }

    if (end == 1)
    {
      break;
    }
  }
}
