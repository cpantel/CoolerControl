#include <SoftwareSerial.h>

const byte rx = 0;
const byte tx = 1;

const byte pwm = 4;


byte serialData;

byte pwmSpeed = 128;

unsigned int Ctemp = 0;

SoftwareSerial swSerial(rx, tx);

void setup() {
  
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);
  DDRB |= B00011100;

  delay(1000);
  swSerial.begin(9600);
  swSerial.println("BEGIN");
/*
  ADMUX = B10001111;

  ADCSRA = (1<<ADPS2) | (1<<ADPS1) | (1<<ADEN);
  // Perform Dummy Conversion to complete ADC init
  ADCSRA |= (1<<ADSC);
  while ((ADCSRA & (1<<ADSC)) != 0);  
*/
}

void loop() {

  if(swSerial.available() > 0){
    serialData = swSerial.read();
    switch (serialData) {
      case 'm':
        swSerial.println("+   increment speed");
        swSerial.println("-   decrement speed");
        swSerial.println("t   print temperature");
        swSerial.println("m   this menu");
      break;
      
      case '+':
           --pwmSpeed;
           analogWrite(pwm, pwmSpeed); 
           swSerial.print("pwm down: ");
           swSerial.println(int(pwmSpeed));
      break;
      case '-':
           ++pwmSpeed;
           analogWrite(pwm, pwmSpeed); 
           swSerial.print("pwm up: ");
           swSerial.println(int(pwmSpeed));
      break;

      case 't':
        /*
        ADCSRA |= (1<<ADSC);
        while ((ADCSRA & (1<<ADSC)) != 0)
        Ctemp = (ADC - 247)/1.22;
        swSerial.println(Ctemp);
        */
      break;

      default:
        swSerial.println("mi no entender");
        swSerial.println(serialData);    
        swSerial.println(int(serialData));
      break;
    }
    
  }
}
