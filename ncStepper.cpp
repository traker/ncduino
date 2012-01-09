/*
  Stepper.cpp - Arduino Library for EasyDriver 3.0 stepper driver board from Sparkfun.com

  Based on:
  Stepper.cpp - - Stepper library for Wiring/Arduino - Version 0.4
  Original library     (0.1) by Tom Igoe.
  Two-wire modifications   (0.2) by Sebastian Gassner
  Combination version   (0.3) by Tom Igoe and David Mellis
  Bug fix for four-wire   (0.4) by Tom Igoe, bug fix from Noah Shibley  

   I wanted This library to be a simple drop-in replacement for the standard stepper lib.
        just change some defines and go!!

                                                                Maken "at" maken.org    8/28/09

*/


#include "WProgram.h"
#include "ncStepper.h"

/*
 * EasyDriver constructor.
 * Sets Direction and Step Pins.
 */
Stepper::Stepper(int number_of_steps, int dir_pin, int step_pin, int fdc_pin)
{
  this->last_step_time = 0;                     // time stamp in ms of the last step taken
  this->number_of_steps = number_of_steps;      // total number of steps for this motor
  this->step_mm = 1 / number_of_steps ;         // clacul en mm la distance d'un pas

  // Arduino pins for the motor control connection:
  this->dir_pin = dir_pin;
  this->step_pin = step_pin;

  // Arduino pin pour fin de course
  this->fdc_pin = fdc_pin;

  // setup the pins on the microcontroller:
  pinMode(this->dir_pin, OUTPUT);
  pinMode(this->step_pin, OUTPUT);
  pinMode(this->fdc_pin, INPUT);

}


/*
  Sets the speed in revs per minute
*/
void Stepper::setSpeed(long whatSpeed)
{
  this->step_delay = 60L / ( whatSpeed * 1000L )/ this->number_of_steps * 1000L;
}

unsigned long Stepper::getSpeed(){
   return this->step_delay;
}

/*
  Moves the motor steps_to_move steps.  If the number is negative,
   the motor moves in the reverse direction.
 */
void Stepper::step(int bytecommand)
{  
  if(bytecommand == 1){
      digitalWrite(this->dir_pin, HIGH);
      this->nbsteppos = this->nbsteppos + 1 ;
  }else{
      this->nbsteppos = this->nbsteppos - 1 ;
  }
  this->stepMotor();
  digitalWrite(this->dir_pin, LOW);
}

/*
 * renvoie la position en millimetre
 */
float Stepper::getposmm(){

  return this->nbsteppos * this->step_mm;
}

/*
 * Moves the motor forward or backwards.
 */
void Stepper::stepMotor()
{
      delayMicroseconds(100);
          digitalWrite(step_pin, LOW);
      delayMicroseconds(100);
          digitalWrite(step_pin, HIGH);
      delayMicroseconds(int(this->step_delay));
 }

/*
  version() returns the version of the library:
*/
int Stepper::version(void)
{
  return .01;
}

