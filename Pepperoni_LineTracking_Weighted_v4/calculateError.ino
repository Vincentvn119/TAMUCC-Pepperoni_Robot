//-34.12 is distance of the far left sensor to the center of the sensor array

float calculateError()
{
  float num=(-34.12*(normalizedValues[0]-normalizedValues[7]))+(-24.375*(normalizedValues[1]-normalizedValues[6]))
  +(-14.625*(normalizedValues[2]-normalizedValues[5]))+(-4.875*(normalizedValues[3]-normalizedValues[4])); // Find the sum for the numerator   x7(y7-y0)+x6(y6-y1)+x5(y5-y2)+x4(y4-y3)
  float denom=normalizedValues[0]+normalizedValues[1]+normalizedValues[2]+normalizedValues[3]+normalizedValues[4] // Find the sum for the denomerator
  +normalizedValues[5]+normalizedValues[6]+normalizedValues[7];

  if (denom !=0.0)
  {
    float error=num/denom;
    constrain(error,-34.12,34.12);
    return error;
    }
    else
    {
      float error=0.0;
      return error;
      }
  }
