=#include <Encoder.h>

Encoder myEnc(2, 3);    // Assuming encoder is connected to pins 4 and 5
const int in1Pin = 10;  // PWM pin for Motor forward
const int in2Pin = 9;   // PWM pin for Motor backward

// Encoder specifications
const int pulsesPerRevolution = 55;  // Number of pulses per revolution without reduction
const int reductionRatio = 70;       // Reduction ratio of the motor

// Define PID variables
float setpoint = 0;  // Target angle
float feedback;

///////////////////////////////////////////////////////////

// control parameters
float errorK;          // position error at the time instant k
float errorKm1 = 0;    // position error at the time instant k-1
float errorKm2 = 0;    // position error at the time instant k-2
float controlK = 0;    // control signal at the time instant k
float controlKm1 = 0;  // control signal at the time instant k-1
float controlKm2 = 0;  // control signal at the time instant k-2
int delayValue = 0;    // additional delay in [ms]

float EK = 0.58617 ;           // parameter that multiplies the error at the time instant k
float EKm1 = -0.96418;       // parameter that multiplies the error at the time instant k-1
float EKm2 = 0.37822 ;        // parameter that multiplies the error at the time instant k-2
float CKm1= 0.25978  ;     // parameter that multiplies the control signal at the time instant k-1
float CKm2= 0.74022;        // parameter that multiplies the control signal at the time instant k-2


//Calc sampling time//
int interval=20; //Sampling time
float pwmValue;


void setup() {
  // what is in here runs once
  pinMode(in1Pin, OUTPUT); //PWM pin1
  pinMode(in2Pin, OUTPUT); ////PWM pin2
  Serial.begin(115200);
}

void loop() {
      //What is in here will run forever
    while(Serial.available()>0){
      String command = Serial.readStringUntil('\n');
      //Once received, implement the process command function
      processCommand(command);
  }
    feedback = getPosition(); //loaD position
    errorK= setpoint-feedback;

    controlK = (CKm1 * controlKm1 ) + (CKm2 * controlKm2) + (EK * errorK) + (EKm1 * errorKm1) + (EKm2 * errorKm2);

    controlKm2 = controlKm1;
    controlKm1 = controlK;

    errorKm2 = errorKm1;
    errorKm1 = errorK;

    adjustMotor(controlK);
    //Prepare data to be published to the data streamer
    Serial.print(setpoint);
    Serial.print(",");
    Serial.print(feedback);
    Serial.print(",");
    Serial.print(micros());
    Serial.print(",");
    Serial.println();

    delay(interval); //Sampling time
}


