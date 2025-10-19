/*
  Arduino Learning Kits by Lyan
  Lesson 02: Button Input & Debounce
  ----------------------------------------
  課程主題：按鈕輸入與防彈跳
  Learn how to read a button input and avoid false triggers
  caused by mechanical bounce.
*/

int buttonPin = 2;          // 按鈕腳位 (button input pin)
int ledPin = 13;            // LED 腳位 (output pin)

// 狀態記錄變數 (state tracking)
int buttonState = HIGH;       // 目前按鈕狀態 (default HIGH due to INPUT_PULLUP)
int lastButtonState = HIGH;   // 上一次按鈕狀態
bool ledState = false;        // LED 狀態 (true = ON, false = OFF)

// 防彈跳控制 (debounce control)
unsigned long lastDebounceTime = 0;  // 上次狀態變化時間
unsigned long debounceDelay = 50;    // 防彈跳延遲時間 (50 ms)

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // 啟用內建上拉電阻 (use internal pull-up resistor)
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // 讀取當前按鈕狀態 (read current button state)
  int reading = digitalRead(buttonPin);

  // 若狀態改變，重設防彈跳計時 (reset debounce timer on state change)
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  // 若狀態穩定超過防彈跳時間，確認輸入有效 (check stable state)
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      // 按下（因上拉邏輯為 LOW）時切換 LED 狀態
      if (buttonState == LOW) {
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
      }
    }
  }

  // 更新狀態記錄 (update last state)
  lastButtonState = reading;
}
