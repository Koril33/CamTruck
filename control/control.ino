#define STOP 0
#define FORWARD 1
#define BACKWARD 2
#define TURNRIGHT 3
#define TURNLEFT 4
#define TURNRIGHTLITTLE 5
#define TURNLEFTLITTLE 6

//L298N电机驱动引脚
const int input1 = 4;
const int input2 = 6;
const int input3 = 10;
const int input4 = 11;
const int pwm1 = 3;                                           
const int pwm2 = 9;   

int msg = 0;
void setup() 
{
    Serial.begin(9600);   //定义波特率

    pinMode(input1, OUTPUT);
    pinMode(input2, OUTPUT);
    pinMode(input3, OUTPUT);
    pinMode(input4, OUTPUT);
    pinMode(pwm1, OUTPUT);
    pinMode(pwm2, OUTPUT);
}

void goStop() {
    analogWrite(pwm1, 0);
    analogWrite(pwm2, 0);

    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    digitalWrite(input3, LOW);
    digitalWrite(input4, LOW);
}

void goForward(int _pwm1, int _pwm2) {
    analogWrite(pwm1, _pwm1);
    analogWrite(pwm2, _pwm2);

    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
    digitalWrite(input3, LOW);
    digitalWrite(input4, HIGH);
}

void goRight(int _pwm1, int _pwm2) {
    analogWrite(pwm1, _pwm1);
    analogWrite(pwm2, _pwm2);

    digitalWrite(input1, HIGH);
    digitalWrite(input2, LOW);
    digitalWrite(input3, LOW);
    digitalWrite(input4, HIGH);
}

void goLeft(int _pwm1, int _pwm2) {
    analogWrite(pwm1, _pwm1);
    analogWrite(pwm2, _pwm2);

    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
    digitalWrite(input3, HIGH);
    digitalWrite(input4, LOW);
}

//电机函数
void motorRun(int _Cmd) {
  switch(_Cmd) {
    case STOP:
      goStop();
      break;
    
    case TURNRIGHT:
      goRight(120, 120);
      break;
    
    case TURNRIGHTLITTLE:
      goRight(80, 0);
      break;

    case TURNLEFT:
      goLeft(120, 120);
      break;

    case TURNLEFTLITTLE:
      goLeft(0, 80);
      break;
    
      
    case FORWARD:
      goForward(120, 120);
      break;
  }
}

void loop()
{
  /*
    for (byte n = 0; n < 255; n++) {
        Serial.write(n);   //向串口写入n
        delay(50);     //延时0.05s
    }
   */
  if(Serial.available() > 0) {
    msg = Serial.read();
    if(msg == 'f'){
      Serial.println("FORWARD");
      motorRun(FORWARD);
      delay(1000);
    }
    else if(msg == 's') {
      Serial.println("STOP");
      motorRun(STOP);
      delay(1000);
    }
    else if(msg == 'l') {
      Serial.println("TURNLEFT");
      motorRun(TURNLEFT);
      delay(1000);
    }
    else if(msg == 'r') {
      Serial.println("TURNRIGHT");
      motorRun(TURNRIGHT);
      delay(1000);
    }
  }  
}
