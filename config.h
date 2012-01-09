/*
 * config.h
 *
 *  Created on: 7 janv. 2012
 *      Author: guill
 */

#ifndef CONFIG_H_
#define CONFIG_H_


// Configuration des Pins

// nombre de pas pour faire 1mm > 200 = 0.005 mm
int Xmotor = 200;
int Ymotor = 200;
int Zmotor = 200;

// variable de stockage des données entrantes
int incomingByte = 0;

// step
int Xpin = 3;
int Ypin = 4;
int Zpin = 5;

// sens de rotation
int Xdir = 6;
int Ydir = 7;
int Zdir = 8;

// fin de course
int Xfdc = 9;
int Yfdc = 10;
int Zfdc = 11;

// conf accel stepper
int speedwork = 200;
int acceleration = 100;

#endif /* CONFIG_H_ */
