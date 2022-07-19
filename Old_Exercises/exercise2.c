//
// Created by 0x1nbetw33n on 25/04/22.
//

#include <stdio.h>
#include <math.h>
#include "exercise1.h"
#include "mathemat.h"

Rational addBruch(Rational fraction1, Rational fraction2){
    Rational result;
    int tmpResult;
    int tmp1 = fraction1.denominator;
    int tmp2 = fraction2.denominator;
    if(abs(fraction1.denominator - fraction2.denominator) >= .0000001){
        fraction1.numerator *= tmp2;
        fraction1.denominator *= tmp2;
        fraction2.numerator *= tmp1;
        fraction2.denominator *= tmp1;
    }
    result.numerator = fraction1.numerator + fraction2.numerator;
    result.denominator = fraction1.denominator;
    tmpResult = result.numerator;
    result.numerator /= ggT(tmpResult, result.denominator);
    result.denominator /= ggT(tmpResult, result.denominator);
    return result;
}

int printQuadraticEquation(){
    int p;
    int q;
    printf("Enter p");
    scanf("%d", &p);
    printf("Enter q");
    scanf("%d", &q);
    if(0 > (- (p / 2) + pow((pow((p / 2), 2) - q), .5)), (+ (p / 2) + pow((pow((p / 2), 2) - q), .5))) {
        return -1;
    }
    printf("%f || %f\n", (- (p / 2) + pow((pow((p / 2), 2) - q), .5)), (+ (p / 2) + pow((pow((p / 2), 2) - q), .5)));
    return 0;
}

float quadrat(float no){
    counter();
    return pow(no, 2);
}

int xMod3(float no){
    counter();
    return ((int) rounding2(no)) % 3;
}

int op(float x){
    printf("%.2f\n", pow(x, 2));
    printf("%i\n", ((int) rounding2(x))% 3);
    printf("%f\n", pow(x, .5));
    printf("%f\n", (5 * x) / (7 * (x - 1.5)));
    printf("%0x\n", (((int) rounding2(x)) << 2));
    printf("%0x\n", (((int) rounding2(x)) & 0x00F0));
    printf("%0f\n", x++);
    printf("%0f\n", ++x);
}
/*
int main(int argc, char* argv[]){
    printf("%lu\n", sizeof(char));
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(float));
    printf("%lu\n", sizeof(double));
    int a = 125,
    b = -39;
    printf("%c | %c\n", a, b);
    printf("%u | %u\n", a, b);
    printf("%0x | %0x\n", a, b);
    printf("%d | %i\n", a, b);
    printf("%.2f | %.2f\n", a, b);
    printf("%E | %E\n", a, b);
    printQuadraticEquation();
    op(7.f);
    Rational fraction1;
    Rational fraction2;
    Rational fraction3;
    fraction1.numerator = 1;
    fraction1.denominator = 3;
    fraction2.numerator = 3;
    fraction2.denominator = 2;
    fraction3.numerator = 2;
    fraction3.denominator = 3;
    printf("%d\n _ \n %d\n\n", addBruch(fraction1, fraction2).numerator, addBruch(fraction1, fraction2).denominator);
    printf("%d\n _ \n %d\n\n", addBruch(fraction1, fraction3).numerator, addBruch(fraction1, fraction3).denominator);
    float af = .1f + .1f + .1f + .1f + .1f + .1f + .1f + .1f + .1f + .1f;
    float bf = 10 * .1f;
    printf("%.10f\n", a);
    printf("%.10f\n", b);
    printf("counter: %i\n", showCounter());
    printf("%f\n", quadrat(4));
    printf("counter: %i\n", showCounter());
    printf("%i\n", xMod3(11));
    printf("counter: %i\n", showCounter());
}
*/

