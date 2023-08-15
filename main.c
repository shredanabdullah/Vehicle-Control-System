#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

//global variables
int vehicleSpeed=0,engineState=0,AC=0,temperature=25,engineTemperature=95,EngineTemperatureController=0;


int main()
{
     char inputCharSensor,sensorsSetChoice,choice;
     int inputIntSensor;
     choice=welcomeMenu();
    while(choice!='a'||choice!='b'){
       switch(choice){
        case 'a':
            engineState=1;
            do{
             DisplayCurrentVehicleState();
             sensorsSetChoice=sensorsSetMenu();
             switch(sensorsSetChoice){
                case'a':
                    engineState=0;
                    choice=welcomeMenu();
                    break;
                case'b':
                    printf("Enter the traffic light color: ");
                    scanf(" %c",&inputCharSensor);
                    TrafficSensorRead(inputCharSensor);
                    vehicleSpeedfunc();
                    break;
                case'c':
                    printf("Enter Temperature Sensor Reading: ");
                    scanf("%d",&inputIntSensor);
                    temperatureRoomSensorRead(inputIntSensor);
                    break;
                case'd':
                    printf("Enter Engine Temperature Sensor Reading: ");
                    scanf("%d",&inputIntSensor);
                    temperatureEngineSensorRead(inputIntSensor);
                    break;
                default: printf("You entered invalid input!");break;
                }
            }while(engineState==1);
            DisplayCurrentVehicleState();
            break;
        case 'b':
             choice=welcomeMenu();
              break;
        case 'c':
        return;
        default: printf("You entered invalid input!");break;
    }
    }



    return 0;
}
