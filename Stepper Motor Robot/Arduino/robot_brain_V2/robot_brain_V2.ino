#include <Stepper.h>
#include <IRremote.h>

const int stepsPerRevolution = 2048;
const int steps = 1; //steps per cycle
float x_pos = 0;
float y_pos = 0;
float mult = 1;
const int inch = 276; //steps per inch
const int deg = 1000; //steps per *10* degrees (not right)
const int spd = 20;
const int RECV_PIN = 2;

const int sAddress = 0x69;
const int UP = 0x00;
const int DOWN = 0x01;
const int LEFT = 0x02;
const int RIGHT = 0x03;


Stepper FL(stepsPerRevolution, 11, 13, 12, A4);
Stepper FR(stepsPerRevolution, 7, 9, 8, 10);
Stepper BL(stepsPerRevolution, A0, A2, A1, A3);
Stepper BR(stepsPerRevolution, 3, 5, 4, 6);

void setup() {
  // put your setup code here, to run once:
  FL.setSpeed(spd);
  FR.setSpeed(spd);
  BL.setSpeed(spd);
  BR.setSpeed(spd);


  IrReceiver.begin(RECV_PIN, DISABLE_LED_FEEDBACK);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()){
    if (IrReceiver.decodedIRData.address == 0x69){
      if (IrReceiver.decodedIRData.command == UP){
        fwd();
      }
      if (IrReceiver.decodedIRData.command == LEFT){
        left();
      }
      if (IrReceiver.decodedIRData.command == RIGHT){
        right();
      }
      if (IrReceiver.decodedIRData.command == DOWN){
        back();
      }
    }
    IrReceiver.resume();
  }
}

void fwd(){
  for (int i = 0; i <= inch*mult; i++){
    BL.step(-steps);
    FL.step(-steps);
    FR.step(steps);
    BR.step(steps);
  }
  stop_mot();
  y_pos = y_pos + mult;
  }
  
void back(){
  for (int i = 0; i <= inch*mult; i++){
    FL.step(steps);
    FR.step(-steps);
    BL.step(steps);
    BR.step(-steps);
  }
  stop_mot();
  y_pos = y_pos - mult;
  }
  
void right(){
  for (int i = 0; i <= inch*mult; i++){
    FL.step(-steps);
    FR.step(-steps);
    BL.step(steps);
    BR.step(steps);
  }
  stop_mot();
  x_pos = x_pos + mult;
  }
  
void left(){
  for (int i = 0; i <= inch*mult; i++){
    FL.step(steps);
    FR.step(steps);
    BL.step(-steps);
    BR.step(-steps);
  }
  stop_mot();
  x_pos = x_pos - mult;
  }

  void go_to(float x, float y){
  float temp = mult;
  if (y_pos < y){
    mult = y-y_pos;
    fwd();
  }
  if (y_pos > y){
    mult = y_pos-y;
    back();
  }
  if (x_pos > x){
    mult = x_pos-x;
    left();
  }
  if (x_pos < x){
    mult = x-x_pos;
    right();
  }
  mult = temp;
}

void go_home(){
  go_to(0,0);
}

void stop_mot(){
  digitalWrite(11, LOW);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);
  digitalWrite(A0, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
}
