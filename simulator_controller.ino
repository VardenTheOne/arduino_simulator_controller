#include <Joystick.h>


#define pitch_pin A1
#define roll_pin A0
#define yaw_pin A3
#define throttle_pin A2

// Create the Joystick
//Joystick_ Joystick(
//  JOYSTICK_DEFAULT_REPORT_ID,
//  JOYSTICK_TYPE_GAMEPAD,
//  0, // buttons
//  0, // hat switch
//  true, // XAxis
//  true, // YAxis
//  false, // ZAxis
//  false, // RxAxis
//  false, // RyAxis
//  false, // RzAxis
//  true, // Rudder
//  true, // Throttle
//  false, // Accelerator
//  false, // Brake
//  false // Steering
//  );


Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_MULTI_AXIS, 32, 0, true, true, true, false, false, false, true, false, false, false, false);
//                ( HID report ID             Joystick Type,           btn hat  X     Y     Z      Rx     Ry     Rz   Rudd   Thro  Acc   Break  Steer)

const bool initAutoSendState = true;

int pitch = 0;
int roll = 0;
int yaw = 0;
int throttle = 0;

int pitchMIN = 842;
int pitchMAX = 96;
int rollMIN = 840;
int rollMAX = 100;
int yawMIN = 870;
int yawMAX = 131;
int throttleMIN = 109;
int throttleMAX = 825;

// Constant that maps the physical pin to the joystick button.
const int pinToButtonMap = 9;

void setup() {
  Serial.begin(9600);
  // Initialize Button Pins
//  pinMode(pinToButtonMap, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();

  Joystick.setXAxisRange(pitchMIN, pitchMAX);
  Joystick.setYAxisRange(rollMIN, rollMAX);
  Joystick.setRudderRange(yawMIN, yawMAX);
  Joystick.setZAxisRange(throttleMIN, throttleMAX);
}

// Last state of the button
int lastButtonState = 0;

void loop() {

  
  pitch = analogRead(pitch_pin);
  Joystick.setXAxis(pitch);

  roll = analogRead(roll_pin);
  Joystick.setYAxis(roll);

  yaw = analogRead(yaw_pin);
  Joystick.setRudder(yaw);

  throttle = analogRead(throttle_pin);
  Joystick.setZAxis(throttle);
  
  Serial.print(pitch);
  Serial.print(" ");
  Serial.print(roll);
  Serial.print(" ");
  Serial.print(yaw);
  Serial.print(" ");
  Serial.println(throttle);

  // Read pin values
//  int currentButtonState = !digitalRead(pinToButtonMap);
//  if (currentButtonState != lastButtonState)
//  {
//  Joystick.setButton(0, currentButtonState);
//  lastButtonState = currentButtonState;
//  }

  delay(50);
}
