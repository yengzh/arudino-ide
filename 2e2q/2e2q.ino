const int M1_pin1 = 5;  // Motor 1 control pin 1
const int M1_pin2 = 6;  // Motor 1 control pin 2
const int M2_pin1 = 9;  // Motor 2 control pin 1
const int M2_pin2 = 10; // Motor 2 control pin 2

void setup() {
  pinMode(M1_pin1, OUTPUT);
  pinMode(M1_pin2, OUTPUT);
  pinMode(M2_pin1, OUTPUT);
  pinMode(M2_pin2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter command: w = forward, s = backward, a = left, d = right, k = stop");
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();  // Read one character

    switch (command) {
      case 'w': // Motor 1 forward
        analogWrite(M1_pin1, 200);
        analogWrite(M2_pin1, 200);
        analogWrite(M1_pin2, 0);
        analogWrite(M2_pin1, 0);
        Serial.println("Motor 1: forward");
        delay(1000);
        break;

      case 's': // Motor 1 backward
        analogWrite(M1_pin1, 0);
        analogWrite(M1_pin2, 200);
        Serial.println("Motor 1: backward");
        delay(1000);
        break;

      case 'a': // Motor 2 left
        analogWrite(M2_pin1, 0);
        analogWrite(M2_pin2, 200);
        Serial.println("Motor 2: left");
        delay(1000);
        break;

      case 'd': // Motor 2 right
        analogWrite(M2_pin1, 200);
        analogWrite(M2_pin2, 0);
        Serial.println("Motor 2: right");
        delay(1000);
        break;

      case 'k': // Stop all motors
        analogWrite(M1_pin1, 0);
        analogWrite(M1_pin2, 0);
        analogWrite(M2_pin1, 0);
        analogWrite(M2_pin2, 0);
        Serial.println("All motors stopped");
        break;

      default:
        Serial.println("Invalid command. Use w/s/a/d/k.");
        break;
    }
  }
}
