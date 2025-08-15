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
      case 'w': // Move both motors forward
       analogWrite(M1_pin1, 200);  // Motor 1 forward
        analogWrite(M1_pin2, 0);    // Motor 1 stop
        analogWrite(M2_pin1, 0);    // Motor 2 stop
        analogWrite(M2_pin2, 200);  // Motor 2 backward
        Serial.println("Motors: forward");
        delay(1000);
        break;

      case 's': // Move both motors backward
       analogWrite(M1_pin1, 0);    // Motor 1 stop
        analogWrite(M1_pin2, 200);  // Motor 1 backward
        analogWrite(M2_pin1, 200);  // Motor 2 forward
        analogWrite(M2_pin2, 0);    // Motor 2 stop
        Serial.println("Motors: backward");
        delay(1000);
        break;

      case 'a': // Motor 1 left, Motor 2 right
         analogWrite(M1_pin1, 200);  // Motor 1 forward
        analogWrite(M1_pin2, 0);    // Motor 1 stop
        analogWrite(M2_pin1, 200);  // Motor 2 forward
        analogWrite(M2_pin2, 0);    // Motor 2 stop
        Serial.println("Motor 1: left, Motor 2: right");
        delay(1000);
        break;

      case 'd': // Motor 1 right, Motor 2 left
      analogWrite(M1_pin1, 0);    // Motor 1 stop
        analogWrite(M1_pin2, 200);  // Motor 1 backward
        analogWrite(M2_pin1, 0);    // Motor 2 stop
        analogWrite(M2_pin2, 200);  // Motor 2 backward
        Serial.println("Motor 1: right, Motor 2: left");
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
