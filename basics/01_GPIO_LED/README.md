# Lesson 01：GPIO 輸出入教學（LED 閃爍）
*(GPIO Tutorial: Control LED Blink)*

---

## 一、開場：讓世界亮起來

當你第一次讓一顆 LED 閃爍時，  
你會體會到「電腦不只是螢幕上的程式，它也能控制真實世界」。  

這是每位創客的起點。  
從這顆燈開始，你將學會輸出控制、時間邏輯，  
也開啟了電子創作的第一步。

---

## 二、教學目標

- 理解 **數位輸出（Digital Output）** 的概念  
- 學會使用 `pinMode()` 與 `digitalWrite()`  
- 瞭解程式如何與硬體腳位互動  

---

## 三、所需材料

| 名稱 | 數量 | 備註 |
|------|------|------|
| Arduino UNO R3 | 1 | 主要控制板 |
| LED 燈 | 1 | 任意顏色皆可 |
| 電阻 220Ω | 1 | 保護 LED |
| 杜邦線 | 若干 | 連接用 |

---

## 四、接線方式

(5V) -----> [LED長腳] → [220Ω 電阻] → D13 腳位
(GND) ----> [LED短腳]

---

## 五、程式碼 (Code)

/*
  Arduino Learning Kits by Lyan
  Lesson 01: GPIO – LED Blink
  ----------------------------------------
  Make an LED blink using digital output.
*/

int ledPin = 13;  // LED pin on UNO R3 (onboard LED is D13)

void setup() {
  pinMode(ledPin, OUTPUT);  // set pin as OUTPUT
}

void loop() {
  digitalWrite(ledPin, HIGH); // turn LED on
  delay(500);               // wait 0.5 second
  digitalWrite(ledPin, LOW);  // turn LED off
  delay(500);               // wait 0.5 second
}

---

## 六、實驗步驟與觀察 (Experiment & Observation)

上傳程式後觀察 LED 以 0.5 秒節奏閃爍。
將 delay(500) 改為 delay(100)，觀察閃爍變快。
將 digitalWrite(ledPin, HIGH) 放進 setup()， LED 會常亮。

---

## 七、延伸挑戰 (Challenges)

用 D9、D10、D11 三顆 LED 寫出跑馬燈。
用 millis() 取代 delay() 讓程式非阻塞運行。
改用蜂鳴器或繼電器，嘗試輸出控制的多種應用。

---

## 八、原理說明 (Concept Behind)

digitalWrite(HIGH) 讓 ATmega328P 在該腳位輸出約 5 V，
電流流經 LED 與電阻至 GND 產生亮光。
這就是數位輸出的本質：在正確的時機給出電位訊號。

---

## 九、作者的話 (From Lyan)

當你讓第一顆燈亮起，你不只是完成一個任務，
而是開始理解「電」與「邏輯」的語言。
從這裡出發，你已經踏上創造的旅程。

「學習 Arduino，不是學會接線，而是學會創造。」
