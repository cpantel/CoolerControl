#include <SoftwareSerial.h>

const byte rx = 0;

const byte tx = 1;

char data;

SoftwareSerial swSerial(rx, tx);

void setup() {
  
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);
  swSerial.begin(9600);
  swSerial.println("BEGIN");
}

void loop() {

  if(swSerial.available() > 0){
    data = swSerial.read();
    switch (data) {
      case '0':
         swSerial.println("cero ok");
      break;
      case 'a':
         swSerial.println("a ok");
      break;
        case 'A':
        swSerial.println("A ok");
      break;
      case '-': 
         swSerial.println("- ok");
      break;

      default:
        swSerial.println("mi no entender");
        swSerial.println(data);
        swSerial.println(int(data));
      break;
    }
  }
}
