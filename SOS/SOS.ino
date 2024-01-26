int EXT_LED = 12;
int INT_LED = 13;

void setup() {                
  Serial.begin(9600);
  pinMode(EXT_LED, OUTPUT);
  pinMode(INT_LED, OUTPUT);   
}


void loop() {
  Serial.println("SOS");
  
  digitalWrite(INT_LED, HIGH);
  for (int i = 0; i < 3; i++) {
    digitalWrite(EXT_LED, HIGH);
    delay(200);
    digitalWrite(EXT_LED, LOW);
    delay(200);
  }

  digitalWrite(INT_LED, LOW);
  for (int i = 0; i < 3; i++) {
    digitalWrite(EXT_LED, HIGH);
    delay(600);
    digitalWrite(EXT_LED, LOW);
    delay(600);
  }

  digitalWrite(INT_LED, HIGH);
  for (int i = 0; i < 3; i++) {
    digitalWrite(EXT_LED, HIGH);
    delay(200);
    digitalWrite(EXT_LED, LOW);
    delay(200);
  }
  
  digitalWrite(INT_LED, LOW);
  delay(2000);
}
