/*
  Stepper.h - Arduino Library for EasyDriver 3.0 stepper driver board from Sparkfun.com

  Based on:
  Stepper.h - - Stepper library for Wiring/Arduino - Version 0.4
  Original library     (0.1) by Tom Igoe.
  Two-wire modifications   (0.2) by Sebastian Gassner
  Combination version   (0.3) by Tom Igoe and David Mellis
  Bug fix for four-wire   (0.4) by Tom Igoe, bug fix from Noah Shibley


        I wanted This library to be a simple drop-in replacement for the standard stepper lib.
        just change some defines and go!!

                                                                Makenb "at" gmail.com   8/28/09


*/

// ensure this library description is only included once
#ifndef NCSTEPPER_H_
#define NCSTEPPER_H_

// library interface description
class Stepper {
  public:
    // constructors:
    Stepper(int number_of_steps, int dir_pin, int step_pin, int fdc_pin);

    // speed setter method:
    void set_speed(long whatSpeed);
    long get_speed(void);
    // mover method:
    bool step(int number_of_steps);
    // renvoi la position en mm
    double get_pos_mm(void);
    // renvoi la position en nbre de pas
    long get_nb_step(void);
    int version(void);

  private:
    void step_motor(void);
    bool stat_fdc(void);

    unsigned long step_delay;    // delay between steps, in ms, based on speed
    int nb_steps_per_mm;      // nbre de pas pour 1 mm
    double step_mm;
    // motor pin numbers:
    int dir_pin;                // pin dir
    int step_pin;               // pin step
    int fdc_pin;                //pin fin de course
    long last_step_time;        // time stamp in ms of when the last step was taken
    long nb_step_pos ;            // position en nombre de pas a a partir de l'init machine
    bool fdc;
};

#endif

