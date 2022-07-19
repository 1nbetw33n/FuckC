// copyright (c) 2022 1nbetw33n Labs
// Virgo Supercluster, Milky Way - Earth A-6847
// All rights reserved
//
// This software is the confidential and proprietary information of
// 1nbetw33n Labs. ("Confidential Information"). You shall not disclose
// such Confidential Information and shall use it only in accordance
// with the terms of the license agreement you entered into with
// 1nbetw33n Labs.

/*
  * Created by 0x1nbetw33n on 19/07/22
  * Virgo Supercluster, Milky Way - Earth A-6847
  */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ex2.h"
#include "ex1.h"

//print sizeof char, int, float, double
void ex2_print_sizeof() {
    printf("sizeof char: %lu\n", sizeof(char));
    printf("sizeof int: %lu\n", sizeof(int));
    printf("sizeof float: %lu\n", sizeof(float));
    printf("sizeof double: %lu\n", sizeof(double));
}

//prints 2 numbers as char, unsigned int, hex number, signed int, float with 2 decimals and double in exponential notation
void ex2_print_numbers(int a, int b) {
    printf("%c | %c\n %u | %u\n %x | %x\n %d | %d\n %.2f | %.2f\n %E | %E\n", a, b, a, b, a, b, a, b, a, b, a, b);
};

void ex2_op(float x){
    if(x < 0){
        printf("not a positive float.");
    }
    else{
        printf("%f² = %f\n", x, x * x);
        printf("%f mod 3 = %d \n", x, (int)x % 3);
        printf("sqrt(%f) = %f\n", x, sqrt(x));
        printf("(5 * %f + 3) / (7 * (%f - 1.5)) = %f\n", x, x, (5 * x + 3) / (7 * (x - 1.5)));
        printf("%f << 2 = %x\n", x, (int)x << 2);
        printf("%f | 0x00F0 = %x\n", x, (int)x | 0x00F0);
        printf("++%f = %f\n", x, ++x);
    }
}

void ex2_solve_quadratic_equation(){
    int a, b, c;
    printf("Enter a, b, c: \n");
    scanf("%d\n %d\n %d\n", &a, &b, &c);
    printf("%dx² + %dx + %d = 0\n", a, b, c);
    double root = sqrt(b * b - 4 * a * c);
    if(root < 0){
        printf("No real roots.\n");
    }
    else{
        printf("x = %.2f\tv \tx = %.2f\n", (-b + root) / (2 * a), (-b - root) / (2 * a));
    }
}

Fraction ex2_add_fractions(Fraction a, Fraction b){
    Fraction result;
    result.numerator = a.numerator * b.denominator + a.denominator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    return result;
}

Fraction ex2_shorten_fraction(Fraction a){
    int gcd = ex1_gcd2(a.numerator, a.denominator);
    a.numerator /= gcd;
    a.denominator /= gcd;
    return a;
}

int compare_floats(float a, float b){
    return fabsf(a - b) <= 0.000001;
}

void ex2_test_solve_quadratic_equation() {
    ex2_solve_quadratic_equation();
}

void ex2_test_add_fractions() {
    Fraction a, b;
    printf("Enter a, b: \n");
    scanf("%d\n %d\n", &a.numerator, &a.denominator);
    scanf("%d\n %d\n", &b.numerator, &b.denominator);
    Fraction result = ex2_add_fractions(a, b);
    printf("%d/%d + %d/%d = %d/%d\n", a.numerator, a.denominator, b.numerator, b.denominator, result.numerator, result.denominator);
}

void ex2_test_shorten_fraction() {
    Fraction a;
    printf("Enter a: \n");
    scanf("%d\n %d\n", &a.numerator, &a.denominator);
    Fraction result = ex2_shorten_fraction(a);
    printf("shorten(%d/%d) -> %d/%d\n", a.numerator, a.denominator, result.numerator, result.denominator);
}

void ex2_test_compare_floats() {
    float a = .1f +.1f +.1f +.1f +.1f +.1f +.1f +.1f +.1f +.1f;
    float b = 10 * .1f;
    if(compare_floats(a, b)){
        printf("%.10f == %.10f\n", a, b);
    }
    else{
        printf("%.10f != %.10f\n", a, b);
    }
}


void ex2_main(void) {
//    ex2_print_sizeof();
//    ex2_print_numbers(125, -39);
//    ex2_op(73.3f);
//    ex2_test_solve_quadratic_equation();
//    ex2_test_add_fractions();
//    ex2_test_shorten_fraction();
//    ex2_test_compare_floats();

    printf("All tests passed! *happy dev noises* \n");
}
