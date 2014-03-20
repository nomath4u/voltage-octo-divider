//#include <ShiftRegister595.h>


//#include <SevenSegment.h>

#define DIVIDED 2.05 //The multiplier for the resistor divider so that you can read what you actually need.

byte seven_seg_digits[16][7] = { { 1,1,1,1,1,1,0 },  // = 0
                                 { 0,1,1,0,0,0,0 },  // = 1
                                 { 1,1,0,1,1,0,1 },  // = 2
                                 { 1,1,1,1,0,0,1 },  // = 3
                                 { 0,1,1,0,0,1,1 },  // = 4
                                 { 1,0,1,1,0,1,1 },  // = 5
                                 { 1,0,1,1,1,1,1 },  // = 6
                                 { 1,1,1,0,0,0,0 },  // = 7
                                 { 1,1,1,1,1,1,1 },  // = 8
                                 { 1,1,1,0,0,1,1 },  // = 9
                                 { 1,1,1,0,1,1,1 },  // = A
                                 { 0,0,1,1,1,1,1 },  // = b
                                 { 1,0,0,1,1,1,0 },  // = C
                                 { 0,1,1,1,1,0,1 },  // = d
                                 { 1,0,0,1,1,1,1 },  // = E
                                 { 1,0,0,0,1,1,1 }   // = F
                                 };
int sensorPin = A4;    // select the input pin for Vin
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
  Serial.begin(9600);
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

byte bconvert(int val){
  out = ((float)val/fraction)*DIVIDED;
  return out;
}

float fconvert(int val){
  float fout = ((float)val/fraction)*DIVIDED;
  return fout;
}
void writeSerial(float val){
  delay(1000);  //We don't need that much data
  Serial.println(val);
}
void loop() {
  sensorValue = analogRead(sensorPin);
  writeSerial(fconvert(sensorValue));
  //writeSerial(sensorValue);
  sevenSegWrite(bconvert(sensorValue));
  delay(10);

}
