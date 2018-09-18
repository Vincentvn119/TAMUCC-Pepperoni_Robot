void normalizeSensors()
{
  for (int i=0;i<8;i++)
  {
    normalizedValues[i]=map(sensorValues[i],white[i],black[i],0,1023);
    if (normalizedValues[i]<0)
    {
      normalizedValues[i]=0;
      }
    if (normalizedValues[i]>1023)
    {
      normalizedValues[i]=1023;
      }
   }
 }
