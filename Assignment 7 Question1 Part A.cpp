void writeRGB(TFileHandle fout, string paper, long redValue, long greenValue, long blueValue)
{
	writeTextPC(fout, paper);
	writeCharPC(fout, ' ');
	writeLongPC(fout, redValue);
	writeCharPC(fout, ' ');
	writeLongPC(fout, greenValue);
	writeCharPC(fout, ' ');
	writeLongPC(fout, blueValue);
	writeEndlPC(fout);
}

task main()
{
	SensorType[S2] = sensorEV3_Color;
	wait1MSec(50);
	SensorMode[S2] = modeEV3Color_Color;
	wait1MSec(50);
	TFileHandle fout;
	bool openWritePC = openWritePC(fout,"RGBResults.txt");
	long redValue = 0, greenValue = 0, blueValue = 0;
	bool endProgram = false;
	getColorRGB(S2,redValue,greenValue,blueValue);
	redValue = greenValue = blueValue = 0;
		
	while(endProgram == false){
		while(!getButtonPress(buttonCenter) || !getButtonPress(buttonLeft) || !getButtonPress(buttonRight)){
		}
		if(getButtonPress(buttonLeft)){
			while(getButtonPress(buttonLeft)){
			}
			getColorRGB(S2,redValue,greenValue,blueValue);
			writeRGB(fout,"Pink",redValue,greenValue,blueValue);
		}
		else if(getbuttonPress(buttonRight)){
			while(getButtonPress(buttonRight)){
			}
			getColorRGB(S2,redValue,greenValue,blueValue);
			writeRGB(fout,"Orange",redValue,greenValue,blueValue);
		}
		else{
			endProgram = true;
		}
	}
}
