#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>

#define endereco  0x27
#define colunas   16
#define linhas    2
#define trigger  12  
#define echo     13  
#define distancia_max 200

NewPing sonar(trigger, echo, distancia_max);
LiquidCrystal_I2C lcd (endereco, colunas, linhas);

float distancia;

void setup() {

  Serial.begin(115200);
  
  lcd.init(); 
  lcd.backlight(); 
  lcd.clear(); 
}

void loop() {

     distancia=sonar.ping_cm();
     lcd.setCursor(0,0);
     lcd.print("Distancia: ");
     lcd.print(distancia);

    delay(50);
    
}
