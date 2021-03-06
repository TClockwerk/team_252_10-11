/*
 * $Id: FLAC-test1.c 21 2010-02-17 10:19:42Z xander $
 */

/**
 * FLAC-driver.h provides an API for the Firgelli Linear Actuator.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * TODO:
 * - Add ramping support (being worked on, has a few bugs)
 *
 * Credits:
 * - Big thanks to Firgelli for providing me with a Linear Actuator to play with!
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 2.00 AND HIGHER.
 * Xander Soldaat (mightor_at_gmail.com)
 * 15 february 2010
 * version 0.1
 */

#include "drivers/FLAC-driver.h"

task main () {
  tMotor testMotor = motorA;

  PlaySound(soundBeepBeep);
  nxtDisplayBigTextLine(3, "Retract");
  FLACtretractLA(testMotor, 100);
  while(!isDone(testMotor)) wait1Msec(50);
  wait1Msec(200);
  nMotorEncoder[testMotor] = 0;
  wait1Msec(1000);

  PlaySound(soundBeepBeep);
  eraseDisplay();
  nxtDisplayBigTextLine(1, "Extend");
  nxtDisplayTextLine(3, "ticks:  40");
  nxtDisplayTextLine(4, "speed:  50");
  FLACextendLA(testMotor, 50, 40);
  while(!isDone(testMotor)) wait1Msec(50);
  if (isStalled(testMotor))
    nxtDisplayTextLine(7, "STALLED");
  wait1Msec(1000);

  PlaySound(soundBeepBeep);
  eraseDisplay();
  nxtDisplayBigTextLine(1, "Extend");
  nxtDisplayTextLine(3, "ticks: 100");
  nxtDisplayTextLine(4, "speed:  80");
  FLACextendLA(testMotor, 80, 100);
  while(!isDone(testMotor)) wait1Msec(50);
  if (isStalled(testMotor))
    nxtDisplayTextLine(7, "STALLED");
  wait1Msec(1000);
  eraseDisplay();

  PlaySound(soundBeepBeep);
  nxtDisplayBigTextLine(1, "Retract");
  nxtDisplayTextLine(3, "ticks: 120");
  nxtDisplayTextLine(4, "speed: 100");
  FLACtretractLA(testMotor, 100, 120);
  while(!isDone(testMotor)) wait1Msec(50);
  if (isStalled(testMotor))
    nxtDisplayTextLine(7, "STALLED");
  wait1Msec(1000);

  PlaySound(soundBeepBeep);
  nxtDisplayBigTextLine(1, "Retract");
  nxtDisplayTextLine(3, "ticks:  20");
  nxtDisplayTextLine(4, "speed: 100");
  FLACtretractLA(testMotor, 100, 20);
  while(!isDone(testMotor)) wait1Msec(50);
  if (isStalled(testMotor))
    nxtDisplayTextLine(7, "STALLED");
  wait1Msec(1000);

  PlaySound(soundBeepBeep);
  eraseDisplay();
  nxtDisplayBigTextLine(1, "Done");
  wait1Msec(2000);
}

/*
 * $Id: FLAC-test1.c 21 2010-02-17 10:19:42Z xander $
 */
