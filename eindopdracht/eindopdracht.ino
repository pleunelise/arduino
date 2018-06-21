const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin1 =  13;      // the number of the LED pin
const int ledPin2 =  12;
const int ledPin3 =  11;
const int ledPin4 =  10;
const int ledPin5 =  9;
const int allPins[] = {13,12,11,10,9};

int buttonState = LOW;       // variable for reading the pushbutton status
int prevButtonState = LOW;   // previous pushbutton state
int ledState = LOW;          // variable for keeping the LED state (HIGH=on)
long interval = 2000;      // interval (in msec) for blink

void setup() {
   Serial.begin(9600);  // init serial link: 9600 bits per second

  pinMode(ledPin1, OUTPUT);     // initialize the LED pin as an output: 
  pinMode(ledPin2, OUTPUT);     // initialize the LED pin as an output: 
  pinMode(ledPin3, OUTPUT);     // initialize the LED pin as an output: 
  pinMode(ledPin4, OUTPUT);     // initialize the LED pin as an output: 
  pinMode(ledPin5, OUTPUT);     // initialize the LED pin as an output: 
  pinMode(allPins, OUTPUT);
  
  pinMode(buttonPin, INPUT);   // initialize the pushbutton pin as an input:  
  startMillis = millis(); //start time
}
/*

void loop()
{
  currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
  if (currentMillis - startMillis >= period)  //test whether the period has elapsed
  {
    digitalWrite(ledPin, !digitalRead(ledPin));  //if so, change the state of the LED.  Uses a neat trick to change the state
    startMillis = currentMillis;  //IMPORTANT to save the start time of the current LED state.
  }
}*/
void loop() {
   currentMillis = millis(); //get the current time in milliseconds
   if (currentMillis - startMillis >= interval) //test wanneer de periode is aangebroken
   {
    nuMillis = currentMillis - startMillis;
    startMillis = currentMillis;
   }
   digitalWrite(ledPin1, HIGH); 
   
   digitalWrite(ledPin2, HIGH); 
   delay(interval); 
   digitalWrite(ledPin3, HIGH); 
   delay(interval);
   digitalWrite(ledPin4, HIGH); 
   delay(interval);   
   digitalWrite(ledPin5, HIGH); 
   delay(interval);   
   for (int i = 0; i < sizeof(allPins); i++) {
    //Serial.println(i);
    digitalWrite(allPins[i], LOW);
   }
   delay(interval);
   buttonState = digitalRead(buttonPin); // read the state of the pushbutton value
   Serial.println(buttonState);
   
   if (buttonState == HIGH && ledPin3 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin4, HIGH);
    //Serial.println();
  } else {
    // turn LED off:
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin5, HIGH);
    // break;
  }
  interval = interval - 100;

}
