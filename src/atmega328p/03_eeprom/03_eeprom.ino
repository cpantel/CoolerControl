
#include <EEPROM.h>

// 11, 12?, 15?, 16?, 17?
const byte pwm = 11; // PB3


char data;
char pwmSpeed = 128;
unsigned int Ctemp = 0;

void setup() {

  Serial.begin(9600);
  Serial.println("BEGIN");

  analogWrite(pwm, pwmSpeed); 

  //ADMUX = B10001111;
  ADMUX = (1<<REFS1) | (1<<REFS0) | (0<<ADLAR) | (1<<MUX3) | (0<<MUX2) | (0<<MUX1) | (0<<MUX0);  

  
  ADCSRA = (1<<ADPS2) | (1<<ADPS1) | (1<<ADEN);
  // Perform Dummy Conversion to complete ADC init
  ADCSRA |= (1<<ADSC);
  while ((ADCSRA & (1<<ADSC)) != 0);

  EEPROM.get(0,pwmSpeed);
  analogWrite(pwm, pwmSpeed);   
  
}

void loop() {

  if(Serial.available() > 0){
    data = Serial.read();
    switch (data) {
      case 'm':
        Serial.println("+   increment speed");
        Serial.println("-   decrement speed");
        Serial.println("t   print temperature");
        Serial.println("m   this menu");
      break;
      
      case 's':
        char tmp;
        Serial.print("stored pwn speed is: ");
        EEPROM.get(0,tmp);
        Serial.println(int(tmp));
        Serial.print("stored: ");
        EEPROM.put(0, pwmSpeed);
        Serial.println(int(pwmSpeed));
      break;
      
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

      case 't':
        ADCSRA |= (1<<ADSC);
        while ((ADCSRA & (1<<ADSC)) != 0)
        Ctemp = (ADC - 247)/1.22;
        Serial.print("Internal Temp: ");
        Serial.println(Ctemp);
      break;
      
      default:
        Serial.println("mi no entender");
      break;
    }
    Serial.println(data);
  }
}
