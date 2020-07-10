
// 11, 12?, 15?, 16?, 17?
const byte pwm = 11; // PB3


char data;
char pwmSpeed = 128;


void setup() {

  //UBRR0L = B01100111;
  
  Serial.begin(9600);
  Serial.println("BEGIN");

  analogWrite(pwm, pwmSpeed); 
  
}

void loop() {

  if(Serial.available() > 0){
    data = Serial.read();
    switch (data) {
      case '-':
           --pwmSpeed;
           analogWrite(pwm, pwmSpeed); 
           Serial.print("pwm down: ");
           Serial.println(int(pwmSpeed));
      break;
      case '+':
           ++pwmSpeed;
           analogWrite(pwm, pwmSpeed); 
           Serial.print("pwm up: ");
           Serial.println(int(pwmSpeed));
      break;

      default:
        Serial.println("mi no entender");
      break;
    }
    Serial.println(data);
  }
}
