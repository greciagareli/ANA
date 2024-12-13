// Pin definitions for LEDs
const int ledPins[] = {2, 3, 4, 5, 6, 7};

// Timing intervals for each LED in milliseconds
// Substitute T1ON, T2ON, T3ON, T4ON, T5ON for the miliseconds of light per panel
// Substitute T1OFF, T2OFF, T3OFF, T4OFF, T5OFF for the miliseconds of light per panel
// T1, T2, T3, T4, T5 refer to the LED panels. This program allows 5 patterns in parallel and a light control denoted by the 0 at the end of the conditions
unsigned long onTimes[] = {T1ON, T2ON, T3ON, T4ON, T5ON, 0}; 
unsigned long offTimes[] = {T1OFF, T2OFF, T3OFF, T4OFF, T5OFF, 0}; 

// Variables to keep track of the state and timing for each LED
unsigned long previousMillis[] = {0, 0, 0, 0, 0, 0};
bool ledStates[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};  // Initial states is ON

void setup() {
  // Initialize each LED pin as OUTPUT
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], ledStates[i]);  // Set initial state
  }
}

void loop() {
  // Get the current time
  unsigned long currentMillis = millis();

  // Loop through each LED
  for (int i = 0; i < 6; i++) {
    // If the LED is D7 (always ON), skip timing logic
    if (i == 5) {
      continue;
    }

    // Check if it's time to toggle the LED state
    if (ledStates[i] == HIGH && (currentMillis - previousMillis[i] >= onTimes[i])) {
      // Turn OFF the LED
      ledStates[i] = LOW;
      previousMillis[i] = currentMillis;  // Reset the timer
      digitalWrite(ledPins[i], ledStates[i]);
    } else if (ledStates[i] == LOW && (currentMillis - previousMillis[i] >= offTimes[i])) {
      // Turn ON the LED
      ledStates[i] = HIGH;
      previousMillis[i] = currentMillis;  // Reset the timer
      digitalWrite(ledPins[i], ledStates[i]);
    }
  }
}

