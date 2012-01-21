/*
 * lcd.h
 *
 *  Created on: 8 janv. 2012
 *      Author: guill
 */

/* Low Level ELCD routine */
#ifndef LCD_H_
#define LCD_H_
class Lcd{
  public:
  Lcd(void);
  void ELCD_initialize(void);
  void ELCD_Cursor_OFF(void);
  void ELCD_Cursor_ON(void);
  void ELCD_Clear_LCD(void);
  void ELCD_Cursor_Position(int x, int y);
  void ELCD_put_str(char *str);
  void ELCD_put_ch(char ch);
  void chargement(void);
  void affiche(double x, double y, double z);

  private:

};

#endif
