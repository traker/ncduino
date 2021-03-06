/*
 * lcd.cpp
 *
 *  Created on: 8 janv. 2012
 *      Author: guill
 */
#include "lcd.h"
#include <WProgram.h>
Lcd::Lcd(){
 // Serial1.begin(19200);

}

void Lcd::ELCD_initialize(){
  Serial1.print(0xA0, BYTE);
}

void Lcd::ELCD_Cursor_OFF(){
  Serial1.print(0xA3, BYTE);
  Serial1.print(0x0C, BYTE);
}

void Lcd::ELCD_Cursor_ON(){
  Serial1.print(0xA3, BYTE);
  Serial1.print(0x0E, BYTE);
}

void Lcd::ELCD_Clear_LCD(){
  Serial1.print(0xA3, BYTE);
  Serial1.print(0x01, BYTE);
}

void Lcd::ELCD_Cursor_Position(int x, int y){
  Serial1.print(0xA1, BYTE);
  Serial1.print(x, BYTE);
  Serial1.print(y, BYTE);
}

void Lcd::ELCD_put_str(char *str){
  Serial1.print(0xA2, BYTE);
  while(*str)
    Serial1.print(*str++);

  Serial1.print(0, BYTE);
}

void Lcd::ELCD_put_ch(char ch){
  Serial1.print(0xA2, BYTE);
  Serial1.print(ch);
  Serial1.print(0, BYTE);
}

void Lcd::chargement(){
  this->ELCD_Cursor_OFF();
  this->ELCD_Clear_LCD();
  this->ELCD_Cursor_Position(0, 0);
  this->ELCD_put_str("        .          ");
  this->ELCD_Cursor_Position(0, 1);
  this->ELCD_put_str("._  _. _|. .*._  _ ");
  this->ELCD_Cursor_Position(0, 2);
  this->ELCD_put_str("[ )(_.(_](_||[ )(_)");
  this->ELCD_Cursor_Position(0, 3);
  this->ELCD_put_str("         by traker");
  this->ELCD_Cursor_OFF();
}

 void Lcd::affiche(double x, double y, double z){
   char str[20] = "";

   this->ELCD_Clear_LCD();
   this->ELCD_Cursor_Position(0, 0);

   dtostrf(x,16,3,str);
   this->ELCD_put_str("X :");
   this->ELCD_put_str(str);

   this->ELCD_Cursor_Position(0, 1);
   dtostrf(y,16,3,str);
   this->ELCD_put_str("Y :");
   this->ELCD_put_str(str);

   this->ELCD_Cursor_Position(0, 2);
   dtostrf(z,16,3,str);
   this->ELCD_put_str("Z :");
   this->ELCD_put_str(str);

 }
