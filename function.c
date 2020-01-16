#include <ctype.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void validation(char input[MAX_INPUT], char type){

    int valid = 0, length, i, times = 0;

    while(1){
        printf(">> ");
        scanf(" %s", input);
        length = strlen(input);

        for(i=0; i<length; i++){

            if(isdigit(input[i]) != 1){

            //'s' -> valid selection
            //'n' -> valid number
            //'t' -> valid temperature
                if(type=='s'){
                    printf("\nPlease, enter the index.\n");

                } else if(type=='n'){

                    if(input[i]=='.'){
                        if(times == 0){
                            valid++;
                            times++;
                            continue;
                        }
                    }

                    printf("\nPlease, enter a valid number.\n");

                } else if(type=='t'){

                //the temperature can have a minus sign only once at the beginning of the number
                    if(i==0 && input[i]=='-'){
                        valid++;
                        continue;

                    } else if(input[i]=='.'){

                //it might be a double number, so, here we check whether it is an only '.' sign or not
                        if(times == 0){
                            valid++;
                            times++;
                            continue;
                        }
                    }
                    printf("\nPlease, enter a valid number.\n");
                }

               valid = 0;
               times = 0;
               break;

             } else {
               valid++;
              }
        }

        printf("\n");

        if(valid==length)
             break;
    }

}

void prompt(char type){

    char choice;
    //c -> category
    //m -> measure
    //o -> others

    if(type == 'c'){
        printf("There is no such a category.\nDo you want to return to homepage? (y/n)");
    } else if(type == 'm'){
        printf("There is no such a measure.\nDo you want to return to homepage? (y/n)");
    } else if(type=='o'){
        printf("\nDo you want to return to homepage? (y/n)");
    }

        scanf(" %c", &choice);
          if(choice=='y'){
             system("cls");
             greeting();
          } else if (choice=='n'){
             printf("\nBYE :)\n\n");
          } else {
             printf("\nThere is not such an option. Bye -_-\n\n");
          }
}

void cycle(char type, int measure){

    char value[MAX_INPUT] = "";
    double result;
    int times = 0;

    if(type=='t'){
    //t -> temperature

    while(1){

        validation(value, 't');

        if(value[0]=='-' && strlen(value)==1){
               prompt('o');
               break;

        } else {

          result = atof(value);

          if(times==2){
             times=0;
             system("cls");
          }

          if(measure==1){
             printf("Celsius -> %.2f (C)\n\nFahrenheit -> %.2f (F)\n\nKelvin -> %.2f (K)\n\n\n", result, result*1.8 + 32, result + 273.15);

          } else if(measure==2){
             printf("Celsius -> %.2f (C)\n\nFahrenheit -> %.2f (F)\n\nKelvin -> %.2f (K)\n\n\n", (result - 32)/1.8, result, (result + 459.67)*5/9);

          } else if(measure==3){
             printf("Celsius -> %.2f (C)\n\nFahrenheit -> %.2f (F)\n\nKelvin -> %.2f (K)\n\n\n", result - 273.15, result*9/5 - 459.67, result);

          }
             times++;
         }
     }

 } else {
        //r_... -> ratio
        //m_.. -> mile to
        float r_weight = 0.001, r_pound = 0.002204622622, r_data1 = 0.0009765625, r_data2 = 0.125;
        float r_length = 0.1, r_mile = 0.0000006213711922, r_yard = 0.001093613298, r_feet = 0.003280839895, r_inch = 0.03937007874;
        float m_yard = 1760, m_feet = 5280, m_inch = 63360;

        while(1){

               validation(value, 'n');
               result = atof(value);

               if(result==0){
                  prompt('o');
                   break;
               }


               if(times==2){
                  times=0;
                  system("cls");
               }

            if(type=='w'){
            //w -> weight
                if(measure==1){
                    printf("Gram -> %.1lf\n\nKilogram -> %.2lf\n\nTon -> %.2lf\n\nPound -> %.2f\n\n\n", result, result*r_weight, result*r_weight*r_weight, result*r_pound);

                } else if(measure==2){
                    printf("Gram -> %.0lf\n\nKilogram -> %.1lf\n\nTon -> %.2lf\n\nPound -> %.2f\n\n\n", result*1/r_weight, result, result*r_weight, result*r_pound*1/r_weight);

                } else if(measure==3){
                    printf("Gram -> %.0lf\n\nKilogram -> %.0lf\n\nTon -> %.1lf\n\nPound -> %.2f\n\n\n", result*1/r_weight*1/r_weight, result*1/r_weight, result, result*r_pound*1/r_weight*1/r_weight);

                } else if(measure==4){
                    printf("Gram -> %.2lf\n\nKilogram -> %.2lf\n\nTon -> %.2lf\n\nPound -> %.2f\n\n\n", result*1/r_pound, result*1/r_pound*r_weight, result*1/r_pound*r_weight*r_weight, result);
                }

            } else if(type=='d'){
            //d -> data
                if(measure==1){
                  printf("Bit -> %.1lf\n\nByte -> %.3lf\n\nKilobyte -> %.3lf\n\nMegabyte -> %.3lf\n\nGigabyte -> %.3lf\n\nTerabyte -> %.3lf\n\n\n", result, result*r_data2, result*r_data2*r_data1, result*r_data2*r_data1*r_data1, result*r_data2*r_data1*r_data1*r_data1, result*r_data2*r_data1*r_data1*r_data1*r_data1);

                } else if(measure==2){
                  printf("Bit -> %.0lf\n\nByte -> %.1lf\n\nKilobyte -> %.3lf\n\nMegabyte -> %.3lf\n\nGigabyte -> %.3lf\n\nTerabyte -> %.3lf\n\n\n", result*8, result, result*r_data1, result*r_data1*r_data1, result*r_data1*r_data1*r_data1, result*r_data1*r_data1*r_data1*r_data1);

                } else if(measure==3){
                  printf("Bit -> %.0lf\n\nByte -> %.0lf\n\nKilobyte -> %.1lf\n\nMegabyte -> %.3lf\n\nGigabyte -> %.3lf\n\nTerabyte -> %.3lf\n\n\n", result*8192, result*1024, result, result*r_data1, result*r_data1*r_data1, result*r_data1*r_data1*r_data1);

                } else if(measure==4){
                  printf("Bit -> %.0lf\n\nByte -> %.0lf\n\nKilobyte -> %.0lf\n\nMegabyte -> %.1lf\n\nGigabyte -> %.3lf\n\nTerabyte -> %.3lf\n\n\n", result*8388608, result*1048576, result*1024, result, result*r_data1, result*r_data1*r_data1);

                } else if(measure==5){
                  printf("Bit -> %.0lf\n\nByte -> %.0lf\n\nKilobyte -> %.0lf\n\nMegabyte -> %.0lf\n\nGigabyte -> %.1lf\n\nTerabyte -> %.3lf\n\n\n", result*8589934592, result*1073741824, result*1048576, result*1024, result, result*r_data1);

                } else if(measure==6){
                  printf("Bit -> %.0lf\n\nByte -> %.0lf\n\nKilobyte -> %.0lf\n\nMegabyte -> %.0lf\n\nGigabyte -> %.0lf\n\nTerabyte -> %.1lf\n\n\n", result*8796093022000, result*1099511628000, result*1073741824, result*1048576, result*1024, result);

                }
            } else if(type=='l'){
             //l -> length
                if(measure==1){
                  printf("Millimeter -> %.1lf\n\nCentimeter -> %.1lf\n\nDecimeter -> %.1lf\n\nMeter -> %.1lf\n\nKilometer -> %.1lf\n\nMile -> %.1lf\n\nYard -> %.1lf\n\nFeet -> %.1lf\n\nInch -> %.1f\n\n\n", result, result*r_length, result*r_length*r_length, result*r_length*r_length*r_length, result*r_length*r_length*r_length*r_length*r_length*r_length, result*r_mile, result*r_yard, result*r_feet, result*r_inch);

                } else if(measure==2){
                  printf("Millimeter -> %.1lf\n\nCentimeter -> %.1lf\n\nDecimeter -> %.1lf\n\nMeter -> %.1lf\n\nKilometer -> %.1lf\n\nMile -> %.1lf\n\nYard -> %.1lf\n\nFeet -> %.1lf\n\nInch -> %.1f\n\n\n", result*1/r_length, result, result*r_length, result*r_length*r_length, result*r_length*r_length*r_length*r_length*r_length, result*r_mile*10, result*r_yard*10, result*r_feet*10, result*r_inch*10);

                } else if(measure==3){
                  printf("Millimeter -> %.1lf\n\nCentimeter -> %.1lf\n\nDecimeter -> %.1lf\n\nMeter -> %.1lf\n\nKilometer -> %.1lf\n\nMile -> %.1lf\n\nYard -> %.1lf\n\nFeet -> %.1lf\n\nInch -> %.1f\n\n\n", result*1/r_length*1/r_length, result*1/r_length, result, result*r_length, result*r_length*r_length*r_length*r_length, result*r_mile*100, result*r_yard*100, result*r_feet*100, result*r_inch*100);

                } else if(measure==4){
                  printf("Millimeter -> %.1lf\n\nCentimeter -> %.1lf\n\nDecimeter -> %.1lf\n\nMeter -> %.1lf\n\nKilometer -> %.1lf\n\nMile -> %.1lf\n\nYard -> %.1lf\n\nFeet -> %.1lf\n\nInch -> %.1f\n\n\n", result*1/r_length*1/r_length*1/r_length, result*1/r_length*1/r_length, result*1/r_length, result, result*r_length*r_length*r_length, result*r_mile*1000, result*r_yard*1000, result*r_feet*1000, result*r_inch*1000);

                } else if(measure==5){
                  printf("Millimeter -> %.1lf\n\nCentimeter -> %.1lf\n\nDecimeter -> %.1lf\n\nMeter -> %.1lf\n\nKilometer -> %.1lf\n\nMile -> %.1lf\n\nYard -> %.1lf\n\nFeet -> %.1lf\n\nInch -> %.1f\n\n\n", result*1/r_length*1/r_length*1/r_length*1/r_length*1/r_length*1/r_length, /**/result*1/r_length*1/r_length*1/r_length*1/r_length*1/r_length, result*1/r_length*1/r_length*1/r_length*1/r_length, result*1/r_length*1/r_length*1/r_length, result, result*r_mile*1000000, result*r_yard*1000000, result*r_feet*1000000, result*r_inch*1000000);

                } else if(measure==6){
                  printf("Millimeter -> %.1lf\n\nCentimeter -> %.1lf\n\nDecimeter -> %.1lf\n\nMeter -> %.1lf\n\nKilometer -> %.1lf\n\nMile -> %.1lf\n\nYard -> %.1lf\n\nFeet -> %.1lf\n\nInch -> %.1f\n\n\n", result*1/r_mile, result*1/(r_mile*10), result*1/(r_mile*100), result*1/(r_mile*1000), result*1/(r_mile*1000000), result, result*m_yard, result*m_feet, result*m_inch);

                } else if(measure==7){
                  printf("Millimeter -> %.1lf\n\nCentimeter -> %.1lf\n\nDecimeter -> %.1lf\n\nMeter -> %.1lf\n\nKilometer -> %.1lf\n\nMile -> %.1lf\n\nYard -> %.1lf\n\nFeet -> %.1lf\n\nInch -> %.1f\n\n\n", result*1/r_yard, result*1/(r_yard*10), result*1/(r_yard*100), result*1/(r_yard*1000), result*1/(r_yard*1000000), result*1/m_yard, result, result*3, result*36);

                } else if(measure==8){
                  printf("Millimeter -> %.1lf\n\nCentimeter -> %.1lf\n\nDecimeter -> %.1lf\n\nMeter -> %.1lf\n\nKilometer -> %.1lf\n\nMile -> %.1lf\n\nYard -> %.1lf\n\nFeet -> %.1lf\n\nInch -> %.1f\n\n\n", result*1/r_feet, result*1/(r_feet*10), result*1/(r_feet*100), result*1/(r_feet*1000), result*1/(r_feet*1000000), result*1/m_feet, result/3, result, result*12);

                } else if(measure==9){
                  printf("Millimeter -> %.1lf\n\nCentimeter -> %.1lf\n\nDecimeter -> %.1lf\n\nMeter -> %.1lf\n\nKilometer -> %.1lf\n\nMile -> %.1lf\n\nYard -> %.1lf\n\nFeet -> %.1lf\n\nInch -> %.1f\n\n\n", result*1/r_inch, result*1/(r_inch*10), result*1/(r_inch*100), result*1/(r_inch*1000), result*1/(r_inch*1000000), result*1/m_inch, result/36, result/12, result);

                }

            } else if(type=='p'){
             //p -> period
                if(measure==1){
                  printf("Second -> %.0lf\n\nMinute -> %.1lf\n\nHour -> %.1lf\n\nDay -> %.1lf\n\nWeek -> %.1lf\n\nMonth -> %.1lf\n\nYear -> %.1lf\n\n\n", result, result/60, result/3600, result/86400, result/(86400*7), result/(86400*30.5), result/(86400*365));

                } else if(measure==2){
                  printf("Second -> %.0lf\n\nMinute -> %.0lf\n\nHour -> %.1lf\n\nDay -> %.1lf\n\nWeek -> %.1lf\n\nMonth -> %.1lf\n\nYear -> %.1lf\n\n\n", result*60, result, result/60, result/1440, result/(1440*7), result/(1440*30.5), result/(1440*365));

                } else if(measure==3){
                  printf("Second -> %.0lf\n\nMinute -> %.0lf\n\nHour -> %.0lf\n\nDay -> %.1lf\n\nWeek -> %.1lf\n\nMonth -> %.1lf\n\nYear -> %.1lf\n\n\n", result*3600, result*60, result, result/24, result/(24*7), result/(24*30.5), result/(24*365));

                } else if(measure==4){
                  printf("Second -> %.0lf\n\nMinute -> %.0lf\n\nHour -> %.0lf\n\nDay -> %.0lf\n\nWeek -> %.1lf\n\nMonth -> %.1lf\n\nYear -> %.1lf\n\n\n", result*86400, result*1440, result*24, result, result/7, result/30.5, result/365);

                } else if(measure==5){
                  printf("Second -> %.0lf\n\nMinute -> %.0lf\n\nHour -> %.0lf\n\nDay -> %.0lf\n\nWeek -> %.0lf\n\nMonth -> %.1lf\n\nYear -> %.1lf\n\n\n", result*86400*7, result*1440*7, result*24*7, result*7, result, result*0.23, result*0.019);

                } else if(measure==6){
                  printf("Second -> %.0lf\n\nMinute -> %.0lf\n\nHour -> %.0lf\n\nDay -> %.0lf\n\nWeek -> %.0lf\n\nMonth -> %.0lf\n\nYear -> %.1lf\n\n\n", result*86400*30.5, result*1440*30.5, result*24*30.5, result*30.5, result/0.23, result, result*0.083);

                } else if(measure==7){
                  printf("Second -> %.0lf\n\nMinute -> %.0lf\n\nHour -> %.0lf\n\nDay -> %.0lf\n\nWeek -> %.0lf\n\nMonth -> %.0lf\n\nYear -> %.0lf\n\n\n", result*86400*365, result*1440*365, result*24*365, result*365, result/0.019, result/0.083, result);

                }

            }
                times++;
        }

  }
}
