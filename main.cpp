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

void setup() // fonction setup - début de l'exécution du programme
{
  Serial.begin(9600);
  Serial1.begin(19200);
  mylcd.ELCD_initialize();
  delay(1000);
  mylcd.chargement();
  delay(6000);
  mylcd.ELCD_Clear_LCD();
}

void loop()
{
  if (Serial.available() > 0) {
                  incomingByte = Serial.read();

                  if (incomingByte &= 128) {Xstep.step(incomingByte & 64 >> 6);}

                  if (incomingByte &= 32) {Ystep.step(incomingByte & 16 >> 4);}

                  if (incomingByte &= 8) {Zstep.step(incomingByte & 4 >> 2);}

                  // dit ce que vous obtenez
                  Serial.print(Xstep.getposmm());
                  Serial.println(incomingByte, BYTE);
                  mylcd.ELCD_put_ch('A');
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
