int LEDpin = 5;                     //定義LED接腳
int potPin1 = 14;                     //定義可變電阻讀取接腳
int potPin2 = 15;                     //定義可變電阻讀取接腳
int val1 = 0;                        //儲存可變電阻阻值
int val2 = 0;                        //儲存可變電阻阻值
int dt  = 0;                        //LED閃爍時間間隔
int frequency = 0;
void setup() {
    pinMode(LEDpin, OUTPUT);        //定義LED接腳為輸出
    pinMode(potPin1, INPUT);         //定義可變電阻讀取接腳為輸入
    pinMode(potPin2, INPUT);
    Serial.begin(9600);
}

void loop() {
    val1 = analogRead(potPin1);
    val2 = analogRead(potPin2);
    frequency=(1/(0.7*(10000+2*val2)*0.00001)); //T會因為可變電阻而改變，所以要計算總共要顯示幾秒，頻率等於週期倒數
    dt = map(val1, 0, 1023, 0, frequency);      //設定val將由0~1023線性變換為0~整個要顯示幾秒存入dt
    digitalWrite(LEDpin, HIGH);                //LED亮
    delay(dt);                                 //由變化的dt決定亮的時間有多久
    digitalWrite(LEDpin, LOW);                 //LED不亮
    delay(frequency-dt);                       //由變化的頻率-dt決定滅的時間有多久
//    Serial.print("val = ");
//    Serial.print(val);
//    Serial.print(";   dt = ");
//    Serial.println(dt);
}
