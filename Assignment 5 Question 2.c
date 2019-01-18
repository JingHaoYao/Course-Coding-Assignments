
task main()
{
	int numBlueTiles = 0;
	int maxRedTile = 0;
	int newRedTile = 0;
	int endingRedDist = 0;
	bool firstDetected = false;
	bool ifFirstBlue = false;
	displayString(0,"Thurs 11:30 10");
	SensorType[S3] = sensorEV3_Ultrasonic;
	wait1Msec(50);
	SensorType[S4] = sensorEV3_Color;
	wait1Msec(50);
	SensorMode[S4] = modeEV3Color_Color;
	wait1Msec(50);
	while(!getButtonPress(buttonEnter)){
	}
	while(getButtonPress(buttonEnter)){
	}
	while(SensorValue[S4] == (int)colorWhite){
		motor[motorA] = motor[motorD] = 30;
	}
	while(SensorValue[S4] != (int)colorWhite){
		if(SensorValue[S4] == (int)colorBlue && SensorValue[S3] < 50){
			motor[motorA] = motor[motorD] = 10;
		}
		else{
			motor[motorA] = motor[motorD] = 30;
		}
		if(SensorValue[S4] != (int)colorBlue && firstDetected == false){
			nMotorEncoder[motorA] = 0;
			firstDetected = true;
			if(ifFirstBlue == false){
				numBlueTiles++;
				ifFirstBlue = true;
			}
			}
		if(SensorValue[S4] == (int)colorBlue && firstDetected == true){
			numBlueTiles++;
			firstDetected = false;
			endingRedDist = nMotorEncoder[motorA]*((PI * 2.75)/180);
			newRedTile = endingRedDist;
			if(newRedTile > maxRedTile){
				maxRedTile = newRedTile;
			}
		}
		wait1Msec(50);
	}
	motor[motorA] = motor[motorD] = 0;
	eraseDisplay();
	displayTextLine(1,"# Blue Tiles: %d", numBlueTiles);
	displayTextLine(2,"Max Red Tile: %d",maxRedTile);
	wait1Msec(5000);
}
