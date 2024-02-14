
// LED pins
const int redLED = 11;
const int greenLED = 10;
const int blueLED = 9;

// button pins
const int redButtonPin = 4;
const int greenButtonPin = 3;
const int blueButtonPin = 2;

// threshold where LDR is considered "covered"
const int ldrThreshold = 100;

// amount to fade each color when in fade mode
int redFadeAmount = 1;
int greenFadeAmount = 5;
int blueFadeAmount = 3;

// variables for RGB color values
int red = 0;
int green = 0;
int blue = 0;

int delaytime = 30;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  int redButtonState = digitalRead(redButtonPin);
  int greenButtonState = digitalRead(greenButtonPin);
  int blueButtonState = digitalRead(blueButtonPin);

  // if LDR is covered, fade LED; else adjust based on buttons
  if (sensorValue < ldrThreshold) {
    fade();
  } else {
    adjustColor();
  }

  analogWrite(redLED, red);
  analogWrite(greenLED, green);
  analogWrite(blueLED, blue);

  delay(delaytime);
}

// fade mode
void fade() {

  // fade colors by their fade amount between 0 and 200
  
  red += redFadeAmount;
  if (red < 1 || red > 199) {
    redFadeAmount = -redFadeAmount;
  }

  green += greenFadeAmount;
  if (green < 5 || green > 195) {
    greenFadeAmount = -greenFadeAmount;
  }

  blue += blueFadeAmount;
  if (blue < 3 || blue > 197) {
    blueFadeAmount = -blueFadeAmount;
  }

  delay(delaytime);
}

// manual adjustment from buttons
void adjustColor() {
  int redButtonState = digitalRead(redButtonPin);
  int greenButtonState = digitalRead(greenButtonPin);
  int blueButtonState = digitalRead(blueButtonPin);

  // if the button for a color is pressed down, increment the
  // color value and loop back to 0 if it exceeds 200

  if (redButtonState == HIGH) {
    red = (red + 2) % 200;
  }

  if (greenButtonState == HIGH) {
    green = (green + 2) % 200;
  }

  if (blueButtonState == HIGH) {
    blue = (blue + 2) % 200;
  }
}
