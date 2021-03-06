//Blinking sin delay

const int ledPin =  13;      // the number of the LED pin

int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

long intervalOn = 500;           // medio segundo  ON
long intervalOff = 5000;         // cinco segundos OFF
void setup() {
  pinMode(ledPin, OUTPUT);     
}

void loop()
{
  unsigned long currentMillis = millis();
  if (ledState == LOW) {
    if(currentMillis - previousMillis > intervalOff) {
            previousMillis = currentMillis;   
            ledState = HIGH;
    }
} else {
    if(currentMillis - previousMillis > intervalOn) {
           previousMillis = currentMillis;   
          ledState = LOW;
    }
}
digitalWrite(ledPin, ledState);
}


