const int TrigPin = 2; 
const int EchoPin = 3; 
float cm; 
void setup() 
{ 
Serial.begin(9600); 
pinMode(TrigPin, OUTPUT); 
pinMode(EchoPin, INPUT); 
} 
void loop() 
{ 
digitalWrite(TrigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(TrigPin, HIGH); 
delayMicroseconds(10); 
digitalWrite(TrigPin, LOW); 

cm = pulseIn(EchoPin, HIGH) / 58.0; 
cm = (int(cm * 100.0)) / 100.0; 
Serial.print(cm); 
Serial.print("cm"); 
Serial.println(); 
delay(1000); 
} 

