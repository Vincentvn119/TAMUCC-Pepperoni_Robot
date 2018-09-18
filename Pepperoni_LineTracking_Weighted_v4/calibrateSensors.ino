void calibrateSensorsBlack()
{
  for (int i=0;i<8;i++)
  {
    black[i]=0;
    }
   for (int i=0;i<8;i++)
   {
    for (int j=0; j<500;j++)
    {
      int reading=analogRead(sensorPins[i]);
      if (black[i]<reading) //if black is less than the reading, the reading should be stored in black 
      {
        black[i]=reading;
        }
        delay(1);
      }
    }
  }

  void calibrateSensorsWhite()
{
  for (int i=0;i<8;i++)
  {
    long sum=0;
    for (int j=0;j<500;j++)
    {
      int reading=analogRead(sensorPins[i]); //reading data from the sensor
      sum=sum+reading; // sum all the data
      delay(1);
      }
      int average=sum/500;
      white[i]=average;
    }
  }
  
