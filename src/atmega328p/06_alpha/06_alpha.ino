
#include <EEPROM.h>
#include <dhtnew.h>
#include "Brain.hpp"
#include "Config.hpp"

#define LEN 3


const byte pwm = 11;     // PB3

const byte dhtpin1 = 3;  // PD3
const byte dhtpin2 = 4;  // PD4

const byte halfSpeed = 127;
const byte fullSpeed = 255;

char data;
char pwmSpeed = 127;     // ??

unsigned long referenceTime;

unsigned int temperature0 = 0;
float humidity1;
float temperature1;
float humidity2;
float temperature2;

DHTNEW dht1(dhtpin1);
DHTNEW dht2(dhtpin2);

Config conf;
Brain brain;

void internalTempInit() {
  //ADMUX = B10001111; // ATtiny85
  ADMUX = (1<<REFS1) | (1<<REFS0) | (0<<ADLAR) | (1<<MUX3) | (0<<MUX2) | (0<<MUX1) | (0<<MUX0);  
  ADCSRA = (1<<ADPS2) | (1<<ADPS1) | (1<<ADEN);
  // Perform Dummy Conversion to complete ADC init
  ADCSRA |= (1<<ADSC);
  while ((ADCSRA & (1<<ADSC)) != 0);
}

void setup() {

  Serial.begin(19200);
  Serial.setTimeout(30000);
  Serial.println();
  Serial.println();
  Serial.println(F("Cooler controller v0.3 alpha"));
  Serial.println(F("Half speed"));
  
  analogWrite(pwm, halfSpeed);

  // internalTempInit();

  delay(1000);
  Serial.println("Full speed");
  analogWrite(pwm, fullSpeed);
  delay(1000);

  // Protect against HFUSE's EESAVE unprogrammed, EEPROM erased after programming
  if ( conf.readFromEEPROM() ) {
     Serial.println(F("EEPROM valid")); 
  } else {
     Serial.println(F("EEPROM not set, loading default values and writing to EEPROM"));
     conf.writeToEEPROM();
  }
  conf.show();
  conf.downloadToCLI();
  analogWrite(pwm, halfSpeed);
  delay(1000);
  referenceTime = millis();

  brainInit();
}

void brainInit() {
  brain.init(
    conf.weight_1,
    conf.weight_2,
    conf.scale,
    conf.temp_ref_1,
    conf.temp_ref_2,
    conf.min_speed,
    conf.delta_eq,
    conf.decrement_2,
    conf.decrement_1,
    conf.decrement_0,
    conf.increment_1,
    conf.increment_2,
    conf.increment_3
  );
  
}

void showCSV(){
  Serial.print(F("# T1:"));
  Serial.print(temperature1);
  Serial.print(F(", H1:"));
  Serial.print(humidity1);
  Serial.print(F(", T2:"));
  Serial.print(temperature2);
  Serial.print(F(", H2:"));
  Serial.print(humidity2);
  Serial.print(F(", CS:"));
  Serial.print(byte(pwmSpeed));
  Serial.println();
}


void showJSON(){
  
  Serial.print(F("{ \"T1\" : \""));  
  Serial.print(temperature1);
  Serial.print(F("\", \"H1\" : \""));
  Serial.print(humidity1);
  Serial.print(F("\", \"T2\" : \""));
  Serial.print(temperature2);
  Serial.print(F("\", \"H2\" : \""));
  Serial.print(humidity2);
  Serial.print(F("\", \"CS\" : \""));
  Serial.print(byte(pwmSpeed));
  Serial.print(F("\","));
  conf.showJSON();

  Serial.println("}");
}

void showStatus() {
//  Serial.print("Internal Temp            : ");
//        Serial.println(temperature0);
  Serial.print(F("External 1 Temperature/Humidity: "));
  Serial.print(temperature1);
  Serial.print(F(" / "));
  Serial.println(humidity1);
  Serial.print(F("External 1 Temperature/Humidity: "));
  Serial.print(temperature2);
  Serial.print(F(" / "));
  Serial.println(humidity2);
  Serial.print(F("Cooler speed                   : "));
  Serial.println(byte(pwmSpeed));
  Serial.println();
}

void loop() {

  unsigned int elapsedTime = millis();
  if ( elapsedTime - referenceTime > conf.sample_interval ) {
    referenceTime = elapsedTime;
    dht1.read();
    humidity1    = dht1.getHumidity();
    temperature1 = dht1.getTemperature(); 
    dht2.read();
    humidity2    = dht2.getHumidity();
    temperature2 = dht2.getTemperature();

    brain.addMeasure(temperature1,temperature2);

    pwmSpeed = brain.getNewSpeed(pwmSpeed);
    analogWrite(pwm, pwmSpeed); 

    showJSON();    
  } else if(Serial.available() > 0){
    data = Serial.read();
    Serial.print("> ");
    switch (data) {
      case '-':
           --pwmSpeed;
           if (pwmSpeed < conf.min_speed) {
             pwmSpeed = conf.min_speed;
           }
           analogWrite(pwm, pwmSpeed); 
           Serial.print(F("pwm down: "));
           Serial.println(byte(pwmSpeed));
      break;
      case '+':
           ++pwmSpeed;
           analogWrite(pwm, pwmSpeed); 
           Serial.print(F("pwm up: "));
           Serial.println(byte(pwmSpeed));
      break;

      case '0':
        Serial.println(F("Internal temperature not calibrated, not used"));
        //ADCSRA |= (1<<ADSC);
        //while ((ADCSRA & (1<<ADSC)) != 0)
        //temperature0 = (ADC - 247)/1.22;
        //Serial.print(F("Internal Temp: "));
        //Serial.println(temperature0);
      break;

      case '1':
        dht1.read();
        delay(1000);
        humidity1    = dht1.getHumidity();
        temperature1 = dht1.getTemperature();
        Serial.print(F("Temperature 1: "));
        Serial.println(temperature1);
        Serial.print(F("Humidity 1: "));
        Serial.println(humidity1);
      break;      

      case '2':
        dht2.read();
        delay(1000);
        humidity2    = dht2.getHumidity();
        temperature2 = dht2.getTemperature();
        Serial.print(F("Temperature 2: "));
        Serial.println(temperature2);
        Serial.print(F("Humidity 2: "));
        Serial.println(humidity2);
      break;      

      case '?': 
        showStatus();
      break;

      case 'm':
        Serial.println(F("+   increment speed"));
        Serial.println(F("-   decrement speed"));
        //Serial.println(F("v   apply speed formula"));
        Serial.println(F("0   sample and print internal temperature"));
        Serial.println(F("1   sample and print external 1 temperature"));
        Serial.println(F("2   sample and print external 2 temperature"));
        Serial.println(F("?   show current values"));
        
        Serial.println(F("c   show config values"));
        Serial.println(F("u   upload config values"));
        Serial.println(F("d   download config values"));
        Serial.println(F("r   reset config to EEPROM values"));
        Serial.println(F("s   show EEPROM parameteres (NOT IMPLEMENTED)"));
        Serial.println(F("w   write EEPROMpwm speed to eeprom"));
        Serial.println(F("m   this menu"));
        Serial.println();
      break;



      case 'r':
        if ( conf.readFromEEPROM() ) {
          brainInit();
          Serial.println(F("Config reset to EEPROM values"));
        } else {
          Serial.println(F("EEPROM invalid, impossible"));
        }
      break;

      case 'w':
        conf.writeToEEPROM();
        Serial.println(F("EEPROM set to config values"));
      break;

      case 'c':
         Serial.println(F("Current config values: "));
         conf.show();  
      break;         
    
      case 'd':
         Serial.println(F("Current config values: "));
         conf.downloadToCLI();  
         Serial.println();
      break;  

      case 'u':
         Serial.println(F("Upload replacement values for:"));
         Config inputConfig;
         conf.show();
         conf.downloadToCLI();
         Serial.println();
         if (conf.uploadFromCLI() ) {
           Serial.println(F("New configuration: "));
           conf.show();
           brainInit();
         } else {
           Serial.println(F("Bad signature"));
         }

      break;
         
      default:
        Serial.print(F("mi no entender: "));
        Serial.println(data);
      break;
    }
    Serial.println("> ");
  }
}
