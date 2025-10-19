# Lesson 02：按鈕輸入與防彈跳  
*(Button Input & Debounce Tutorial)*

## 一、開場：讓機器回應你的動作
當 LED 會閃爍後，下一步就是讓它「回應你」。  
這一課我們要學的，是最簡單也最關鍵的人機互動方式──按鈕輸入。  
透過一個按鍵，你可以讓系統聽見你的指令。

## 二、教學目標 (Learning Objectives)
- 理解 Digital Input 的原理與腳位設定  
- 學會使用 `digitalRead()` 讀取按鈕狀態  
- 認識「防彈跳 (Debounce)」的重要性與實作方法  

## 三、所需材料 (Materials)
| 名稱 | 數量 | 備註 |
|------|------|------|
| Arduino UNO R3 | 1 | 控制板 |
| 按鈕開關 | 1 | 常見 4 腳按鈕 |
| LED | 1 | 任意顏色 |
| 電阻 220Ω | 1 | 保護 LED |
| 杜邦線 | 若干 | 連接用 |

## 四、接線方式 (Circuit Diagram)
LED 控制腳位 D13；按鈕輸入腳位 D2。  
使用內建上拉電阻 (INPUT_PULLUP) 省去外接電阻。  

5V → LED 長腳 → 220Ω → D13
GND → LED 短腳
按鈕一腳 → D2
按鈕另一腳 → GND

## 五、程式碼 (Code)

/*
  Arduino Learning Kits by Lyan
  Lesson 02: Button Input & Debounce
  ----------------------------------------
  Read button input and toggle LED state with debounce.
*/

int buttonPin = 2;    // 按鈕腳位 (button input pin)
int ledPin = 13;      // LED 腳位 (output pin)
int buttonState = HIGH;       // 初始狀態為未按下 (default: HIGH due to INPUT_PULLUP)
int lastButtonState = HIGH;   // 前一次狀態
unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;  // 防彈跳時間 (50 ms)
bool ledState = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // 啟用內建上拉電阻 (enable internal pull-up)
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();  // 狀態變化時記錄時間
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {   // 按下（因為上拉為反向邏輯）
        ledState = !ledState;     // 切換 LED 狀態
        digitalWrite(ledPin, ledState);
      }
    }
  }
  lastButtonState = reading;
}


## 六、實驗步驟與觀察 (Experiment & Observation)

上傳程式後，按下按鈕一次，LED 狀態改變。

再按一次，LED 恢復原狀。

嘗試移除防彈跳程式段落，觀察 LED 是否出現「抖動」現象（按一次亮滅多次）。

這樣的抖動是因為按鈕在機械彈跳期間產生數次高低變化，
若不處理，系統會誤判成多次觸發。

## 七、延伸挑戰 (Challenges)

使用兩顆按鈕：一顆負責「亮」、一顆負責「滅」。

結合 millis() 建立「長按觸發」功能。

使用外部下拉電阻而非 INPUT_PULLUP，觀察邏輯差異。

## 八、原理說明 (Concept Behind)

按鈕是最基礎的輸入元件，但由於機械結構在接觸瞬間會彈跳，
產生 5~20 毫秒的不穩定訊號，導致誤觸。
透過軟體判斷「狀態穩定一段時間再採用」，
即可實現防彈跳，確保輸入精準。

## 九、作者的話 (From Lyan)

當你能讓一個按鈕可靠地觸發事件，
你就學會了讓機器「傾聽」。
這是互動設計的起點，也是創造真正智慧裝置的關鍵。

「創造不只是讓機器動，而是讓它回應你的想法。」
