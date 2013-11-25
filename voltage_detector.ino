//#include <ShiftRegister595.h>


//#include <SevenSegment.h>

byte seven_seg_digits[10][7] = { { 1,1,1,1,1,1,0 },  // = 0
                                 { 0,1,1,0,0,0,0 },  // = 1
                                 { 1,1,0,1,1,0,1 },  // = 2
                                 { 1,1,1,1,0,0,1 },  // = 3
                                 { 0,1,1,0,0,1,1 },  // = 4
                                 { 1,0,1,1,0,1,1 },  // = 5
                                 { 1,0,1,1,1,1,1 },  // = 6
                                 { 1,1,1,0,0,0,0 },  // = 7
                                 { 1,1,1,1,1,1,1 },  // = 8
                                 { 1,1,1,0,0,1,1 }   // = 9
                                 };
int sensorPin = A0;    // select the input pin for Vin
int sensorValue = 0;  // variable to store the value coming from the sensor
float fraction = 1023/5; //Max adc out is 1023 and 5V going in
byte out;
void setup() {
  // declare the Seven Segment Display Pins as an OUTPUT:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  /*Start a Serial connection for testing*/
  //Serial.begin(9600);
  //Serial.println("Beginning Serial Output");
  /*Set dot pin to low*/
  digitalWrite(9,LOW);
}

void sevenSegWrite(byte digit) {
  byte pin = 2;
  for (byte segCount = 0; segCount < 7; ++segCount) {
    digitalWrite(pin, seven_seg_digits[digit][segCount]);
    ++pin;
  }
}

byte convert(int val){
  out = (val)/fraction;
  return out;
}
  

void loop() {
  sensorValue = analogRead(sensorPin);

  sevenSegWrite(convert(sensorValue));
  delay(10);

}
