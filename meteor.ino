#include <FastLED.h>

#define LED_PIN 23
#define NUM_LEDS 600

CRGBArray<NUM_LEDS> leds;
CRGBArray<NUM_LEDS> previous_leds;

// 定義最大流星數量
#define MAX_METEORS 30

struct Meteor {
  int positionStart; //起始位置
  int position; //當前位置
  int size; //總長度
  int brightness; //亮度
  int speed; //移動速度
};

Meteor meteors[MAX_METEORS];

int meteor_size; //最大流星長度

void meteors_reset(int i) {
  meteor_size = round(NUM_LEDS / random(10, 30));
  meteors[i].positionStart = random(0, NUM_LEDS - meteor_size);
  meteors[i].position = 0; //當前流星本身狀態，大於0就代表動畫已觸發。
  meteors[i].size = meteor_size;
  meteors[i].brightness = random(150, 255); //流星亮度
  meteors[i].speed = random(1, 5); //隨機移動速度
}

void meteors_animation(int i) {
  if ((meteors[i].position != 0 ) || (random(200) < 1)) { // 1/80的機率會觸發流星
    for (int j = 0; j < meteors[i].position; j++) {
      if (j + 1 != meteors[i].position) {
        leds[meteors[i].positionStart + j] = CRGB(0, 0, meteors[i].brightness); //藍色
      } else {
        leds[meteors[i].positionStart + j] = CRGB(meteors[i].brightness, meteors[i].brightness, meteors[i].brightness);
        if (meteors[i].position >= meteors[i].size) {
          leds[meteors[i].positionStart + j] = CRGB(0, 0, 0);
        }
      }
    }

    if (meteors[i].position < meteors[i].size) {
      meteors[i].position += meteors[i].speed;
    } else if (meteors[i].brightness > 0) {
      if (meteors[i].brightness - 10 >= 0) {
        meteors[i].brightness -= 10;
      } else {
        meteors[i].brightness = 0;
      }
    } else {
      meteors_reset(i);
    }
  }
}

void twinklingStars() {
  // 隨機點亮一些像素點，模擬星星閃爍效果
  for (int i = 0; i < NUM_LEDS; i++) {
    int light = random(0, 255);
    if (random(10) < 2) { // 20% 的機率點亮像素點
      //leds[i] = CRGB::White; // 使用白色作為星星的顏色
      leds[i] = CRGB(light, light, light);
    }

    previous_leds[i] = leds[i];
  }
}

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50); // 設置亮度，根據需要調整

  // 初始化所有流星
  for (int i = 0; i < MAX_METEORS; i++) {
    meteors_reset(i);
  }
}

unsigned long twinklingStars_delayTime = 1000;
unsigned long twinklingStars_previous_delayTime = 0;
bool twinklingStars_current = false;

void loop() {
  unsigned long currentTime = millis();

  /*-----------------------------------*/
  leds(0, NUM_LEDS) = CRGB::Black; //固定
  /*-----------------------------------*/

  if (currentTime - twinklingStars_previous_delayTime >= twinklingStars_delayTime) {
    twinklingStars_current = true;
    twinklingStars_previous_delayTime = currentTime;
  }

  if (twinklingStars_current) {
    twinklingStars();
    twinklingStars_current = false;
  } else {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = previous_leds[i];
    }
  }

  for (int i = 0; i < MAX_METEORS; i++) {
    meteors_animation(i);
  }

  FastLED.show();
}
