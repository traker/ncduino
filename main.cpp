/*
 * main.cpp
 *
 *  Created on: 7 janv. 2012
 *      Author: guill
 */
#include "config.h"
#include "lcd.h"
#include "ncstepper.h"
#include <WProgram.h>
//============================================================================
// Name        : main.cpp
// Author      : guill
// Version     :
// Copyright   : Your copyright notice
// Description : ncduino in C++, Ansi-style
//============================================================================


/** protocole host > slave 1 octet
  0|1     128|0         -X step
  0|1     64|0          -X dir
  0|1     32|0          -Y step
  0|1     16|0          -Y dir
  0|1     8|0           -Z step
  0|1     4|0           -Z dir
  0|1     2|0
  0|1     1|0

  exemple:
    192 = 11000000 = c0 = xtep et xdir son actif; change le sens du moteur puis fait 1 pas.
**/


//
Stepper Xstep(Xmotor, Xdir, Xpin, Xfdc);
Stepper Ystep(Ymotor, Ydir, Ypin, Yfdc);
Stepper Zstep(Zmotor, Zdir, Zpin, Zfdc);
Lcd mylcd;
int i = 0;

void setup() // fonction setup - début de l'exécution du programme
{
  Serial.begin(57600);
  Serial1.begin(19200);
  mylcd.ELCD_initialize();
  delay(1000);
  mylcd.chargement();
  delay(2000);

}

void loop()
{
  if (Serial.available() > 0) {
                  Serial.print("a");
                  incomingByte = Serial.read();
                  int temp = incomingByte;
                  i++;
                  if (temp &= 128) {
                    temp = incomingByte;
                    Xstep.step(temp & 64 >> 6);
                  }
                  temp = incomingByte;
                  if (temp &= 32) {
                      temp = incomingByte;
                      Ystep.step(temp & 16 >> 4);
                  }
                  temp = incomingByte;
                  if (temp &= 8) {
                    temp = incomingByte;
                    Zstep.step(temp & 4 >> 2);
                  }
                  temp = incomingByte;
                  //if ( i == 10) {
                  mylcd.affiche(Xstep.get_pos_mm(), Ystep.get_pos_mm(), Zstep.get_pos_mm());
                  //i=0;}

    }
}



int main(void) {

  /* Must call init for arduino to work properly */
  init();
  setup();

  for (;;) {
          loop();
  } // end for
} // end main
