#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void greeting(){

    char category[MAX_INPUT] = "";
    int i, j, choice;

    for(i=0; i<9; i++){

        for(j=0; j<80; j++){

            if(i==0 || i==8){
                printf("#");
            } else if(i>1 && i<=6){

                if(j==6 || j==10 || j==14 || j==18 || j==26 || j==34 || j==42 || j==47 || j==51 || j==55 || j==59 || j==63){
                    printf("#");

                } else if((j>6 && j<=9) || (j>10 && j<=13)){
                //w
                    if(i==6){
                    printf("#");
                    } else{
                        printf(" ");
                    }

                } else if(j>=19 && j<=22){
                //e
                    if(i==2 || i==4 || i==6){
                        printf("#");
                    } else{
                        printf(" ");
                    }

                } else if(j>26 && j<=30){
                //l
                    if(i==6){
                    printf("#");
                    } else{
                        printf(" ");
                    }

                } else if(j>34 && j<=38){
                //c
                    if(i==2 || i==6){
                        printf("#");
                    } else{
                        printf(" ");
                    }

                } else if(j>42 && j<=46) {
                //o
                    if(i==2 || i==6){
                        printf("#");
                    } else{
                        printf(" ");
                    }

                } else if((j>51 && j<=54) || (j>55 && j<=58)){
                //m
                    if(i==2){
                    printf("#");
                    } else{
                        printf(" ");
                    }

                } else if(j>=64 && j<=67){
                //e
                   if(i==2 || i==4 || i==6){
                        printf("#");
                    } else{
                        printf(" ");
                    }

                } else if(j==73){
                //!
                    if(i==5){
                        printf(" ");
                    } else {
                        printf("#");
                    }

                } else {
                    printf(" ");
                }

            } else {
                printf(" ");
            }
        }
    }


    printf("\nPlease, choose a category: \n\n1. Data \t2. Temperature\n3. Length \t4. Weight\n5. Time\n\n");

    validation(category, 's');

    system("cls");
    choice = atoi(category);
    chosenCategory(choice);
}
