#include <SoftwareSerial.h>

const byte rx = 0;
const byte tx = 1;

char serialData;

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

}

void loop() {

  if(swSerial.available() > 0){
    serialData = swSerial.read();
    switch (serialData) {
      case 't':
      
        ADCSRA |= (1<<ADSC);
        while ((ADCSRA & (1<<ADSC)) != 0)
        Ctemp = (ADC - 247)/1.22;
        swSerial.println(Ctemp);
      
      break;

      default:
        swSerial.println("mi no entender");
      break;
    }
    swSerial.println(serialData);
  }
}
