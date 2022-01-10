int pinA = 7;
int pinB = 6;
int out = 14;
int _7408count = 0;
int _7400count = 0;
int x = 0;
int Logic_gate[2][4] = {{1, 1, 1, 0}, {0, 0, 0, 1}}; //7400,7408
int Read_gate [4];
void setup()
{
  Serial.begin(9600);
  pinMode(out, INPUT);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
}

void loop()
{
  while (x < 4) {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    delay(250);   
      Read_gate[x] = digitalRead(out);
      if (Read_gate[x] == Logic_gate[1][x]) {
        _7408count++;
      }
      if (Read_gate[x] == Logic_gate[0][x]) {
        _7400count++;
      }
      x = x + 1;

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    delay(250);
      Read_gate[x] = digitalRead(out);
      if (Read_gate[x] == Logic_gate[1][x]) {
        _7408count++;
      }
      if (Read_gate[x] == Logic_gate[0][x]) {
        _7400count++;
      }
      x = x + 1;

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    delay(250);
      Read_gate[x] = digitalRead(out);
      if (Read_gate[x] == Logic_gate[1][x]) {
        _7408count++;
      }
      if (Read_gate[x] == Logic_gate[0][x]) {
        _7400count++;
      }
      x = x + 1;

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    delay(250);
      Read_gate[x] = digitalRead(out);
      if (Read_gate[x] == Logic_gate[1][x]) {
        _7408count++;
      } 
      if (Read_gate[x] == Logic_gate[0][x]) {
        _7400count++;
      }
      x = x + 1;
      
    if (_7408count == 4) {
      Serial.print("\n7408 IC is good.\n");
      break;
    }
    if (_7400count == 4) {
      Serial.print("\n7400 IC is good.\n");
      break;
    }
     if (_7400count != 4 and _7408count != 4) {
      Serial.print("\nNothing connect or IC is not AND or NAND.\n");
      break;
    }
  }

}
