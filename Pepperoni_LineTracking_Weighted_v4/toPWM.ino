void toPWM(int y)
{
  int left_motor_speed = maxSpeed+y;
    int right_motor_speed = maxSpeed-y;
    //------------------------------------------------------------------
    // The motor speed should not exceed the max PWM value
    left_motor_speed=constrain(left_motor_speed,0,maxSpeed);
    right_motor_speed=constrain(right_motor_speed,0,maxSpeed);
    moveWheels(1, right_motor_speed, 1);//right side motor move forward
    moveWheels(0, left_motor_speed, 1);//left side motor move forward

 
  }
/*
 * This function control the speed, direction of the motor
 * int motor: Left side motor or right side motor, motor=0 left side. motor=1 right side
 * int speedRover: How fast the motr will move, the value is from 0 -255 (PWM)
 * int directionTurn: Forward or backward. (directionTurn=1 : Forward). directionTurn=0:backward.
 */
void moveWheels(int motor, int speedRover, int directionTurn){


  boolean inPin1=LOW;
  boolean inPin2=HIGH;
  
  if(directionTurn == 1){ // Move Forward
    inPin1 = LOW;
    inPin2 = HIGH;
  }  
  if(directionTurn == 0){
    inPin1 = HIGH;
    inPin2 = LOW;
  }
  if(motor == 0){ //left side motor
    digitalWrite(M1_DIR,inPin1); 
    analogWrite(M1_PWM,speedRover);   //Top Left M1 Motor Speed
    
    //Motor 2 run forward: 30 LOW; 32 High
    digitalWrite(M2_DIR,inPin1);
    analogWrite(M2_PWM,speedRover);   //Bot Left M2 Motor Speed
  }
  
  if(motor == 1){ //Right side motor
    //Motor 3 run forward: 26 LOW; 28 High
    digitalWrite(M3_DIR,inPin2);
     analogWrite(M3_PWM,speedRover);  //Top Right M3 Motor Speed
    
    //Motor 4 run forward: 22 HIGH; 24 LOW
    digitalWrite(M4_DIR,inPin2);
    analogWrite(M4_PWM,speedRover);  //Bot Right M4 Motor Speed
  }  
}
  
