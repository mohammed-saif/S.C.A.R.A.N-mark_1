

#include <Servo.h>

Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;

int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos; // current position
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos; // previous position
int servo01SP[50], servo02SP[50], servo03SP[50], servo04SP[50], servo05SP[50], servo06SP[50]; // for storing positions/steps
int speedDelay = 20;
int index = 0;
String dataIn = "";

void setup() {
  servo01.attach(5);
  servo02.attach(6);
  servo03.attach(7);
  servo04.attach(8);
  servo05.attach(9);
  servo06.attach(10);
  Serial.begin(9600);
  Serial.print("i started");
  
  delay(20);
  // Robot arm initial position
  servo1PPos = 90;
  servo01.write(servo1PPos);
  servo2PPos = 120;
  servo02.write(servo2PPos);
  servo3PPos = 180;
  servo03.write(servo3PPos);
  servo4PPos = 90;
  servo04.write(servo4PPos);
  servo5PPos = 50;
  servo05.write(servo5PPos);
  servo6PPos = 80;
  servo06.write(servo6PPos);
}

void loop() {
  // Check for incoming data
  
    Serial.print("im in");
    dataIn =Serial.readString();          // Read the data as string
    Serial.print(dataIn);
                                        // If "Waist" slider has changed value - Move Servo 1 to position
    if (dataIn.startsWith("s1")==true) {
      Serial.print("to s1");
      String dataInS = dataIn.substring(2);
      Serial.print("shortened");               // Extract only the number. E.g. from "s1120" to "120"
      servo1Pos = dataInS.toInt(); 
      Serial.print("converted to int");           // Convert the string into integer
                                                 // We use for loops so we can control the speed of the servo
                                              // If previous position is bigger then current position
      if (servo1PPos > servo1Pos) {
        Serial.print("into loop");
        for ( int j = servo1PPos; j >= servo1Pos; j--) {          // Run servo down
          servo01.write(j);
          Serial.print("writing");
          delay(20);                           // defines the speed at which the servo rotates
        }
      }
      // If previous position is smaller then current position
      if (servo1PPos < servo1Pos) {
        Serial.print("into loop");
        for ( int j = servo1PPos; j <= servo1Pos; j++) {     // Run servo up
          servo01.write(j);
          Serial.print("writing");
          delay(20);
        }
      }
      servo1PPos = servo1Pos;                // set current position as previous position
    }
    
    // Move Servo 2
    if (dataIn.startsWith("s2")==true) {
      String dataInS = dataIn.substring(2, dataIn.length());
      servo2Pos = dataInS.toInt();

      if (servo2PPos > servo2Pos) {
        for ( int j = servo2PPos; j >= servo2Pos; j--) {
          servo02.write(j);
          delay(50);
        }
      }
      if (servo2PPos < servo2Pos) {
        for ( int j = servo2PPos; j <= servo2Pos; j++) {
          servo02.write(j);
          delay(50);
        }
      }
      servo2PPos = servo2Pos;
    }
    // Move Servo 3
    if (dataIn.startsWith("s3")==true) {
      String dataInS = dataIn.substring(2, dataIn.length());
      servo3Pos = dataInS.toInt();
      if (servo3PPos > servo3Pos) {
        for ( int j = servo3PPos; j >= servo3Pos; j--) {
          servo03.write(j);
          delay(30);
        }
      }
      if (servo3PPos < servo3Pos) {
        for ( int j = servo3PPos; j <= servo3Pos; j++) {
          servo03.write(j);
          delay(30);
        }
      }
      servo3PPos = servo3Pos;
    }
    // Move Servo 4
    if (dataIn.startsWith("s4")==true) {
      String dataInS = dataIn.substring(2, dataIn.length());
      servo4Pos = dataInS.toInt();
      if (servo4PPos > servo4Pos) {
        for ( int j = servo4PPos; j >= servo4Pos; j--) {
          servo04.write(j);
          delay(30);
        }
      }
      if (servo4PPos < servo4Pos) {
        for ( int j = servo4PPos; j <= servo4Pos; j++) {
          servo04.write(j);
          delay(30);
        }
      }
      servo4PPos = servo4Pos;
    }
    // Move Servo 5
    if (dataIn.startsWith("s5")==true) {
      String dataInS = dataIn.substring(2, dataIn.length());
      servo5Pos = dataInS.toInt();
      if (servo5PPos > servo5Pos) {
        for ( int j = servo5PPos; j >= servo5Pos; j--) {
          servo05.write(j);
          delay(30);
        }
      }
      if (servo5PPos < servo5Pos) {
        for ( int j = servo5PPos; j <= servo5Pos; j++) {
          servo05.write(j);
          delay(30);
        }
      }
      servo5PPos = servo5Pos;
    }
    // Move Servo 6
    if (dataIn.startsWith("s6")==true) {
      String dataInS = dataIn.substring(2, dataIn.length());
      servo6Pos = dataInS.toInt();
      if (servo6PPos > servo6Pos) {
        for ( int j = servo6PPos; j >= servo6Pos; j--) {
          servo06.write(j);
          delay(30);
        }
      }
      if (servo6PPos < servo6Pos) {
        for ( int j = servo6PPos; j <= servo6Pos; j++) {
          servo06.write(j);
          delay(30);
        }
      }
      servo6PPos = servo6Pos; 
    }
    
  }
