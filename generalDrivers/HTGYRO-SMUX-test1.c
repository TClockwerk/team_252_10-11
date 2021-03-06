#pragma config(Sensor, S1,     HTSMUX,                sensorLowSpeed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: HTGYRO-SMUX-test1.c 20 2009-12-08 22:59:13Z xander $
 */

/**
 * HTGYRO-driver.h provides an API for the HiTechnic Gyroscopic Sensor.  This program
 * demonstrates how to use that API in combination with the Sensor MUX.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to HiTechnic for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 2.00 AND HIGHER.
 * Xander Soldaat (mightor_at_gmail.com)
 * 25 November 2009
 * version 0.1
 */

#include "drivers/HTGYRO-driver.h"

task main () {

  nxtDisplayCenteredTextLine(0, "HiTechnic");
  nxtDisplayCenteredBigTextLine(1, "GYRO");
  nxtDisplayCenteredTextLine(3, "SMUX Test");
  nxtDisplayCenteredTextLine(5, "Connect SMUX to");
  nxtDisplayCenteredTextLine(6, "S1 and sensor to");
  nxtDisplayCenteredTextLine(7, "SMUX Port 1");
  wait1Msec(2000);

  nxtDisplayCenteredTextLine(5, "Press enter");
  nxtDisplayCenteredTextLine(6, "to set relative");
  nxtDisplayCenteredTextLine(7, "heading");
  wait1Msec(2000);

  // Before using the SMUX, you need to initialise the driver
  HTSMUXinit();

  // Tell the SMUX to scan its ports for connected sensors
  HTSMUXscanPorts(HTSMUX);

  // The sensor is connected to the first port
  // of the SMUX which is connected to the NXT port S1.
  // To access that sensor, we must use msensor_S1_1.  If the sensor
  // were connected to 3rd port of the SMUX connected to the NXT port S4,
  // we would use msensor_S4_3

  wait1Msec(2000);
  eraseDisplay();
  time1[T1] = 0;
  while(true) {
    if (time1[T1] > 1000) {
      eraseDisplay();
      nxtDisplayTextLine(1, "Resetting");
      nxtDisplayTextLine(1, "heading");
      wait1Msec(500);

      // Start the calibration and display the offset
      nxtDisplayTextLine(2, "Offset: %4d", HTGYROstartCal(msensor_S1_1));
      PlaySound(soundBlip);
      while(bSoundActive);
      time1[T1] = 0;
    }

    while(nNxtButtonPressed != kEnterButton) {
      eraseDisplay();

      nxtDisplayTextLine(1, "Reading");
      // Read the current calibration offset and display it
      nxtDisplayTextLine(2, "Offset: %4d", HTGYROreadCal(msensor_S1_1));

      nxtDisplayClearTextLine(4);
      // Read the current rotational speed and display it
      nxtDisplayTextLine(4, "Gyro:   %4d", HTGYROreadRot(msensor_S1_1));
      nxtDisplayTextLine(6, "Press enter");
      nxtDisplayTextLine(7, "to recalibrate");
      wait1Msec(100);
    }
  }
}

/*
 * $Id: HTGYRO-SMUX-test1.c 20 2009-12-08 22:59:13Z xander $
 */
