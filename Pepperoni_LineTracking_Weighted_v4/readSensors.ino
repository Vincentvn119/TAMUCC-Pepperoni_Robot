void readSensors()
{
  for (int i=0;i<8;i++)
  {
    sensorValues[i]=analogRead(sensorPins[i]);
    }
  }
void printValues()
{
  float error;
  readSensors();
  normalizeSensors();
  error=calculateError();
  Serial.print("READ");
  Serial.print(" ");
  for (int i=0;i<8;i++)
  {
    Serial.print(normalizedValues[i]);
    Serial.print(" ");
    }
    Serial.println(error);
  }
