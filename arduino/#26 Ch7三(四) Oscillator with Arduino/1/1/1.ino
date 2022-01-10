int LEDpin = 5;                     //定義LED接腳
int potPin =14;                     //定義可變電阻讀取接腳
int fre=15;
int val = 0;                        //儲存可變電阻阻值
int dt  = 0;                        //LED閃爍時間間隔
int frequency = 0;
int dt2 = 0;
void setup() {
    pinMode(LEDpin, OUTPUT);        //定義LED接腳為輸出
    pinMode(potPin, INPUT);         //定義可變電阻讀取接腳為輸入
    pinMode(fre,INPUT);
    Serial.begin(9600);
}

void loop() {
    val = analogRead(potPin);
    frequency = analogRead(fre)*2;  
    dt = map(val, 0, 1023, 0, frequency); //設定val將由0~1023線性變換為0~500存入dt
    digitalWrite(LEDpin, HIGH);     //LED亮
    delay(frequency-dt);                      //由變化的dt決定亮的時間有多久
    digitalWrite(LEDpin, LOW);      //LED不亮
    delay(dt);                      //由變化的dt決定滅的時間有多久
//    Serial.print("val = ");
//    Serial.print(val);
//    Serial.print(";   dt = ");
//    Serial.println(dt);
}
