// Simple example application that shows how to read four Arduino
// digital pins and map them to the USB Joystick library.
//
// The digital pins 9, 10, 11, and 12 are grounded when they are pressed.
//
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//
// by Matthew Heironimus
// 2015-11-20
//--------------------------------------------------------------------

#include <Joystick.h>

void setup() {
  // Initialize Button Pins
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);

    /*pinMode(14, OUTPUT);
    pinMode(15, OUTPUT);
    pinMode(16, OUTPUT);
    pinMode(17, OUTPUT);
    pinMode(18, OUTPUT);
    pinMode(19, OUTPUT);*/

    

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);


String lit = "1";

  // Initialize Joystick Library
  Joystick.begin();
}

// Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap = 3;

// Last state of the button
int lastButtonState[11] = {0,0,0,0,0,0,0,0,0,0,0};

int dblPosBtn = 13;
int leftoverPin = 14;

void loop() {


   /* digitalWrite(A2,HIGH);
    digitalWrite(A3,HIGH);
    digitalWrite(A4,HIGH);
    digitalWrite(A5,HIGH);
*/
  // Read pin values
  for (int index = 0; index < 11; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index] && index!=dblPosBtn)
    {
      if(currentButtonState){
        if(index==1){
          digitalWrite(A1, HIGH);  
          digitalWrite(A0, LOW);
          digitalWrite(A2, LOW);
          digitalWrite(A3, LOW);
        }else if(index==0){
          digitalWrite(A0, HIGH);
          digitalWrite(A1, LOW);
          digitalWrite(A2, LOW);
          digitalWrite(A3, LOW); 
        }else if(index==2){
          digitalWrite(A2, HIGH);
          digitalWrite(A1, LOW);
          digitalWrite(A0, LOW);
          digitalWrite(A3, LOW); 
        }else if(index==3){
          digitalWrite(A3, HIGH);
          digitalWrite(A1, LOW);
          digitalWrite(A2, LOW);
          digitalWrite(A0, LOW); 
        }else if(/*index==4&&*/index==6){
          digitalWrite(A5, HIGH);
        }else if(index==8){
          digitalWrite(A4, HIGH);
        }
        else if(index!=6){
          digitalWrite(A5, LOW);
        }
        else if(index!=8){
          digitalWrite(A4, LOW);
        }
      }else{
        digitalWrite(A4, LOW);
      digitalWrite(A5, LOW);
        }
        
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }


/*
if(digitalRead(dblPosBtn)==HIGH){
    Joystick.setButton(dblPosBtn, 1);
    Joystick.setButton(leftoverPin, 0);
}else{
    Joystick.setButton(leftoverPin, 1);   
    Joystick.setButton(dblPosBtn, 0);
}*/

  delay(50);
}

