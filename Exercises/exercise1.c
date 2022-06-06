//
// Created by 0x1nbetw33n on 06/04/2022.
//

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "exercise1.h"


double sum(double term1, double term2){ return term1 + term2; }

double subtraction(double term1, double term2){ return term1 - term2; }

double multiplication(double factor1, double factor2){ return factor1 * factor2; }

double division(double dividend, double divisor){ return dividend / divisor;}

float rounding(float no){return roundf(no); }

extern float rounding2(float no){return (no - (int) no) > .5f ? (int) no + 1 : (int) no;}

int abs(int no){return no >= 0 ? no : -no;}

int maxOf2Nos(int no1, int no2){return no1 > no2 ? no1 : no2;}

double max(double no1, double no2, double no3){
    //drawing a tree helps in understanding the expression
    return no1 > no2 ?
           (no1 > no3 ? no1 : no3) : (no2 > no3 ? no2 : no3);
}

int minOf2Nos(int no1, int no2){return no1 < no2 ? no1 : no2;}

double min(double no1, double no2, double no3){
    return no1 < no2 ?
           (no1 < no3 ? no1 : no3) : (no2 < no3 ? no2 : no3);
}

int ggT(int no1, int no2) {
    int max = maxOf2Nos(no1, no2);
    int min = minOf2Nos(no1, no2);
    int remainder = 0;
    while (min > 0){
        remainder = maxOf2Nos(min, max) % minOf2Nos(min, max);
        max = minOf2Nos(min, max);
        min = remainder;
    }
    return max;
}

bool isPrim(int possiblePrim){
    for (int i = 2; i < possiblePrim; i++) {
        if(ggT(possiblePrim, i) != 1){
            return false;
        }
    }
    return true;
}

bool arePrimTwins(int prim1, int prim2){ return abs(prim1 - prim2) == 2; }

 int printPrimTwins(int min, int max){
    int * prims[2] = {0, 0};
    for(int counter = min, arrayPosition = 0; counter < max; counter++){
        if(isPrim(counter)){
            //if the number is a prim no. -> assign the number to the array at current position of arrayPosition
            prims[arrayPosition] = counter;
            //if index points to array's first element -> increment
            arrayPosition = arrayPosition < 1 ? ++arrayPosition : arrayPosition;
            if(arePrimTwins(prims[0], prims[1])){
                printf("%d | %d\n", prims[0], prims[1]);
                //assigning arrayPosition again to array's first element to start looking for the next twins
                arrayPosition = 0;
            }
        }
    }
    return 0;
}

/*
int main(){
    printf("\nhello human:) u are awesome!\n");
    //printf("%f\n", sum(-1.5, 4.5));
    //printf("%f\n", subtraction(54., -99.));
    //printf("%f\n", multiplication(3., 25.));
    //printf("%f\n", division(3., 4.));
    //printf("%f\n", rounding(5.545f));
    //printf("%f\n", rounding2(5.347f));
    //printf("%f\n", rounding2(5.647f));
    //printf("%f\n", rounding2(3835.647f));
    //printf("%f\n", max(233., 111., 66.));
    //printf("%f\n", min(11., 20., 3.));
    //printf("%d\n", minOf2Nos(34, 85));
    //printf("%d\n", maxOf2Nos(34, 85));
    //printf("%d\n", isPrim(31)); //-> TRUE
    //printf("%d\n", isPrim(1)); //-> FALSE
    //printf("%d\n", isPrim(29)); //-> TRUE
    //printf("%d\n", isPrim(14)); //-> FALSE
    //printf("%d\n", isPrim(37)); //-> TRUE
   // printf("%d\n", isPrim(60)); //-> FALSE
    //printf("%d\n", ggT(12, 27));
    //printf("%d\n", ggT(34, 85));
    //printf("%d\n", ggT(31, 2));
    //printf("%d\n", arePrimTwins(3,5)); //-> TRUE
    //printf("%d\n", arePrimTwins(71,73)); //-> TRUE
    //printf("%d\n", arePrimTwins(41,43)); //-> TRUE
    //printf("%d\n", arePrimTwins(101,150)); //-> FALSE
    //printf("%d\n", arePrimTwins(3,7)); //-> FALSE
    //printf(printPrimTwins(2, 500));
    return 0;
}
 */

