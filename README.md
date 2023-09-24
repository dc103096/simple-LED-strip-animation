# 簡易燈帶特效

## 🚀 Introduction
這是一個基於支援 WS281X RGB LED 系列的特效庫所設計的簡易特效，利用 ESP32S 微控制器和 FastLED 庫實現。該特效庫允許你創建簡潔、多彩的 LED 燈光效果，適用於多種應用，包括裝飾、藝術展示、建築照明等。

## 🌟 Features

- 彩虹燈：顯示彩虹色，您也可以選擇流動速度。

  <img src="./gif/rainbow.gif" alt="rainbow" width="180" height="320">

- 警車燈：紅藍快速交替閃爍。

  <img src="./gif/warning.gif" alt="warning" width="180" height="320">

- 流水燈：快速顯示流動燈效。

  <img src="./gif/Scroller.gif" alt="Scroller" width="180" height="320">

- 煙火燈：細緻的煙火動畫。

  <img src="./gif/hanabi.gif" alt="hanabi" width="180" height="320">

- (待更新)

## 📥 Installation from source

###### Clone the repository

1. 克隆儲存庫
```sh
git clone https://github.com/dc103096/simple-LED-strip-animation.git
```
2. 將指定特效的副檔名 .ino 使用Arduino IDE開啟

3. 編譯並寫入指定微處理器

###### 硬體配置要求

- ESP32, ESP32S, Arduino 等支持 FastLED 的微控制器
- WS2812B, WS2812, WS2815 等可定址LED

###### 軟體配置要求

- Arduino IDE
- FastLED 3.6.0

## 🤖 Technologies Used

使用 FastLED 代碼庫，用於控制LED。

## 💡 Feedback

如果您有任何反饋或問題，請隨時提出問題。
