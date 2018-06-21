const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin1 =  13;      // the number of the LED pin
const int ledPin2 =  12;
const int ledPin3 =  11;
const int ledPin4 =  10;
const int ledPin5 =  9;
const int ledPin6 = 7;

int nextEvent = 0;
int nextEvent2 = 100;
int nextEvent3 = 200;
int nextEvent4 = 300;
int nextEvent5 = 400;

int buttonState = LOW;       // variable for reading the pushbutton status
int prevButtonState = LOW;   // previous pushbutton state
int ledState = LOW;          // variable for keeping the LED state (HIGH=on)
long interval = 1000;      // interval (in msec) for blink

void setup() {
  Serial.begin(9600);  // init serial link: 9600 bits per second

  pinMode(buttonPin, INPUT);
  pinMode(ledPin1, OUTPUT);     // initialize the LED pin as an output: 
  pinMode(ledPin2, OUTPUT);     // initialize the LED pin as an output: 
  pinMode(ledPin3, OUTPUT);     // initialize the LED pin as an output: 
  pinMode(ledPin4, OUTPUT);     // initialize the LED pin as an output: 
  pinMode(ledPin5, OUTPUT);     // initialize the LED pin as an output: 
  pinMode(ledPin6, OUTPUT);     // initialize the LED pin as an output: 

}


void loop() {
  
   if (nextEvent < millis()) //test wanneer de periode is aangebroken
   {
    nextEvent += interval;
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin5, LOW);

    //startTijd = millis();
   }

   if (nextEvent2 < millis())
   {
    nextEvent2 += interval;
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin1, LOW);

   }

   if (nextEvent3 < millis())
   {
    nextEvent3 += interval;
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin2, LOW);

   }

   if (nextEvent4 < millis())
   {
    nextEvent4 += interval;
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin3, LOW);

    }

   if (nextEvent5 < millis())
   {
    nextEvent5 += interval;
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin4, LOW);

    }


   buttonState = digitalRead(buttonPin);
   ledState = digitalRead(ledPin3);
   Serial.println(buttonState);
   if (buttonState == HIGH && ledState == HIGH)
   {
    buttonState = digitalRead(buttonPin);
    //Serial.println(buttonState);
    digitalWrite(ledPin6, HIGH);
    
    //nextEvent = nextEvent - 200;
    //nextEvent2 = nextEvent2 - 200;
    //nextEvent3 = nextEvent3 - 200;
    //nextEvent4 = nextEvent4 - 200;
    //nextEvent5 = nextEvent5 - 200;
    }
 }
