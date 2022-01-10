#define RESOLUTION 256//解析度設成256，代表一個週期畫多少點

void setup()
{
int pin;
pinMode(2,INPUT);         //設為int改變正弦跟三角
for(pin=3;pin<11;pin++)   //設定輸出 
  pinMode(pin,OUTPUT);
pinMode(A0,INPUT);        //調整頻率
pinMode(A1,INPUT);        //調整傾斜度
}

void loop()
{
int T,i,out,pin;
float D;
T=analogRead(A0);         //A0的值讀進來
D=analogRead(A1)/1024.0;  //A1的值讀進來--浮點數
for(i=0;i<RESOLUTION;i++) //總共畫256個點
  {
  if(digitalRead(2)==HIGH)                      //if 2==HIGH畫正弦波
    out=cos(i*6.283184/RESOLUTION)*127.5+127.5; //0到255→一整個週期(0~2π)值會介於-1~+1之間，要做修正所以乘上127.5
  else 
    if(i<RESOLUTION/2)                          //if 2==LOW 畫三角波
      out=i*256/(RESOLUTION/2);                 //畫三角波前半段的線
    else
      out=(RESOLUTION-1-i)*256/(RESOLUTION/2);  //畫後半段三角波的線
  for(pin=3;pin<11;pin++)
    {
    digitalWrite(pin,out%2);
    out/=2;
    }
  if(i<RESOLUTION/2)
    delayMicroseconds(T*D);                     //畫的前半段停留多久
  else
    delayMicroseconds(T*(1.0-D));               //畫的後半段停留多久
  }
}
