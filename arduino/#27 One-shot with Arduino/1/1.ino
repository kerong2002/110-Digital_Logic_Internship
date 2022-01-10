int LEDpin = 5;                     //定義LED接腳
int potPin = 0;                     //定義可變電阻讀取接腳
int val = 0;                        //儲存可變電阻阻值
int dt  = 0;                        //LED閃爍時間間隔
int button1 =0;
int digital =0;


void setup() {
    pinMode(LEDpin, OUTPUT);        //定義LED接腳為輸出
    pinMode(potPin, INPUT);         //定義可變電阻讀取接腳為輸入
    pinMode(7, INPUT);
    Serial.begin(9600);
}

void loop() {
    int previousState;
    int state;
    int swState;                // 穩定後的按鈕狀態
    previousState = digitalRead(7); // 讀取第一次按鈕狀態
    delay(5);                      // 隔 10 毫秒後再讀取第二次狀態
    state = digitalRead(7);
    if(state == previousState)      //如果兩次狀態相同，判定按鈕狀態穩定
    {
      swState = state;              // 判定按鈕狀態
    }
    val = analogRead(potPin);  
    dt = map(val, 0, 1023, 0, 3000); //設定val將由0~1023線性變換為0~500存入dt
    button1 = digitalRead(7);
    while(previousState == LOW and state ==HIGH){
      digitalWrite(LEDpin, HIGH);     //LED亮
      delay(dt);                      //由變化的dt決定亮的時間有多久
      digitalWrite(LEDpin, LOW);      //LED不亮
      delay(dt);
      break;
    }
}
