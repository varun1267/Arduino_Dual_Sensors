#define trig1 7
#define echo1 6
#define trig2 4
#define echo2 3
#define led 11
float distance;
int duration;
int RightSensor;
int LeftSensor;

void setup(){
  	Serial.begin (9600);
	pinMode(trig1,OUTPUT);
	pinMode(echo1, INPUT);
	pinMode(trig2, OUTPUT);
	pinMode(echo2, INPUT);
  pinMode(led,OUTPUT);
	
}

void loop() {
SonarSensor(trig1, echo1);
RightSensor = distance;
SonarSensor(trig2, echo2);
LeftSensor = distance;

Serial.print(LeftSensor);
Serial.print(" - ");
Serial.println(RightSensor);
  if (LeftSensor<=25||RightSensor<=25){
    digitalWrite(led,LOW);
  }
  else{
    digitalWrite(led,HIGH);
  }
  
  
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

}

  