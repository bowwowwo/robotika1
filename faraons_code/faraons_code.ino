#include <Arduino.h>
#include <Stepper.h>


//hall sensor
int hallSensorPin = A0;
int amnt = 0;
int amnt2 = 0;


//rgb led
int redPin= 5;
int greenPin = 6;
int  bluePin = 9;
int L = 0;

// stepper
Stepper stepper(4, 10, 12, 11, 13); //10-13
const int stepsPerRevolution = 512;

//lcd


//variables
int turn_on;

//functions
void rgb_light();
void spin();


void setup() { //---------------------------------------------------------
  Serial.begin(115200);

  //hall sensor
  pinMode(hallSensorPin, INPUT);

  //rgb led
  pinMode(redPin,  OUTPUT);              
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  //stepper
  stepper.setSpeed(2048);

  //lcd

}

void loop() {  //---------------------------------------------------------

  amnt = analogRead(hallSensorPin);
    Serial.println(amnt);
  if(amnt > 800){
    spin();
    rgb_light();
  }

  delay(100);
}

// * combine rbg_light and spin()

void rgb_light(){
  for(int i = 0; i < 255; i++){
      L = 255-i;
      analogWrite(greenPin, i);
      analogWrite(redPin, L);
      delay(10);
    }
    for(int i = 0; i < 255; i++){
      L = 255-i;
      analogWrite(bluePin, i);
      analogWrite(greenPin, L);
      delay(10);
    }
    for(int i = 0; i < 255; i++){
      L = 255-i;
      analogWrite(redPin, i);
      analogWrite(bluePin, L);
      delay(10);
    }
}

void spin(){
  Serial.println("clockwise");
  stepper.step(1000);

  Serial.println(SREG_S);
  stepper.step(-1000);

}