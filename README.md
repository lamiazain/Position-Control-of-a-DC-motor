System identification for the DC motor to find the transfer function that best describes the system (System Identification toolbox, MATLAB).
For system Identification, real velocity was recorded against the given one (Arduino Code).
Discretizing the PID was done using the Tustin method (Simulink).
Apply the controller equation to the real system using (Arduino code).
You will need MATLAB R2023a or Latter to run this code.
Output result of a PID-controlled DC motor on SIMULINK
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/127b59c0-5263-4df8-acdc-c97e8d113f4b)

PID control in S domain and Z domain (Tustin used for discretization)
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/26c354bc-a7ad-4389-8870-c0e06711f3e4)
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/9fde0ace-5980-47c2-977e-bb268ca47e00)

System Identification:
A sinusoidal velocity was given to the motor as input, corresponding real velocity was recorded against this sinusoidally changing velocity.
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/997eefa6-eb1b-4429-be94-97b05626fc51)

Importing time domain data
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/f6b250c6-5154-4c57-82c3-43f56dae3673)

Time Plot of Input Data
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/a484c13c-14b9-4f8a-bcd9-1ec72ec25aef)
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/e70bd96d-7ebd-43bd-bdf3-68a138f23357)

Estimate model transfer function:
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/a7b817d2-b2d5-4515-9cff-988882bfaeba)

Trying Higher order models
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/28ac2c50-554f-4755-ab21-3983cd374404)

Linear tfmodel, We can change zeros and poles to get the best fit model
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/f6becdd5-7172-4b16-9b4a-ea811e1be6b7)

No Zero, Two poles (S domain):
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/ccdfcf5d-f5ce-4d16-847c-121a445030bf)

One zero, Two poles sys (Z domain):
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/6c64a454-2e51-4ff3-a9eb-6f639bfa42af)
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/55c67224-63ea-4337-99f2-3dce5c0879da)

One zero, Two poles sys(S domain):
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/0b5ee602-1024-4fd6-8749-9ababd10956d)
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/e6665aa3-e86d-4ebf-a22a-41e740b2d9cd)

No zeros, 3 poles sys(Z domain):
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/15d69486-25fc-4328-bb10-e5a315e35db8)

No zeros, 3 poles sys(S domain):
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/cd4881e2-0dc0-4d71-b3b8-a17af538c35e)

One zero, Two poles sys(Z domain):
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/bc0b6b65-0ea0-42d4-92b5-67fe3f82438e)

Bick the best fitting tfand export it to MATLAB workspace:
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/c137fc25-0d35-4394-ae95-bb8b1c621734)
![image](https://github.com/lamiazain/Position-Control-of-a-DC-motor/assets/36462678/a24dfd82-0839-4a85-a183-359b86a9534d)














