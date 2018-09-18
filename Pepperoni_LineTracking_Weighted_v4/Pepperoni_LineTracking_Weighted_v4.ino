//*************************************************************
//*****   PEPPERONI CONTROLLER                            *****
//*****   Vincent Nguyen                                  *****
//*****   Daniel A. Gonzalez                              *****
//*****   Tamucc-Fall 2018                              *****
//*************************************************************

float Kp=1,Ki=0,Kd=0; // Change this value to see the result try Kp=0.5 jp =0.1 Kd =4
float error=0, P=0, I=0, D=0, PID_value=0;
float previous_error=0, previous_I=0;
int sensorValues[8];
int normalizedValues[8];
int white[8]={22,22,21,22,22,23,23,25};

int black[8]={613,502,429,432,560,564,540,664};
//int white[8]={};
//int black[8]={};
int sensorPins[]={A0,A1,A2,A3,A4,A5,A6,A7}; 
unsigned long lastTime;
float integral,lastError;
int maxSpeed=25; // For the PWM output

//Motors Pin set up:
int M1_PWM=11, M1_DIR=22; //PIN set up for Motor 1: Top Left
int M2_PWM=10, M2_DIR=24; //PIN set up for Motor 2: Bot Left
int M3_PWM=9, M3_DIR=26; //PIN set up for Motor 3: Top Right
int M4_PWM=5, M4_DIR=28; //PIN set up for Motor 4: Bot Right
  
  
void setup()
{
  Serial.begin(115200);
 // For Motor 1 (Top Left)
 // For Motor 1 (Top Left)
 pinMode(M1_PWM,OUTPUT); //PWM Pin
 pinMode(M1_DIR,OUTPUT);
//
// // For Motor 2 (Bottom Left)
 pinMode(M2_PWM,OUTPUT); //PWM PIN 5
 pinMode(M2_DIR,OUTPUT); 
 
// // For Motor 3 (Top Right)
 pinMode(M3_PWM,OUTPUT); //PWM PIN 3
 pinMode(M3_DIR,OUTPUT); 
//
// // For Motor 4 (Bot Right)
// pinMode(M4_PWM,OUTPUT); //PWM PIN 2
// pinMode(M4_DIR,OUTPUT); 
//moveWheels(1, 20, 1);//right side motor move forward
//moveWheels(0, 20, 0);//left side motor move forward
//delay(5000);
//moveWheels(1, 0, 1);//right side motor move forward
//moveWheels(0, 0, 0);//left side motor move forward
delay(3000);

}

void loop()
{
float error;
int output=0;
readSensors();
normalizeSensors();
error=calculateError();
Serial.print("error: ");
Serial.println(error);
//printValues();
output=PIDController(error);
//if output
delay(100);
toPWM(output);

  
}
