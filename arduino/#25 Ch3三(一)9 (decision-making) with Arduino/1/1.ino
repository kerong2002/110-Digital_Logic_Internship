const int agree = 13;                  //同意LED，設定輸出腳為D13
const int disagree = 12;               //不同意LED，設定輸出腳為D12
const int redecide = 11;               //重新制定LED，設定輸出腳為D11

#define boss 14                        //老闆，設定輸入腳為A0 D14
#define manger1 15                     //主管1，設定輸入腳為A1 D15
#define manger2 16                     //主管2，設定輸入腳為A2 D16
#define manger3 17                     //主管3，設定輸入腳為A3 D17

int x=0;                               //設變數X為整數，且出值為0
int y=0;                               //設變數y為整數，且出值為0
int z=0;                               //設變數z為整數，且出值為0
int B=0;                               //設變數B為整數，且出值為0


void setup() {
  pinMode(boss,INPUT);                 //設定老闆為DIPSW輸入
  pinMode(manger1,INPUT);              //設定主管1為DIPSW輸入
  pinMode(manger2,INPUT);              //設定主管2為DIPSW輸入
  pinMode(manger3,INPUT);              //設定主管3為DIPSW輸入
  pinMode(agree, OUTPUT);              //設定同意為輸出
  pinMode(disagree, OUTPUT);           //設定不同意為輸出
  pinMode(redecide, OUTPUT);           //設定重新決定為輸出

}
 
void loop() {
  x=digitalRead(manger1);              //變數給主管1，以方便做bitwise operator
  y=digitalRead(manger2);              //變數給主管2，以方便做bitwise operator
  z=digitalRead(manger3);              //變數給主管3，以方便做bitwise operator
  B=digitalRead(boss);                 //變數給老闆，以方便做bitwise operator
  if(B==1 && x|y|z==1){                //假如老闆同意，且超過一名(含)主管以上同意
    digitalWrite(agree, HIGH);         //政策執行
  }
  else if(B==0 && x&y&z==1){           //另外假如老闆不同意，但三位主管皆同意，則無視老闆是否同意
    digitalWrite(agree, HIGH);         //政策執行
  }
  else{
    digitalWrite(agree, LOW);          //清除
  }
  if(B+x+y+z==1 || B+x+y+z==0){        //假如老闆與三位主管中只有一人同意，或者沒人同意
    digitalWrite(disagree, HIGH);      //政策不執行
  }
  else{
    digitalWrite(disagree, LOW);       //清除
  }
  if(x+y+z==2 && B==0){                //其餘狀況
    digitalWrite(redecide, HIGH);      //重新制定政策
  }
  else{
    digitalWrite(redecide, LOW);       //清除
  }
}
