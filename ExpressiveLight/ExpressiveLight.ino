
// LED pins
const int redLED = 9;  
const int greenLED = 10;  
const int blueLED = 11;  

const int redButtonPin = 4;
const int greenButtonPin = 3;
const int blueButtonPin = 2;

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

// note: full brightness is REALLY bright, so we often start at 50% and increase from there if necessary 

void loop(){
    int redButtonState = digitalRead(redButtonPin);
    int greenButtonState = digitalRead(greenButtonPin);
    int blueButtonState = digitalRead(blueButtonPin);

    if (redButtonState == HIGH) {
      red += 1;
      analogWrite(redLED, red % 128);
    }

    if (greenButtonState == HIGH) {
      green += 1;
      analogWrite(greenLED, green % 128);
    }

    if (blueButtonState == HIGH) {
      blue += 1;
      analogWrite(blueLED, blue % 128);
    }

    delay(delaytime);
}
