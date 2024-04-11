void adjustMotor(float motorVoltage) {
  // Map voltage to PWM range
  pwmValue = int(motorVoltage/12*255);
  // Apply speed control to the motor
  if (pwmValue > 0) {
    analogWrite(in1Pin, pwmValue);
    analogWrite(in2Pin, 0);
  } else if (pwmValue < 0) {
    pwmValue = -pwmValue;
    analogWrite(in1Pin, 0);
    analogWrite(in2Pin, pwmValue);
  } else {
    // Motor is at rest
    analogWrite(in1Pin, 0);
    analogWrite(in2Pin, 0);
  }
}

float calculateVelocity() {
  float currentPosition = getPosition();
  float deltaTime = real_interval / 1000.0;  // Convert milliseconds to seconds
  float velocity = (currentPosition - previousPosition) / deltaTime;
  previousPosition = currentPosition;
  return velocity; //real
}
float getPosition() {
  float encoderCount = myEnc.read();
  // return Motor shaft  position
  return (encoderCount * 360.0) / float(pulsesPerRevolution*reductionRatio);
}