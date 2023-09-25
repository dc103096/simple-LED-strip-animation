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

int L = 64;
int run = 1;
int R = 0;
int G = 0;
int B = 0;
int model = 0;

void loop() {
  for (int i = 0; i < NUM_LEDS; i+=1) {
    if (model == 0) {
      R = 255;
      G = 0;
      B = 0;
    } else if (model == 1) {
      R = 255;
      G = 165;
      B = 0;
    } else if (model == 2) {
      R = 255;
      G = 255;
      B = 0;
    } else if (model == 3) {
      R = 0;
      G = 255;
      B = 0;
    } else if (model == 4) {
      R = 0;
      G = 127;
      B = 255;
    } else if (model == 5) {
      R = 0;
      G = 0;
      B = 255;
    } else if (model == 6) {
      R = 139;
      G = 0;
      B = 255;
    }
    leds[i] = CRGB(R, G, B);
  }
  
  if(L>=64) {
    run = 0;
    delay(30);
  }

  if(L<=0) {
    run = 1;
    model++;
    delay(30);
  }

  if(model==7) {
    model=0;
  }

  if(run == 0) {
    L-=2;
  } else {
    L+=2;
  }
  FastLED.setBrightness(L);
  delay(1);
  FastLED.show();
}
