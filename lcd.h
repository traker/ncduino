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
#ifndef LCD_H_
#define LCD_H_
class Lcd{
  public:
  Lcd(int pinrx);
  void ELCD_initialize();
  void ELCD_Cursor_OFF(void);
  void ELCD_Cursor_ON(void);
  void ELCD_Clear_LCD(void);
  void ELCD_Cursor_Position(int x, int y);
  void ELCD_put_str(char *str);
  void ELCD_put_ch(char ch);

  private:

};

#endif
