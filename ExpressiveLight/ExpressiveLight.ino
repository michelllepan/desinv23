
// LED pins
const int redLED = 11;  
const int greenLED = 10;  
const int blueLED = 9;  

const int redButtonPin = 4;
const int greenButtonPin = 3;
const int blueButtonPin = 2;

int redFadeAmount = 1;    
int greenFadeAmount = 5;    
int blueFadeAmount = 3;  

int red = 0;
int green = 0; 
int blue = 0;

int delaytime = 30;  // a variable for all delay times
                      // now we can change them all just by changing this one number!

void setup(){
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop(){
    int sensorValue = analogRead(A0);
    int redButtonState = digitalRead(redButtonPin);
    int greenButtonState = digitalRead(greenButtonPin);
    int blueButtonState = digitalRead(blueButtonPin);

    if (sensorValue < 100) {
        fade();
    } else {
        adjustColor();
    }

    analogWrite(redLED, red);
    analogWrite(greenLED, green);
    analogWrite(blueLED, blue);

    delay(delaytime);
}

void fade(){
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

void adjustColor() {
    int redButtonState = digitalRead(redButtonPin);
    int greenButtonState = digitalRead(greenButtonPin);
    int blueButtonState = digitalRead(blueButtonPin);

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
