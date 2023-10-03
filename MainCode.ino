//And this is varible for bluetooth
char Incoming_value = 0;
//this is motor's pins
int enA=9; 
int in1=8;
int in2=7;

void setup() {
Serial.begin(9600);
  // Set all pins output
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);


  
}
void directionControl()
{
  //set motor to maximum speed
  analogWrite(enA, 255); 

  //Turn on the motor a
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(2000); 
  
  //change the motor direction

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(2000);
 //Turn off the motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(2000);

}
//Controlling the speed of the motor A
 void speedControl() {
  // Turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  // Accelerate from zero to max speed
  for (int c = 0; c <= 255; c++) {
    analogWrite(enA, c);
    delay(20);
  }

  // Decelerate from maximum speed to 0
  for (int c = 255; c >= 0; c--) {
    analogWrite(enA, c);
    delay(20);
  }

  // Turn off the motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
}





void loop() {
  // Check if there's data available from Bluetooth
  if (Serial.available() > 0) {
    Incoming_value = Serial.read(); // Read the incoming data
    
    if (Incoming_value == '1') {
      directionControl(); // Call the function to control motor direction
    } else if (Incoming_value == '0') {
      speedControl(); // Call the function to control motor speed
    }
  }
} //Ok guys I ended the code . If I helped to you , it is good new for me. If you liked the video pls like the video. Bye!