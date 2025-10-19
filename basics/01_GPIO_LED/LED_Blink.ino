/*
  Arduino Learning Kits by Lyan
  Lesson 01: GPIO - LED Blink
  ----------------------------------------
  控制一顆 LED 閃爍。
  Learn how to make an LED blink using digital output.
*/

int ledPin = 13;  // LED 腳位 (LED pin on UNO R3)

void setup() {
  pinMode(ledPin, OUTPUT);  // 設定腳位為輸出 (set pin as OUTPUT)
}

void loop() {
  digitalWrite(ledPin, HIGH);  // LED 亮 (turn LED on)
  delay(500);                  // 延遲 0.5 秒 (wait 0.5 sec)
  digitalWrite(ledPin, LOW);   // LED 滅 (turn LED off)
  delay(500);                  // 延遲 0.5 秒 (wait 0.5 sec)
}
