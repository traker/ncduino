/*
 * lcd.h
 *
 *  Created on: 8 janv. 2012
 *      Author: guill
 */

/**
void setup() {
  Serial1.begin(19200);
  ELCD_initialize();
  delay(200);
  ELCD_Clear_LCD();
  ELCD_Cursor_Position(0, 0);
  ELCD_put_str("Hello World !");
}

void loop() {
}
*/
/* Low Level ELCD routine */
void ELCD_initialize(){
  Serial1.print(0xA0, BYTE);
}

void ELCD_Cursor_OFF(){
  Serial1.print(0xA3, BYTE);
  Serial1.print(0x0C, BYTE);
}

void ELCD_Cursor_ON(){
  Serial1.print(0xA3, BYTE);
  Serial1.print(0x0E, BYTE);
}

void ELCD_Clear_LCD(){
  Serial1.print(0xA3, BYTE);
  Serial1.print(0x01, BYTE);
}

void ELCD_Cursor_Position(int x, int y){
  Serial1.print(0xA1, BYTE);
  Serial1.print(x, BYTE);
  Serial1.print(y, BYTE);
}

void ELCD_put_str(char *str){
  Serial1.print(0xA2, BYTE);
  while(*str)
    Serial1.print(*str++);
  Serial1.print(0, BYTE);
}

void ELCD_put_ch(char ch){
  Serial1.print(0xA2, BYTE);
  Serial1.print(ch);
  Serial1.print(0, BYTE);
}

