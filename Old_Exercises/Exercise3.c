#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat"
#pragma ide diagnostic ignored "cert-err34-c"
//
// Created by 0x1nbetw33n on 09/05/22.
//

#include <math.h>
#include <stdio.h>
#include "exercise1.h"
#include "Exercise3.h"


double fOfx(double no){return pow(no, 3) - (2 * pow(no, 2)) - no + 2;}

double integral(int leftSide, int rightSide, double stepSize ){
return 0;
}

double hsqrt(double a){
    if(a == 0){
        return a;
    } if(a < 0) {
        return -1;
    } else {
            double epsilon = .000000001;
            //TODO: BULLSHIT - FIX THIS MAYBE
         double xN = (a +1) / 2;
         double xN_1 = xN - ((pow(xN, 2) - a) / 2 * xN);
            return xN_1;
    }
}

int kgV(int no1, int no2){return abs((no1 / ggT(no1, no2)) * no2);}

Rational kuerze(Rational rational){
    int tmpNumerator = rational.numerator;
    rational.numerator = rational.numerator < 0 ? //numerator
            -(abs(rational.numerator) /  ggT(abs(rational.numerator), abs(rational.denominator))) : //numerator is negative
                         abs(rational.numerator) /  ggT(abs(rational.numerator), abs(rational.denominator)); //numerator is positive
    rational.denominator = rational.denominator < 0 ? //denominator
            -(abs(rational.denominator) / ggT(abs(tmpNumerator), abs(rational.denominator))) : //denominator is negative
                           abs(rational.denominator) / ggT(abs(tmpNumerator), abs(rational.denominator)); //denominator is positive
    return rational;
}

Rational addiere(Rational rational1, Rational rational2) {
    Rational result;
    int tmpDenominator1 = rational1.denominator;
    if(abs(rational1.denominator - rational2.denominator) >= .00000001){
        rational1.numerator *= rational2.denominator;
        rational1.denominator *= rational2.denominator;
        rational2.numerator *= tmpDenominator1;
    }
    result.numerator = rational1.numerator + rational2.numerator;
    result.denominator = rational1.denominator;
    return kuerze(result);
}

Rational subtrahiere(Rational rational1, Rational rational2){
    Rational result;
    int tmpDenominator1 = rational1.denominator;
    if(abs(rational1.denominator - rational2.denominator) >= .000000001){
        rational1.numerator *= rational2.denominator;
        rational1.denominator *= rational2.denominator;
        rational2.numerator *= tmpDenominator1;
    }
    result.numerator = rational1.numerator - rational2.numerator;
    result.denominator = rational1.denominator;
    return kuerze(result);
}

Rational multipliziere(Rational rational1, Rational rational2){
    Rational result;
    result.numerator = rational1.numerator * rational2.numerator;
    result.denominator = rational1.denominator * rational2.denominator;
    return kuerze(result);
}

Rational dividiere(Rational rational1, Rational rational2) {
    Rational result;
    result.numerator = rational2.denominator;
    result.denominator = rational2.numerator;
    return kuerze(multipliziere(rational1, result));
}

float toFloat(Rational rational) {return (float) rational.numerator / (float) rational.denominator;}

void ausgabe(char description[], Rational rational){printf("%s: %d | %d\n", description, rational.numerator, rational.denominator);}

void printRGB(RGB rgb){printf("%d\n%d\n%d\n", rgb.R, rgb.G, rgb.B);}

int testHeron() {
    double a;
    printf("Enter a double value for n\n");
    scanf("%f", &a);
    printf("sqrt(a): %f | hsqrt(a): %f", sqrt(a), hsqrt(a)); //TODO: FIND OUT WHY BOTH OF THEM DOESNT WORK
}

int testKGV() {
    int no1;
    int no2;
    printf("Enter 1. number\n");
    scanf("%d", &no1);
    printf("Enter 2. number\n");
    scanf("%d", &no2);
    printf("kgV(%d, %d): %d \n", no1, no2, kgV(no1, no2));
    printf("no1: %d | no2: %d\n", kgV(no1, no2)); //TODO: FIND OUT WHY THIS PRINTS THE SAME VALUE AS POSITIVE AND NEGATIVE VALUE
}

int testRationalFunctions() {
    Rational rational1;
    Rational rational2;
    printf("Enter an integer value for rational1.numerator\n");
    scanf("%d", &rational1.numerator);
    printf("Enter an integer value for rational1.denominator\n");
    scanf("%d", &rational1.denominator);
    printf("Enter an integer value for rational2.numerator\n");
    scanf("%d", &rational2.numerator);
    printf("Enter an integer value for rational2.denominator\n");
    scanf("%d", &rational2.denominator);
    ausgabe("1. shortened fraction",kuerze(rational1));
    ausgabe("2. shortened fraction", kuerze(rational2));
    ausgabe("addElement", addiere(rational1, rational2));
    ausgabe("subtract", subtrahiere(rational1, rational2));
    ausgabe("multiply", multipliziere(rational1, rational2));
    ausgabe("divide", dividiere(rational1, rational2));
    float float1 = toFloat(rational1);
    float float2 = toFloat(rational2);
    printf("1. fraction to float: %f\n", float1);
    printf("2. fraction to float: %f\n", float2);
    return 0;
}

int testRGB(){
    RGB rgb;
    printf("Enter an unsigned char value for R\n");
    scanf("%d", &rgb.R);
    printf("Enter an unsigned char value for B\n");
    scanf("%d", &rgb.G);
    printf("Enter an unsigned char value for G\n");
    scanf("%d", &rgb.B);
    printRGB(rgb);
    return 0;
}

int testUnsignedIntRGB(){
    unsignedIntRGB rgb;
    printf("Enter an unsigned char value for R\n");
    scanf("%u", &rgb.R);
    printf("%u\n", rgb.R);
    printf("Enter an unsigned char value for B\n");
    scanf("%u", &rgb.G);
    printf("%u\n", rgb.G);
    printf("Enter an unsigned char value for G\n");
    scanf("%u", &rgb.B);
    printf("%u\n",rgb.B);
    return 0;
}

/*
 int main(){
    //testHeron();
    //testKGV();
    //testRationalFunctions();
    //testRGB();
    //testUnsignedIntRGB();
}
*/
#pragma clang diagnostic pop