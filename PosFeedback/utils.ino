void stopMotor() {
  analogWrite(in1Pin, 255);
  analogWrite(in2Pin, 255);
}

void adjustMotor(float voltage) {

  pwmValue = (controlK/12)*255; //converting volt to speed
  if (pwmValue > 0) {
    pwmValue = map(pwmValue, 0, 255, 20, 255); //deadzone mapping
    analogWrite(in1Pin, constrain(pwmValue, 0, 255));
    analogWrite(in2Pin, 0);
  } else if (pwmValue < 0) {
    pwmValue = -pwmValue;                      //make it positive
    pwmValue = map(pwmValue, 0, 255, 20, 255);
    analogWrite(in1Pin, 0);
    analogWrite(in2Pin, constrain(pwmValue, 0, 255));
  }
}

float getPosition() {
  float encoderCount = myEnc.read(); //reads number of pulses
  //return the Position of the output shaft
  return (encoderCount * 360.0) / float(pulsesPerRevolution*reductionRatio); 
  // pulsesPerRevolution * reductionRatio = Number of pulses received at the encoder when the output shaft rotates 1 rev
}

void processCommand(String command) {
  if (command.startsWith("set=")) {
    // Extract and set new setpoint
    setpoint = command.substring(4).toFloat();
  } 
}
