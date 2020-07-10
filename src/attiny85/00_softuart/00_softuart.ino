#include <SoftwareSerial.h>

const byte rx = 0;

const byte tx = 1;

char data;

SoftwareSerial swSerial(rx, tx);

void setup() {
  
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);
  DDRB |= B00011100;

  delay(5000);
  swSerial.begin(9600);
  swSerial.println("BEGIN");
  
  PORTB &= B11100011;
  delay(1000);
  
  PORTB |= B00000100;
  swSerial.println("led 0");
  delay(1000);
  
  PORTB |= B00001000;
  swSerial.println("led 1");
  delay(1000);
  
  PORTB |= B00010000;
  swSerial.println("led 2");
  delay(1000);

  swSerial.println("limpiando");
  PORTB &= B11100011;
  delay(1000);
}

void loop() {

  if(swSerial.available() > 0){
    data = swSerial.read();
    switch (data) {
      case '5':
         PORTB &= B11000011;
         swSerial.println("limpiando");
      break;
        case '0':
           PORTB |= B00000100;
           swSerial.println("led 0");
      break;
        case '1':
           PORTB |= B00001000;
           swSerial.println("led 1");
      break;
      case '2': 
           PORTB |= B00010000;
           swSerial.println("led 2");
      break;

      default:
        swSerial.println("mi no entender");
      break;
    }
    swSerial.println(data);
  }
}
