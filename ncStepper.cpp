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
  this->nb_steps_per_mm = number_of_steps;      // total number of steps for this motor
  this->step_mm = 0.000;         // clacul en mm la distance d'un pas

  // Arduino pins for the motor control connection:
  this->dir_pin = dir_pin;
  this->step_pin = step_pin;

  // Arduino pin pour fin de course
  this->fdc_pin = fdc_pin;
  this->nb_step_pos = 0;

  // setup the pins on the microcontroller:
  pinMode(this->dir_pin, OUTPUT);
  pinMode(this->step_pin, OUTPUT);
  pinMode(this->fdc_pin, INPUT);

}


/*
  Sets the speed in revs per minute
*/
void Stepper::set_speed(long whatSpeed)
{
  this->step_delay = 60L / ( whatSpeed * 1000L )/ this->nb_steps_per_mm * 1000L;
}

long Stepper::get_speed(){
   return this->step_delay;
}

/*
  Moves the motor steps_to_move steps.  If the number is negative,
   the motor moves in the reverse direction.
 */
bool Stepper::step(int bytecommand)
{  
  //Serial.println(bytecommand);
  if(!this->stat_fdc()){
      if(bytecommand == 1){
          digitalWrite(this->dir_pin, HIGH);
          this->step_mm += 0.005 ;
      }else{
          this->step_mm -= 0.005 ;
      }
      this->step_motor();
      digitalWrite(this->dir_pin, LOW);
      return true;
  }else{
      return false;
  }
}

/*
 * renvoie la position en millimetre
 */
double Stepper::get_pos_mm(){

  return this->step_mm;
}
long Stepper::get_nb_step(){
  return this->nb_step_pos;
}
/*
 * Moves the motor forward or backwards.
 */
void Stepper::step_motor()
{
      delayMicroseconds(100);
          digitalWrite(step_pin, LOW);
      delayMicroseconds(100);
          digitalWrite(step_pin, HIGH);
      delayMicroseconds(int(this->step_delay));
}

bool Stepper::stat_fdc(void){
  this->fdc = digitalRead(this->fdc_pin);
  return this->fdc;
}
/*
  version() returns the version of the library:
*/
int Stepper::version(void)
{
  return .01;
}

