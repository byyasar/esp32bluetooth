/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Arduino.h>
#include <DabbleESP32.h>
#include <ESP32_Servo.h>

#define JAWSPIN 13
#define LEANPIN 14
#define ELEVPIN 12
#define ROTPIN 27

Servo ROT_servo;
Servo LEAN_servo;
Servo ELEV_servo;
Servo JAWS_servo;

int ROT_angle;
int LEAN_angle;
int ELEV_angle;
int JAWS_angle;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);    // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("MyEsp32"); // set bluetooth name of your device

  ROT_angle = 90;
  LEAN_angle = 90;
  ELEV_angle = 90;
  JAWS_angle = 90;

  ROT_servo.attach(ROTPIN, 1000, 2400);
  LEAN_servo.attach(LEANPIN, 1000, 2400);
  ELEV_servo.attach(ELEVPIN, 1000, 2400);
  JAWS_servo.attach(JAWSPIN, 500, 2400);
}

void loop()
{
  Dabble.processInput(); // this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.print("KeyPressed: ");
  if (GamePad.isUpPressed())
  {
    Serial.print("Up");
    if (ELEV_angle < 255)
      ELEV_angle += 10;
  }

  if (GamePad.isDownPressed())
  {
    Serial.print("Down");
    if (ELEV_angle > 0)
      ELEV_angle -= 10;
  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("Left");
    if (ROT_angle > 0)
      ROT_angle -= 10;
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("Right");
    if (ROT_angle < 255)
      ROT_angle += 10;
  }

  if (GamePad.isSquarePressed())
  {
    Serial.print("Square");
    if (JAWS_angle > 0)
      JAWS_angle -= 10;
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
    if (JAWS_angle < 255)
      JAWS_angle += 10;
  }

  if (GamePad.isCrossPressed())
  {
    Serial.print("Cross");
    if (LEAN_angle > 0)
      LEAN_angle -= 10;
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.print("Triangle");
    if (LEAN_angle < 255)
      LEAN_angle += 10;
  }

  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
  }
  Serial.print('\t');

  ROT_servo.write(ROT_angle);
  LEAN_servo.write(LEAN_angle);
  ELEV_servo.write(ELEV_angle);
  JAWS_servo.write(JAWS_angle);
  /*int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
 */
  Serial.println();
  delay(100);
}
