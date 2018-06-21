const int analogInPin = A0;  // Analog input pin for potentiometer
const int analogOutPin = 9;  // Analog output pin for LED

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  pinMode(analogOutPin, OUTPUT); // initialize LED output pin
}

void loop() {
  sensorValue = analogRead(analogInPin); // read the potmeter value
  delay(2);            // wait 2 milliseconds for the AD converter to settle
             
  //outputValue = map(sensorValue, 0, 1023, 0, 255);  // map input to output range
  //analogWrite(analogOutPin, outputValue);      // set the LED                          
}
