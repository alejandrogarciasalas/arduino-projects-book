const int sensorPin = 0;
const float baselineTemp = 25.0;

void setup() {
  Serial.begin(9600); // open a serial port between the Arduino and the computer 

  for(int pinNumber = 2; pinNumber<5; pinNumber++){ //put all pins 2-4 to OUTPUT mode and LOW
    pinMode(pinNumber, OUTPUT); 
    digitalWrite(pinNumber, LOW);
   }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  
  Serial.print(", degrees C: ");
  // convert the voltage to temperature in degrees
  float temperature = (voltage - .5) *100;
  Serial.println(temperature);

  if(temperature < baselineTemp){
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp+2 && temperature < baselineTemp+6){
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
    } else if (temperature >= baselineTemp+6){
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);  
    }

    delay(1);
}
