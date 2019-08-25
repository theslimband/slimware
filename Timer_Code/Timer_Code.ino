

// constants
const int buttonPin = 2;     // the number of the pushbutton pin
const int tonePin = 1;      //the number of the speaker pin
const int ledPin = 0;       //the number of the LED pin
const int led2Pin = 3;       //the number of the LED pin
const int led3Pin = 4;       //the number of the LED pin

// variables
byte currentButtonState = HIGH;         // variable for reading the pushbutton status
byte previousButtonState = HIGH;       // start old button state as off

long timerPeriod = 10000;  //countdown timer period 300000 = 5 min
const long reminderPeriod = 5000;  //period of delay to 2nd reminder 60000 = 1 min
const long toneFreq = 7500;   //freq of the beep noise 2500 or 7500

long millis_held;    // How long the button was held (milliseconds)

unsigned long firstTime = 0; // how long since the button was first pressed 


void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  // initialize the LED and Speaker pin as an output:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(tonePin,OUTPUT);
  digitalWrite(tonePin,LOW);

}

void loop() {
  currentButtonState = digitalRead(buttonPin);   // read the state of the pushbutton value:
  
  // if the button state changes to pressed, remember the start time, debounce delay 50
  if (currentButtonState == LOW && previousButtonState == HIGH && (millis() - firstTime) > 50) {
    firstTime = millis();
    beep(125);    //let user know button was pressed
    previousButtonState == LOW;
  }
    millis_held = (millis() - firstTime);
  
    // This if statement is a basic debouncing tool, the button must be pushed for at least
  // 100 milliseconds in a row for it to be considered as a push. 50+50= 100
  if (millis_held > 50) {
    
    if (currentButtonState == LOW && millis_held >= 4000 && millis_held < 5000) {
      beep(150); // Each second the button is held beep
      timerPeriod = 2000;
    }
    else if (currentButtonState == LOW && millis_held >= 5000 && millis_held < 6000) {
      beep(150); // Each second the button is held beep
      timerPeriod = 4000;
    }
    else if (currentButtonState == LOW && millis_held >= 6000 && millis_held < 7000) {
      beep(150); // Each second the button is held beep
      timerPeriod = 6000;
    }
    else if (currentButtonState == LOW && millis_held >= 7000) {
      beep(150); // Each second the button is held beep
      timerPeriod = 8000;
    }

    // check if the button was released since we last checked
    if (currentButtonState == HIGH && previousButtonState == LOW) {
      // Button pressed for less than 2 seconds, run countdown timer
      if (millis_held <2000) {
        //beep(125);    //let user know button was pressed
        delay(timerPeriod);      //length of countdown timer delay
        alarm();
        delay(reminderPeriod);   // length of reminder delay
        alarm();
      }
    }
      // ===============================================================================
    }
    previousButtonState = currentButtonState;
}
void beep(int onTime){
  digitalWrite(ledPin, HIGH);
  tone(tonePin,toneFreq,onTime);
  digitalWrite(tonePin,LOW);
  digitalWrite(ledPin, LOW);
}  

void alarm(){
    // start Beep Beep x2
    beep(125);
    delay(200);
    beep(125);
    delay(500);
    beep(125);
    delay(200);
    beep(125);



    
}
