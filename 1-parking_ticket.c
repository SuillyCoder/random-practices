/*
v1
started at around 8:35PM
ended at around 9:50PM
no error-trapping, assumes that inputs are within bounds

v2
started at around 11:35PM
ended at around 11:45PM
understood what ROUNDED TOTAL actually means
added comments
*/

#include <stdio.h>

void main (){

    //user inputs
    char vehicle;
    printf("Type of vehicle? ");
    scanf("%c", &vehicle);

    int hourEnter, minuteEnter, hourExit, minuteExit;
    printf("Hour vehicle entered lot\t(0 - 24)? ");
    scanf("%d", &hourEnter);

    printf("Minute vehicle entered lot\t(0 - 60)? ");
    scanf("%d", &minuteEnter);

    printf("Hour vehicle left lot\t\t(0 - 24)? ");
    scanf("%d", &hourExit);

    printf("Minute vehicle left lot\t\t(0 - 60)? ");
    scanf("%d", &minuteExit);

    printf("\n\n\t\tPARKING LOT CHARGE\n");

    //determines which rate applies based on the vehicle
    float firstRateCost, secondRateCost, rateTime;
    switch (vehicle)
    {
        case 'C':
            printf("Type of vehicle: Car\n");
            firstRateCost = 0;
            secondRateCost = 1.5;
            rateTime = 3;
            break;
    
        case 'T':
            printf("Type of vehicle: Truck\n");
            firstRateCost = 1;
            secondRateCost = 2.3;
            rateTime = 2;
            break;

        case 'B':
            printf("Type of vehicle: Bus\n");
            firstRateCost = 2;
            secondRateCost = 3.7;
            rateTime = 1;
            break;
    }

    //prints out the time user inputted above
    printf("TIME-IN\t\t\t%02d : %02d\n", hourEnter, minuteEnter);
    printf("TIME-OUT\t\t%02d : %02d\n", hourExit, minuteExit);
    printf("\t\t\t--------\n");

    //calculates total period of time parked in minutes
    int parkingTime = (minuteExit + hourExit * 60) - (minuteEnter + hourEnter * 60);
    printf("PARKING TIME\t\t%02d : %02d\n", parkingTime / 60, parkingTime % 60);

    //calculates whole-numbered hours that the vehicle parked (calculations round up)
    (parkingTime % 60 == 0) ? (parkingTime /= 60) : (parkingTime = parkingTime / 60 + 1);
    printf("ROUNDED TOTAL\t\t%02d\n", parkingTime);

    //applies the base rate
    float charge = firstRateCost;
    parkingTime -= rateTime;

    //applies the second rate
    while(parkingTime > 0) //'> 0' since 'parkingTime -= rateTime' could be less than 0 such as when 'parkingTime = 1' and 'rateTime = 3'
    {
        charge += secondRateCost;
        parkingTime--;
    }

    //prints result
    printf("\t\t\t--------\n");
    printf("TOTAL CHARGE\t\t$%02.2f", charge);

}