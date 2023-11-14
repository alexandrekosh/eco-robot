#include <Ultrasonic.h>

Ultrasonic ultrasonic(9, 8);

class DCMotor {
  int spd = 255, pin1, pin2;
  public:
  void Pinout(int in1, int in2){
    pin1 = in1;
    pin2 = in2;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
  }
  void Speed(int in1){
    spd = in1;
  }
  void Forward(){ 
    analogWrite(pin1, spd);
    digitalWrite(pin2, LOW);
  }
  void Backward(){
    digitalWrite(pin1, LOW);
    analogWrite(pin2, spd);
  }
  void Stop(){
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
  }
};

DCMotor Motor1, Motor2;

void setup() {
  Motor1.Pinout(5,6); 
  Motor2.Pinout(10,11);
}

void loop() {

  float distance = ultrasonic.read();
  
  if(distance <= 30) {
    Motor1.Stop();
    Motor2.Stop();
    delay(200);
    Motor1.Backward(); 
    Motor2.Backward();
    delay(200);
    Motor1.Forward();
    Motor2.Backward();
    delay(200);
  }
  Motor1.Speed(200);
  Motor2.Speed(200);
  Motor1.Forward();
  Motor2.Forward();
  delay(1000);
}