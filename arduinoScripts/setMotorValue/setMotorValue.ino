int motorPin = 3;

void setup() {
  pinMode(motorPin, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char inByte = 0;
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    analogWrite(motorPin, inByte);

    
    // byte read, send three characters
    Serial.print(inByte);   
  }
}
