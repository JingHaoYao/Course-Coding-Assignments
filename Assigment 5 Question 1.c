
task main()
{
int initDistance = 0;
displayString(0,"Thurs 11:30 10");
wait1Msec(50);
SensorType[S2] = sensorEV3_Touch;
wait1Msec(50);
SensorType[S3] = sensorEV3_Ultrasonic;
wait1Msec(50);
while (SensorValue[S2] == 0){
}
while(SensorValue[S2] == 1){
}
clearTimer(T1);
initDistance = SensorValue[S3] - 20;
while(SensorValue[S2] == 0){
	motor[motorA] = motor[motorD] = 30;
}
motor[motorA] = motor[motorD] = 0;
wait1Msec(2000);
while(SensorValue[S3] < (initDistance/2 + 20)){
	motor[motorA] = motor[motorD] = -30;
}
motor[motorA] = motor[motorD] = 0;
eraseDisplay();
displayTextLine(2,"Time since pressed: %f", time1[T1]/1000.0);
wait1Msec(4000);
}
