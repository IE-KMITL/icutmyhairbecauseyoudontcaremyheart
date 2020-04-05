#include <HCSR04.h>
HCSR04 hc(10,9);//initialisation class HCSR04 (trig pin , echo pin)
const int motorPin1  = 5;
const int motorPin2  = 6;
const int motorPin3  = 7;
const int motorPin4  = 8;
const int sensor_left=2;
const int sensor_rigth=3;
const int sensor_back=11;
const int sensor_color=A5;
int count=1,yello=0,black=0,No_color=0,red=0;
int detect=1,non_detect=0;
int color;
int getColor() {          
  if ((NO_color>=2200)&&(NO_color<=2500))       //สีแดง
    return red;
  else if ((NO_color>=1900)&&(NO_color<=2200))  //สีเหลือง
    return yellow;
  else if ((NO_color>=3600)&&(NO_color<=3900))  //สีดำ
    return black;
  else                                        //ไม่พบสี
    return NO_color;

void setup() {
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(sensor_left, INPUT);
    pinMode(sensor_rigth, INPUT);
    pinMode(sensor_back, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor_value_A = digitalRead(sensor_A);
  sensor_value_B = digitalRead(sensor_B);
  color = analogRead(sensor_color);
  //รุก
  move_forward();
  if(color == yellow){
    yellow++;
    delay(300);  
  }
  if(color == black){
    black++;
    delay(300);  
  }
  if(color == red){
    move_forward();
    delay(1000);
    move_return();
    move_forward();
    delay(1000);  
  }
  if(color == red)
  if(yello==1&&(black==0||black==2||black==4)){
    move_forward();
  }
  if(yello==2){
    while(1)
          move_stop();
  }
  
  if(yello==1&&black==2){
    move_forward();
  }
  if(black==1&&black==3){
    if(hc.dist()>=10||(sensor_left==10)||(sensor_rigth==10)){ 
        move_stop();
        delay(2000);
        move_backward();
        delay(1000);
      }
     else{ 
        move_forward();
        delay(1000);
     }
    
  }
  //รับ
  if(hc.dist()>=10){
      move_forward();
      delay(1000);
  }
  else if(sensor_rigth==detect){
      move_right();
      move_forward();
      delay(1000);
  }
  else if(sensor_left==detect){
      move_left();
      move_forward();
      delay(1000);
  }
  else if(sensor_back==detect){
    move_backward()
  }
  if(color == black){
    move_return();
    move_forward();
    deley(500);
  }
  else{
    move_stop();
  }
    

}
void move_forward(){
    analogWrite(motorPin1, 255);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 255);
    analogWrite(motorPin4, 0);
}
void move_backward(){
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 255);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 255);
}
void move_left(){
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 255);
    analogWrite(motorPin3, 255);
    analogWrite(motorPin4, 0);
    delay(1000);//จับเวลาในการหมุนด้วย
}
void move_right(){
    analogWrite(motorPin1, 255);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 255);
    delay(1000);//จับเวลาในการหมุนด้วย
}
void move_return(){
    analogWrite(motorPin1, 255);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 255);
    delay(2000);//จับเวลาในการหมุนด้วย
    
}
void move_stop(){
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
}
