
#include <EEPROM.h>
#include <dhtnew.h>
#include "Brain.hpp"

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


struct Config {
  byte         signature       = 0x13;
  byte         temp_ref_1      = 25;
  byte         temp_ref_2      = 25;
  byte         weight_1        = 5;
  byte         weight_2        = 5;
  byte         decrement_2     = 20;
  byte         decrement_1     = 10;
  byte         equal           = 0;
  byte         increment_1     = 10;
  byte         increment_2     = 20;
  byte         increment_3     = 50;
  byte         min_speed       = 62;
  byte         scale           = 1;
  byte         delta_eq        = 2;
  byte         history_length  = 5;
  unsigned int min_interval    = 1000;
  unsigned int sample_interval = 5000;
};

Config storedConfig;
Config defaultConfig;

DHTNEW dht1(dhtpin1);
DHTNEW dht2(dhtpin2);

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

  Serial.begin(9600);
  Serial.setTimeout(30000);
  Serial.println();
  Serial.println();
  Serial.println(F("Cooler controller v1.0"));
  Serial.println(F("Half speed"));
  
  analogWrite(pwm, halfSpeed);

  internalTempInit();

  delay(storedConfig.min_interval);
  Serial.println("Full speed");
  analogWrite(pwm, fullSpeed);
  delay(storedConfig.min_interval);
 
  
  EEPROM.get(0,storedConfig);
  
  // Protect against HFUSE's EESAVE unprogrammed, EEPROM erased after programming
  // checkSignature
  // an object with
  if (storedConfig.signature != defaultConfig.signature) {
     Serial.println(F("EEPROM not set, loading default values"));
     storedConfig = defaultConfig;
  } else {
     Serial.println(F("EEPROM valid")); 
  }
  if (pwmSpeed <= storedConfig.min_speed) {
    pwmSpeed = halfSpeed;
  } else {
    Serial.print(F("Stored speed: "));
    Serial.println(byte(pwmSpeed));
  }
  analogWrite(pwm, pwmSpeed); 
  delay(storedConfig.min_interval);
  referenceTime = millis();

  brain.init(
    storedConfig.weight_1,
    storedConfig.weight_2,
    storedConfig.scale,
    storedConfig.temp_ref_1,
    storedConfig.temp_ref_2,
    storedConfig.min_speed,
    storedConfig.delta_eq,
    storedConfig.decrement_2,
    storedConfig.decrement_2,
    storedConfig.equal,
    storedConfig.increment_1,
    storedConfig.increment_2,
    storedConfig.increment_3
  );
  
}

void downloadConfig(Config *configToShow) {
        Serial.print(configToShow->signature);
        Serial.print(" ");
        Serial.print(configToShow->temp_ref_1);
        Serial.print(" ");
        Serial.print(configToShow->temp_ref_2);
        Serial.print(" ");
        Serial.print(configToShow->weight_1);
        Serial.print(" ");
        Serial.print(configToShow->weight_2);
        Serial.print(" ");
        Serial.print(configToShow->decrement_2);
        Serial.print(" ");
        Serial.print(configToShow->decrement_1);
        Serial.print(" ");
        Serial.print(configToShow->equal);
        Serial.print(" ");
        Serial.print(configToShow->increment_1);
        Serial.print(" ");
        Serial.print(configToShow->increment_2);
        Serial.print(" ");
        Serial.print(configToShow->increment_3);
        Serial.print(" ");
        Serial.print(configToShow->min_speed);
        Serial.print(" ");
        Serial.print(configToShow->delta_eq);
        Serial.print(" ");
        Serial.print(configToShow->history_length);
        Serial.print(" ");
        Serial.print(configToShow->min_interval);
        Serial.print(" ");
        Serial.print(configToShow->sample_interval);

}

void showConfig(Config *configToShow) {
        Serial.print(F("signature       : "));
        Serial.println(configToShow->signature);
        Serial.print(F("temp_ref_1      : "));
        Serial.println(configToShow->temp_ref_1);
        Serial.print(F("temp_ref_2      : "));
        Serial.println(configToShow->temp_ref_2);
        Serial.print(F("weight_1        : "));
        Serial.println(configToShow->weight_1);
        Serial.print(F("weight_2        : "));
        Serial.println(configToShow->weight_2);
        Serial.print(F("decrement_2     : "));
        Serial.println(configToShow->decrement_2);
        Serial.print(F("decrement_1     : "));
        Serial.println(configToShow->decrement_1);
        Serial.print(F("increment_1     : "));
        Serial.println(configToShow->increment_1);
        Serial.print(F("increment_2     : "));
        Serial.println(configToShow->increment_2);
        Serial.print(F("increment_3     : "));
        Serial.println(configToShow->increment_3);
        Serial.print(F("min_speed       : "));
        Serial.println(configToShow->min_speed);
        Serial.print(F("delta_eq        : "));
        Serial.println(configToShow->delta_eq);
        Serial.print(F("history_length  : "));
        Serial.println(configToShow->history_length);
        Serial.print(F("min_interval    : "));
        Serial.println(configToShow->min_interval);
        Serial.print(F("sample_interval : "));
        Serial.println(configToShow->sample_interval);
        Serial.println();
}

void showStatus() {
  //        Serial.print("Internal Temp                  : ");
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
  if ( elapsedTime - referenceTime > storedConfig.sample_interval ) {
    referenceTime = elapsedTime;
    dht1.read();
    humidity1    = dht1.getHumidity();
    temperature1 = dht1.getTemperature(); 
    dht2.read();
    humidity2    = dht2.getHumidity();
    temperature2 = dht2.getTemperature();

    brain.addMeasure(temperature1,temperature2);

    pwmSpeed = brain.getNewSpeed(pwmSpeed);
    showStatus();    
  } else if(Serial.available() > 0){
    data = Serial.read();
    Serial.print("> ");
    switch (data) {
      case '-':
           --pwmSpeed;
           if (pwmSpeed < storedConfig.min_speed) {
             pwmSpeed = storedConfig.min_speed;
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
        ADCSRA |= (1<<ADSC);
        while ((ADCSRA & (1<<ADSC)) != 0)
        temperature0 = (ADC - 247)/1.22;
        Serial.print(F("Internal Temp: "));
        Serial.println(temperature0);
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
        Serial.println(F("s   show EEPROM parameteres"));
        Serial.println(F("w   write EEPROMpwm speed to eeprom"));
        Serial.println(F("m   this menu"));
        Serial.println();
      break;



      case 'r':
        EEPROM.get(0,storedConfig);
        Serial.println(F("Config reset to EEPROM values"));
      break;

      case 'w':
        EEPROM.put(0,storedConfig);
        Serial.println(F("EEPROM set to config values"));
      break;

      case 'c':
         Serial.println(F("Current config values: "));
         showConfig(&storedConfig);  
      break;         
    
      case 'd':
         Serial.println(F("Current config values: "));
         downloadConfig(&storedConfig);  
         Serial.println();
      break;  

      case 'u':
         Serial.println(F("Upload replacement values for:"));
         Config inputConfig;
         showConfig(&storedConfig); 
         downloadConfig(&storedConfig); 
         Serial.println();
         inputConfig.signature       = Serial.parseInt();
         inputConfig.temp_ref_1      = Serial.parseInt();
         inputConfig.temp_ref_2      = Serial.parseInt();
         inputConfig.weight_1        = Serial.parseInt();
         inputConfig.weight_2        = Serial.parseInt();
         inputConfig.decrement_2     = Serial.parseInt();
         inputConfig.decrement_1     = Serial.parseInt();
         inputConfig.increment_1     = Serial.parseInt();
         inputConfig.increment_2     = Serial.parseInt();
         inputConfig.increment_3     = Serial.parseInt();
         inputConfig.min_speed       = Serial.parseInt();
         inputConfig.delta_eq        = Serial.parseInt();
         inputConfig.history_length  = Serial.parseInt();
         inputConfig.min_interval    = Serial.parseInt();
         inputConfig.sample_interval = Serial.parseInt();
         if (inputConfig.signature == storedConfig.signature ) {
           Serial.println(F("New configuration: "));
           storedConfig = inputConfig;
           showConfig(&storedConfig); 
         } else {
           Serial.println(F("Bad signature"));
         }

      break;
         
      default:
        Serial.print(F("mi no entender: "));
        Serial.println(data);
      break;
                   

    }
    Serial.print("> ");
  }
}
