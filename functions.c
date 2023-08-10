extern int vehicleSpeed,engineState,AC,temperature,engineTemperature,EngineTemperatureController;

char welcomeMenu(){
    char input;
    printf("a. Turn on the vehicle engine\n");
    printf("b. Turn off the vehicle engine\n");
    printf("c. Quit the system\n\n");
    printf("Choose one of those three options [a,b,c]: \n");
    scanf(" %c",&input);
    system("cls");
    return input;
}
char sensorsSetMenu(){
    char input;
    printf("a. Turn off the engine\n");
    printf("b. Set the traffic light color\n");
    printf("c. Set the room temperature (Temperature Sensor)\n");
    printf("d. Set the engine temperature (Engine Temperature Sensor)\n\n");
    printf("Choose one of those four options [a,b,c,d]: \n");
    scanf(" %c",&input);
    system("cls");
    return input;

}
void TrafficSensorRead(char input){
    switch(input){
    case'G': vehicleSpeed=100;break;
    case'O': vehicleSpeed=30;break;
    case'R': vehicleSpeed=0;break;
    default: printf("You entered invalid input!");break;
    }
}
void temperatureRoomSensorRead(int input){
   if(input<10){
    AC=1; temperature=20;
   }
   else if(input>30){
     AC=1; temperature=20;
   }
   else{
     AC=0; //temperature=0;
   }
}
void temperatureEngineSensorRead(int input){
   if(input<100){
    EngineTemperatureController=1; engineTemperature=125;
   }
   else if(input>150){
    EngineTemperatureController=1; engineTemperature=125;
   }
   else{
     EngineTemperatureController=0; //temperature=0;
   }
}
void vehicleSpeedfunc(){
   if(vehicleSpeed==30){
        if(AC==0){
             AC=1;temperature=temperature * (5/4) + 1;
        }
        if(EngineTemperatureController==0){
            EngineTemperatureController=1;engineTemperature=engineTemperature* (5/4) + 1;
        }
   }
}
void DisplayCurrentVehicleState(){
    printf("\nEngine state: %d\n",engineState);
    printf("AC: %d\n",AC);
    printf("Vehicle Speed: %d\n",vehicleSpeed);
    printf("Room Temperature: %d\n",temperature);
    printf("Engine Temperature Controller State: %d\n",EngineTemperatureController);
    printf("Engine Temperature: %d\n\n",engineTemperature);
}


