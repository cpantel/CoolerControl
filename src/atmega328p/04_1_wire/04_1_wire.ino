
#include <EEPROM.h>
#include <dhtnew.h>


// 11, 12?, 15?, 16?, 17?
const byte pwm = 11; // PB3

const byte dhtpin1 = 8;
const byte dhtpin2 = 7;

char data;
char pwmSpeed = 128;

unsigned int temperature0 = 0;
float humidity1;
float temperature1;
float humidity2;
float temperature2;

DHTNEW dht1(dhtpin1);
DHTNEW dht2(dhtpin2);


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

  analogWrite(pwm, pwmSpeed);
  delay(1);
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
        Serial.println("s   store pwm speed to eeprom");
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
        temperature0 = (ADC - 247)/1.22;
        Serial.print("Internal Temp: ");
        Serial.println(temperature0);
      break;

      case '1':
        dht1.read();
        delay(1000);
        humidity1    = dht1.getHumidity();
        temperature1 = dht1.getTemperature();
        Serial.print("Temperature 1: ");
        Serial.println(temperature1);
        Serial.print("Humidity 1: ");
        Serial.println(humidity1);
      break;      

      case '2':
        dht2.read();
        delay(1000);
        humidity2    = dht2.getHumidity();
        temperature2 = dht2.getTemperature();
        Serial.print("Temperature 2: ");
        Serial.println(temperature2);
        Serial.print("Humidity 2: ");
        Serial.println(humidity2);
      break;      

      
      default:
        Serial.println("mi no entender");
      break;
    }
    Serial.println(data);
  }
}
