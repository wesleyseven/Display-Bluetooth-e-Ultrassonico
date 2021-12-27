#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <NewPing.h>

SoftwareSerial BT (11,10);// RX, TX

#define endereco 0x27
#define colunas 16
#define linhas 2
#define trigger 12 //cinza
#define echo 13 //roxo
#define distancia_max 200

NewPing sonar (trigger, echo, distancia_max);
LiquidCrystal_I2C lcd (endereco, colunas, linhas);

char texto;
float distancia;

void setup() {

  BT.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(3, 0);
  lcd.print("iniciando");
  delay(1500);
  lcd.clear();

  lcd.setCursor(4, 0);
  lcd.print("Projeto");
  lcd.setCursor(1, 1);
  lcd.print("Greifen - 2021");

}

void loop() {
 
if (BT.available()) {
  
    texto = BT.read();
    lcd.print(texto);

      if(texto=='@'){
        lcd.clear();}

      if(texto=='#'){
        lcd.backlight();  
        lcd.clear();}

      if(texto=='$'){
       lcd.noBacklight();
       lcd.clear();}

      if(texto=='.'){
       lcd.setCursor(0, 1);}
              
    }
      
else if(texto=='*'){
  
       distancia = sonar.ping_cm(); 
       lcd.setCursor(0,0);
       lcd.print("Approximation:");
       lcd.setCursor(5,1);
       lcd.print(distancia);

       delay(250); }

}
