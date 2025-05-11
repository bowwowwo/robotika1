#include <Arduino.h>
#include <Stepper.h>
#include <LiquidCrystal_I2C.h>

// A0, 5, 6, 9, 10, 11, 12, 13, a4, a5
// 13, 16, 17, 18, 14, 27, 26, 25, 22, 21

#define I2C_SDA 21
#define I2C_SCL 22

// hall sensor
int hallSensorPin = 13;
int amnt = 0;
int amnt2 = 0;

// rgb led
/*int redPin = 16;
int greenPin = 17;
int bluePin = 18;
int L = 0;*/

// stepper
Stepper stepper(4, 14, 26, 27, 25); // 10-13 //4 is stepsPerRevolution //esp - 14, 27, 26, 25

// lcd
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

// variables
int turn_on;

// functions
void rgb_light();
void spin();

void setup()
{

  //---------------------------------------------------------
  // Serial.begin(115200);

  // hall sensor
  pinMode(hallSensorPin, INPUT);

  // rgb led
  /*pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  ledcAttachPin(redPin, 0);   // channel 0
  ledcAttachPin(greenPin, 1); // channel 1
  ledcAttachPin(bluePin, 2);  // channel 2

  ledcSetup(0, 5000, 8); // 5kHz PWM, 8-bit resolution
  ledcSetup(1, 5000, 8);
  ledcSetup(2, 5000, 8);*/

  // stepper
  stepper.setSpeed(2048);

  // lcd
  lcd.init(I2C_SDA, I2C_SCL);
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("Sveicinati");

  // Serial.println("sketch1#############");
}

void loop()
{ //---------------------------------------------------------

  amnt = analogRead(hallSensorPin); // amnt ~1872
  // Serial.println(amnt);
  //   Serial.println(amnt);

  /*if (amnt > 2400)
  {
    lcd.noBacklight();
    spin();
  }
  else if (amnt < 1200)
  {
    lcd.noBacklight();
    rgb_light();
  }*/
  lcd.noBacklight();
  spin();

  delay(100);
}

// * combine rbg_light and spin()

void rgb_light()
{

  /*for (int i = 0; i < 255; i++)
  {
    L = 255 - i;
    ledcWrite(1, i); // greenpin
    ledcWrite(0, L); // redpin
    delay(10);
  }
  for (int i = 0; i < 255; i++)
  {
    L = 255 - i;
    ledcWrite(2, i); // bluepin
    ledcWrite(1, L); // greenpin
    delay(10);
  }
  for (int i = 0; i < 255; i++)
  {
    L = 255 - i;
    ledcWrite(0, i); // redpin
    ledcWrite(2, L); // bluepin
    delay(10);
  }*/
}

void spin()
{
  stepper.step(1000);

  stepper.step(-1000);
}