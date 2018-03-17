task main(){
	moveMotorTarget(motorB,500,50);
	moveMotorTarget(motorC,500,50);
	waitUntilMotorStop(motorB);
	waitUntilMotorStop(motorC);
}