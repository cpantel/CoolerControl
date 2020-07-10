#include <SoftwareSerial.h>
#include <EEPROM.h>
#include <dhtnew.h>

#define  rx  0
#define  tx  1
#define  pwm  4


#define DHTPIN1 2
#define DHTPIN2 3

char serialData;
char pwmSpeed = 128;
unsigned int temperature0 = 0;
float humidity1;
float temperature1;
float humidity2;
float temperature2;

SoftwareSerial swSerial(rx, tx);

DHTNEW dht1(DHTPIN1);
DHTNEW dht2(DHTPIN2);


void setup() {
  
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);

  int chk =dht1.read();
  delay(1000);
  humidity1    = dht1.getHumidity();
  temperature1 = dht1.getTemperature();  

  swSerial.begin(9600);
  swSerial.println("BEGIN");
  
  switch (chk)   {
    case DHTLIB_OK:
      swSerial.print("OK,\t");
      
      break;
    case DHTLIB_ERROR_CHECKSUM:
      swSerial.print("Checksum error,\t");
      break;
    case DHTLIB_ERROR_TIMEOUT:
      swSerial.print("Time out error,\t");
      break;
    default:
      swSerial.print("Unknown error,\t");
  }
  humidity1    = dht1.getHumidity();
  temperature1 = dht1.getTemperature();
             
  swSerial.print("Temperature 1: ");
  swSerial.println(temperature1);
  swSerial.print("Humidity 1: ");
  swSerial.println(humidity1);
  

  ADMUX = B10001111;

  ADCSRA = (1<<ADPS2) | (1<<ADPS1) | (1<<ADEN);
  // Perform Dummy Conversion to complete ADC init
  ADCSRA |= (1<<ADSC);
  while ((ADCSRA & (1<<ADSC)) != 0); 

  EEPROM.get(0,pwmSpeed);

}

void readTemp1() {
  int chk =dht1.read();
  delay(1000);
  switch (chk)   {
    case DHTLIB_OK:
      swSerial.print("OK,\t");
      
      break;
    case DHTLIB_ERROR_CHECKSUM:
      swSerial.print("Checksum error,\t");
      break;
    case DHTLIB_ERROR_TIMEOUT:
      swSerial.print("Time out error,\t");
      break;
    default:
      swSerial.print("Unknown error,\t");
  }
  humidity1    = dht1.getHumidity();
  temperature1 = dht1.getTemperature();
             
  swSerial.print("Temperature 1: ");
  swSerial.println(temperature1);
  swSerial.print("Humidity 1: ");
  swSerial.println(humidity1);
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
      case '0':
        ADCSRA |= (1<<ADSC);
        while ((ADCSRA & (1<<ADSC)) != 0)
        temperature0 = (ADC - 247)/1.22;
        swSerial.print("Temperature 0: ");
        swSerial.println(temperature0);

      
      break;
      case '1':
        readTemp1();
        
      break;

      case '2':
        dht2.read();
        delay(1000);
        humidity2    = dht2.getHumidity();
        temperature2 = dht2.getTemperature();
        swSerial.print("Temperature 2: ");
        swSerial.println(temperature2);
        swSerial.print("Humidity 2: ");
        swSerial.println(humidity2);
        
      break;
      
      default:
        swSerial.println("mi no entender");
      break;
    }
    swSerial.println(int(serialData));
  }
}
