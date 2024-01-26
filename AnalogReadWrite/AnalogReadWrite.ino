/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/

int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0: range 0-1024
  int sensorValue = analogRead(A0);
  int goalBrightness = (int) (sensorValue * 255/ 1024);

  if (brightness < goalBrightness - 3) {
    brightness += fadeAmount;
  } else if (brightness > goalBrightness + 3) {
    brightness -= fadeAmount;
  }

  analogWrite(led, brightness);
  Serial.println(sensorValue);
  delay(30);
}
