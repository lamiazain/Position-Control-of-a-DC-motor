#include <Encoder.h>

Encoder myEnc(2, 3);    // Assuming encoder is connected to pins 2 and 3
const int in1Pin = 10;  // PWM pin for Motor forward
const int in2Pin = 9;   // PWM pin for Motor backward

// Encoder specifications
const int pulsesPerRevolution = 55;  // Number of pulses per revolution without reduction
const int reductionRatio = 70;       // Reduction ratio of the motor

unsigned long previousMillis = 0;
const long interval = 20;  // Sampling time is nearly 20 ms

long real_interval = 0;

float maxVoltage = 12.0;  // Maximum supply voltage to the motor

// Variables for sinusoidal velocity profile
float amplitude = maxVoltage;  // Adjust the amplitude of the sine wave
float frequency = 0.5;          // Adjust the frequency of the sine wave//time one osscillation=2 sec

int pwmValue;
float previousPosition = 0;

void setup() {
  Serial.begin(115200);  // Start serial communication
  pinMode(in1Pin, OUTPUT); //PWM pin1
  pinMode(in2Pin, OUTPUT); ////PWM pin2

}

void loop() {
  //Number of milliseconds passed since the program started. Data type: unsigned long.
  unsigned long currentMillis = millis();

  // Calculate sinusoidal voltage profile from -12 to 12 volt
  float motorVoltage = amplitude * sin(2 * PI * frequency * currentMillis / 1000.0);
  //float motorVoltage=maxVoltage; 
  // Adjust motor voltage based on the voltage
  adjustMotor(motorVoltage);

  if (currentMillis - previousMillis >= interval) { //when 20 milliseconds pass
    real_interval = currentMillis - previousMillis; //return 20 milli secs
    previousMillis = currentMillis;

    // Calculate motor velocity
    float velocity = calculateVelocity();
    // Export data to Excel format (CSV)
    Serial.print(motorVoltage);
    Serial.print(",");
    //Output shaft Velocity Nearly 500-520 deg/s In case of 12v,
    //Motor shaft Velocity Nearly 35000-36400 deg/s received from encoder In case of 12v
    Serial.print(velocity);  
    Serial.print(",");
    Serial.println();
  }
}
