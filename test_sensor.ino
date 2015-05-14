int inputPin = 2;
int outputPin = 3;
int resetPin = 4;
int hasTurnedOn = 0;

void setup()
{
  Serial.begin(57600);
  Serial.println("Start");
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  pinMode(resetPin, INPUT);
  
  digitalWrite(outputPin, LOW);
  digitalWrite(resetPin, LOW);
}

void loop()
{
  Serial.print("Has Turned On: ");
  Serial.println(hasTurnedOn);
  
  if(hasTurnedOn == 0)
  {
    int startTime = millis();
    digitalWrite(outputPin, HIGH);
    //Guage how long the indicator takes to move from 0 to 1
    
    while(digitalRead(inputPin) == 0)
    {
      delay(1);  
    }
    Serial.println(digitalRead(inputPin));
  
    digitalWrite(outputPin, LOW);
    pinMode(outputPin, INPUT);
    
    hasTurnedOn = 1;
    int endTime = millis();
    int elapsed = endTime - startTime;
    Serial.print("Elapsed Time: ");
    Serial.println(elapsed);
    
    //Calculate capacitance
    //Based on 5V
    //Charged to 2.3V
    //Resistor 33k
    int time = elapsed / 1000;
    
  }
  else {
    pinMode(resetPin, OUTPUT);
    //Turn on reset pin to discharge capacitor
    digitalWrite(resetPin, HIGH);
    delay(3000);
    digitalWrite(resetPin, LOW);
    hasTurnedOn = 0;
  }

  
  delay(10000);

}
