int sensorPin = A0;    // select the input pin for Vin
/*Seven Segment display pins*/
int a = 2; 
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int h = 9;
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the Seven Segment Display Pins as an OUTPUT:
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);
  /*Start a Serial connection for testing*/
  Serial.begin(9600);
  Serial.println("Beginning Serial Output");
}

void loop() {
  Serial.println(sensorValue);
  delay(1000);  
}
