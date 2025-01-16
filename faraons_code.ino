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
Stepper stepper(STEPS, 10, 11, 12, 13);
int previous = 0;

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
  stepper.setSpeed(30);

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
  myStepper.step(stepsPerRevolution);
  delay(500);

  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500)
}
