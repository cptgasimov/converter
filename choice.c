#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


void chosenCategory(int category){

    int measure;
    char input[MAX_INPUT] = "";

    switch(category){
        case 1:
            printf("Chosen category: Data.\tNow, choose the measure: \n\n1.Bit\t\t\t2.Byte\n\n3.Kilobyte\t\t4.Megabyte\n\n5.Gigabyte\t\t6.Terabyte\n\n");
            validation(input, 's');
            measure = atoi(input);
            chosenMeasure(category, measure);
            break;


        case 2:
            printf("Chosen category: Temperature.\tNow, choose the measure: \n\n1.Celsius (C)\t\t2.Fahrenheit (F)\t\t3.Kelvin (K)\n\n");
            validation(input, 's');
            measure = atoi(input);
            chosenMeasure(category, measure);
            break;

        case 3:
            printf("Chosen category: Length.   Now, choose the measure: \n\n1.Millimeter\t\t2.Centimeter\n\n3.Decimeter\t\t4.Meter\n\n5.Kilometer\t\t6.Mile\n\n7.Yard\t\t\t8.Feet\n\n9.Inch\n\n");
            validation(input, 's');
            measure = atoi(input);
            chosenMeasure(category, measure);
            break;

        case 4:
            printf("Chosen category: Weight.    Now, choose the measure: \n\n1.Gram\t\t2.Kilogram\n\n3.Ton\t\t4.Pound\n\n");
            validation(input, 's');
            measure = atoi(input);
            chosenMeasure(category, measure);
            break;

        case 5:
            printf("Chosen category: Time.    Now, choose the measure: \n\n1.Second\t2.Minute\n\n3.Hour\t\t4.Day\n\n5.Week\t\t6.Month\n\n7.Year\n\n");
            validation(input, 's');
            measure = atoi(input);
            chosenMeasure(category, measure);
            break;

        default:
            prompt('c');
    }
}

void chosenMeasure(int category, int measure){

        system("cls");

        //Data is chosen
        if(category==1){

        switch(measure){
            //Bit
            case 1:
            printf("Chosen measure: Bit. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('d', 1);
            break;

            //Byte
            case 2:
            printf("Chosen measure: Byte. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('d', 2);
            break;

            //Kilobyte
            case 3:
            printf("Chosen measure: Kilobyte. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('d', 3);
            break;

            //Megabyte
            case 4:
            printf("Chosen measure: Megabyte. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('d', 4);
            break;

            //Gigabyte
            case 5:
            printf("Chosen measure: Gigabyte. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('d', 5);
            break;

            //Terabyte
            case 6:
            printf("Chosen measure: Terabyte. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('d', 6);
            break;

            default:
            prompt('m');
        }

    } else if(category==2){
        //Temperature is chosen

        switch(measure){

            case 1:
            printf("Chosen measure: Celsius (C). If you wish to exit, enter -\n\nNow, please, enter the value: \n\n");
            cycle('t', 1);
            break;

            case 2:
            printf("Chosen measure: Fahrenheit (F). If you wish to exit, enter -\n\nNow, please, enter the value: \n\n");
            cycle('t', 2);
            break;

            case 3:
            printf("Chosen measure: Kelvin (K). If you wish to exit, enter -\n\nNow, please, enter the value: \n\n");
            cycle('t', 3);
            break;

            default:
            prompt('m');
        }

    } else if(category==3){
        //Length is chosen

        switch(measure){
            //Millimeter
            case 1:
            printf("Chosen measure: Millimeter. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('l', 1);
            break;

            //Centimeter
            case 2:
            printf("Chosen measure: Centimeter. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('l', 2);
            break;

            //Decimeter
            case 3:
            printf("Chosen measure: Decimeter. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('l', 3);
            break;

            //Meter
            case 4:
            printf("Chosen measure: Meter. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('l', 4);
            break;

            //Kilometer
            case 5:
            printf("Chosen measure: Kilometer. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('l', 5);
            break;

            //Mile
            case 6:
            printf("Chosen measure: Mile. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('l', 6);
            break;

            //Yard
            case 7:
            printf("Chosen measure: Yard. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('l', 7);
            break;

            //Feet
            case 8:
            printf("Chosen measure: Feet. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('l', 8);
            break;

            //Inch
            case 9:
            printf("Chosen measure: Inch. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('l', 9);
            break;

            default:
            prompt('m');
        }

    } else if(category==4){
        //Weight is chosen

        switch(measure){

            //Gram
            case 1:
            printf("Chosen measure: Gram. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('w', 1);
            break;

            //Kilogram
            case 2:
            printf("Chosen measure: Kilogram. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('w', 2);
            break;

            //Ton
            case 3:
            printf("Chosen measure: Ton. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('w', 3);
            break;

            //Pound
            case 4:
            printf("Chosen measure: Pound. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('w', 4);
            break;

            default:
            prompt('m');
        }

    } else if(category==5){
            //Time is chosen

            switch(measure){

            //Second
            case 1:
            printf("Chosen measure: Second. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('p', 1);
            break;

            //Minute
            case 2:
            printf("Chosen measure: Minute. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('p', 2);
            break;

            //Hour
            case 3:
            printf("Chosen measure: Hour. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('p', 3);
            break;

            //Day
            case 4:
            printf("Chosen measure: Day. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('p', 4);
            break;

            //Week
            case 5:
            printf("Chosen measure: Week. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('p', 5);
            break;

            //Month
            case 6:
            printf("Chosen measure: Month. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('p', 6);
            break;

            //Year
            case 7:
            printf("Chosen measure: Year. If you wish to exit, enter 0\n\nNow, please, enter the value: \n\n");
            cycle('p', 7);
            break;

            default:
            prompt('m');
        }
    }


}

