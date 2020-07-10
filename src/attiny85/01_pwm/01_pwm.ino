#include <SoftwareSerial.h>

const byte rx = 0;
const byte tx = 1;

const byte pwm = 4;


char data;
char pwmSpeed = 128;

SoftwareSerial swSerial(rx, tx);

void setup() {
  
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);

  
  swSerial.begin(9600);
  swSerial.println("BEGIN");

  analogWrite(pwm, pwmSpeed); 
  
}

void loop() {

  if(swSerial.available() > 0){
    data = swSerial.read();
    switch (data) {
      case '-':
           --pwmSpeed;
           analogWrite(pwm, pwmSpeed); 
           swSerial.print("pwm down: ");
           swSerial.println(int(pwmSpeed));
      break;
      case '+':
           ++pwmSpeed;
           analogWrite(pwm, pwmSpeed); 
           swSerial.print("pwm up: ");
           swSerial.println(int(pwmSpeed));
      break;

      default:
        swSerial.println("mi no entender");
      break;
    }
    swSerial.println(data);
  }
}
