#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorNone, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorNone, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main(){
  while(true){//forever
    motor[motorD] = 100;//run forward
  }
}
