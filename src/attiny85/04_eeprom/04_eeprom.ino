#include <SoftwareSerial.h>
#include <EEPROM.h>


const byte rx = 0;
const byte tx = 1;

const byte pwm = 4;


char serialData;
char pwmSpeed = 128;
unsigned int Ctemp = 0;


SoftwareSerial swSerial(rx, tx);

void setup() {
  
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);

  
  swSerial.begin(9600);
  swSerial.println("BEGIN");


  ADMUX = B10001111;

  ADCSRA = (1<<ADPS2) | (1<<ADPS1) | (1<<ADEN);
  // Perform Dummy Conversion to complete ADC init
  ADCSRA |= (1<<ADSC);
  while ((ADCSRA & (1<<ADSC)) != 0); 

  EEPROM.get(0,pwmSpeed);
  analogWrite(pwm, pwmSpeed); 
  
}

void loop() {

  if(swSerial.available() > 0){
    serialData = swSerial.read();
    switch (serialData) {
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
      case 's':
           char tmp;
           swSerial.print("stored pwn speed is: ");
           EEPROM.get(0,tmp);
           swSerial.println(int(tmp));
           swSerial.print("stored: ");
           EEPROM.put(0, pwmSpeed);
           swSerial.println(int(pwmSpeed));


      break;
      case 't':
      
        ADCSRA |= (1<<ADSC);
        while ((ADCSRA & (1<<ADSC)) != 0)
        Ctemp = (ADC - 247)/1.22;
        swSerial.print("temp: ");
        swSerial.println(Ctemp);
      
      break;
      default:
        swSerial.println("mi no entender");
      break;
    }
    swSerial.println(int(serialData));
  }
}
