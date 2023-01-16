#include <AFMotor.h>

int analogPin = A2;     
                               
int val = 0;          

AF_DCMotor motor3(3, MOTOR12_1KHZ);
AF_DCMotor motor4(4, MOTOR12_1KHZ);

void setup()
{

  Serial.begin(9600);

}

void movestop()
{
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void forward()
{
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
}

void backward()
{
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
    
}

void  lookright()
{
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
}

void lookleft()
{
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
}

void loop()
{
  val = analogRead(analogPin);
  if(val < 1000)
  {   
    backward();
    delay(1000);
    
      
    movestop();
    delay(1000);
      
    lookright();
    delay(750);
  }
  else
  {
    forward();
    delay(1000); 
  }
}
