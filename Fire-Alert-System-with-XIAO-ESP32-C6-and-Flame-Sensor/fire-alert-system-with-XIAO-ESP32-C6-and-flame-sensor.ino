//Tech Trends Shameer
//Flame Detection using XIAO ESP32 C6 and Flame Sensor

const int buzzerPin = 0;
const int flamePin = 1;
int Flame = HIGH;
int redled = 2; 
void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(redled, OUTPUT); 

  pinMode(flamePin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  Flame = digitalRead(flamePin);
  if (Flame== LOW)
  {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(redled, HIGH); 
  }
  else
  {
    digitalWrite(buzzerPin, LOW); 
    digitalWrite(redled, LOW);
  }
}
