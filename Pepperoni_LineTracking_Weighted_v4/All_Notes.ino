/* 8 Infrared sensors are placed in the front of the robot.
 * I/Connection diagram:
 * 1,H-Bridge to Arduino:
 * -Left side Motor:
 *   Motor 1 ( Top Left Motor)
 *    +M1_PWM=D11
 *    +M1_DIR=D22
 *   Motor 2 (Bot Left Motor)
 *    +M2_PWM=D10
 *    +M2_DIR=D24
 *   Motor 3 (Top Right Motor)
 *    +M3_PWM=D9
 *    +M3_DIR=D26 
 *   Motor 4 (Bot Right Motor)
 *    +M3_PWM=D5
 *    +M3_DIR=D28  
 * 2/ IR sensors to Arduino( From Left to Right- IR1 IR2 IR3 IR4 IR5):
 *    +IR1: D40
 *    +IR2: D41
 *    +IR3: D42
 *    +IR4: D43
 *    +IR5: D44
 *  Set up the spinning direction of each motor:
    //Motor 1 run forward: LOW
    digitalWrite(M1_DIR,LOW); 
    analogWrite(M1_PWM,speed);
    
    //Motor 2 run forward:  LOW
    digitalWrite(M2_DIR,LOW);
    digitalWrite(M2_PWM,speed);

    //Motor 3 run forward:  HIGH
    digitalWrite(M3_DIR,HIGH);
    digitalWrite(M3_PWM,speed);
        
    //Motor 4 run forward: HIGH;
    digitalWrite(M4_DIR,HIGH);
    digitalWrite(M4_PWM,speed);
 */
