// Define pin connections
const int gasSensorPin = A0;      // MQ2 Gas Sensor is connected to analog pin A0
const int ledPin = 13;            // LED is connected to digital pin 13
const int buzzerPin = 9;          // Buzzer is connected to digital pin 9

// Define threshold value for triggering the alert
int gasThreshold = 400;           // Set threshold for gas detection, you can adjust this value
int gasValue = 0;                 // Variable to store the gas sensor value

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize pins
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Ensure that LED and Buzzer are OFF initially
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  // Read the analog value from MQ2 gas sensor
  gasValue = analogRead(gasSensorPin);
  
  // Print the gas value for debugging
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);
  
  // If the gas level exceeds the threshold, activate the alert system
  if (gasValue > gasThreshold) {
    // Turn on the LED and buzzer
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Gas detected! Alert triggered.");
  } else {
    // Otherwise, turn off the LED and buzzer
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
  
  // Delay for a short time before reading the sensor again
  delay(500);   // Delay for half a second
}
