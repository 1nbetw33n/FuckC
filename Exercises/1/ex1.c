// copyright (c) 2022 1nbetw33n Labs
// Virgo Supercluster, Milky Way - Earth A-6847
// All rights reserved
//
// This software is the confidential and proprietary information of
// 1nbetw33n Labs. ("Confidential Information"). You shall not disclose
// such Confidential Information and shall use it only in accordance
// with the terms of the license agreement you entered into with
// 1nbetw33n Labs.

#include <stdio.h>
#include <stdlib.h>

/*
  * Created by 0x1nbetw33n on 19/07/22
  * Virgo Supercluster, Milky Way - Earth A-6847
  */

void helloWorld() {
    printf("Hello World!\n");
}

double ex1_sum(double term1, double term2) {
    return term1 + term2;
}

double ex1_difference(double term1, double term2) {
    return term1 - term2;
}

double ex1_product(double factor1, double factor2) {
    return factor1 * factor2;
}

double ex1_quotient(double dividend, double divisor) {
    return dividend / divisor;
}

int ex1_rounding(double no) {
    return (int) (no + .5);
}

double ex1_min2(double no1, double no2){
    return no1 - no2 < .000001 ? no1 : no2;
}

double ex1_max2(double no1, double no2){
    return no1 - no2 < .000001 ? no2 : no1;
}

double ex1_min3(double no1, double no2, double no3){
    return ex1_min2(ex1_min2(no1, no2), no3);
}

double ex1_max3(double no1, double no2, double no3){
    return ex1_max2(ex1_max2(no1, no2), no3);
}

//greatest common divisor of two ints
int ex1_gcd2(int no1, int no2) {
    int temp;
    while (no2 != 0) {
        temp = no2;
        no2 = no1 % no2;
        no1 = temp;
    }
    return no1;
}

//greatest common divisor of 3 ints
int ex1_gcd3(int no1, int no2, int no3) {
    return ex1_gcd2(ex1_gcd2(no1, no2), no3);
}

//checks if int is prime
int ex1_isPrime(int possiblePrim) {
    for (int i = 2; i < possiblePrim; i++) {
        if (ex1_gcd2(possiblePrim, i) != 1) {
            return 0;
        }
    }
    return 1;
}

//checks if two ints are prime twins
int ex1_arePrimeTwins(int prim1, int prim2) {
    return abs(prim1 - prim2) == 2;
}


//prints all prime twins between two ints
void ex1_printPrimeTwins(int min, int max) {
    for (int i = min; i <= max; i++) {
        for (int j = i + 1; j <= max; j++) {
            if(ex1_isPrime(i) && ex1_isPrime(j) && ex1_arePrimeTwins(i, j)){
                printf("%d %d\n", i, j);
            }
        }
    }
}

void ex1_testSum() {
    printf("sum(%f, %f) = %f\n", 1.1, 2.2, ex1_sum(1.1, 2.2));
    printf("sum(%f, %f) = %f\n", -1.1, 2.2, ex1_sum(-1.1, 2.2));
}


void ex1_testDifference() {
    printf("difference(%f, %f) = %f\n", 1.1, 2.2, ex1_difference(1.1, 2.2));
    printf("difference(%f, %f) = %f\n", -1.1, 2.2, ex1_difference(-1.1, 2.2));
}

void ex1_testProduct() {
    printf("product(%f, %f) = %f\n", 1.1, 2.2, ex1_product(1.1, 2.2));
    printf("product(%f, %f) = %f\n", -1.1, 2.2, ex1_product(-1.1, 2.2));

}

void ex1_testQuotient() {
    printf("quotient(%f, %f) = %f\n", 1.1, 2.2, ex1_quotient(1.1, 2.2));
    printf("quotient(%f, %f) = %f\n", -1.1, 2.2, ex1_quotient(-1.1, 2.2));

}

void ex1_testRounding() {
    printf("rounding(%f) -> %d\n", 1.1, ex1_rounding(1.1));
    printf("rounding(%f) -> %d\n", -1.1, ex1_rounding(-1.1));
    printf("rounding(%f) -> %d\n", 1.5, ex1_rounding(1.5));

}


void ex1_testMin2() {
    printf("min2(%f, %f) -> %f\n", 1.1, 2.2, ex1_min2(1.1, 2.2));
    printf("min2(%f, %f) -> %f\n", 2.2, 1.1, ex1_min2(2.2, 1.1));
    printf("min2(%f, %f) -> %f\n", 1.1, -1.1, ex1_min2(1.1, -1.1));
}

void ex1_testMax2() {
    printf("max2(%f, %f) -> %f\n", 1.1, 2.2, ex1_max2(1.1, 2.2));
    printf("max2(%f, %f) -> %f\n", 2.2, 1.1, ex1_max2(2.2, 1.1));
    printf("max2(%f, %f) -> %f\n", 1.1, -1.1, ex1_max2(1.1, -1.1));
}

void ex1_testMin3() {
    printf("min3(%f, %f) -> %f\n", 1.1, 2.2, 3.3, ex1_min3(1.1, 2.2, 3.3));
    printf("min3(%f, %f) -> %f\n", 2.2, 1.1, 3.3, ex1_min3(2.2, 1.1, 3.3));
    printf("min3(%f, %f) -> %f\n", 1.1, -1.1, -3.3, ex1_min3(1.1, -1.1, -3.3));
    printf("min3(%f, %f) -> %f\n", 1.1, 2.2, -1.1, ex1_min3(1.1, 2.2, -1.1));
}

void ex1_testMax3() {
    printf("max3(%f, %f) -> %f\n", 1.1, 2.2, 3.3, ex1_max3(1.1, 2.2, 3.3));
    printf("max3(%f, %f) -> %f\n", 2.2, 1.1, 3.3, ex1_max3(2.2, 1.1, 3.3));
    printf("max3(%f, %f) -> %f\n", 1.1, -1.1, -3.3, ex1_max3(1.1, -1.1, -3.3));
    printf("max3(%f, %f) -> %f\n", 1.1, 2.2, -1.1, ex1_max3(1.1, 2.2, -1.1));
}

//test gcd
void ex1_testGcd2() {
    printf("gcd(%d, %d) -> %d\n", 12, 18, ex1_gcd2(12, 18));
    printf("gcd(%d, %d) -> %d\n", 12, 27, ex1_gcd2(12, 27));
    printf("gcd(%d, %d) -> %d\n", 34, 85, ex1_gcd2(34, 85));
    printf("gcd(%d, %d) -> %d\n", 31, 2, ex1_gcd2(31, 2));
}

void ex1_testGcd3() {
    printf("gcd(%d, %d, %d) -> %d\n", 12, 18, 27, ex1_gcd3(12, 18, 27));
    printf("gcd(%d, %d, %d) -> %d\n", 12, 27, 13, ex1_gcd3(12, 27, 18));
    printf("gcd(%d, %d, %d) -> %d\n", 34, 85, 31, ex1_gcd3(34, 85, 31));
    printf("gcd(%d, %d, %d) -> %d\n", 31, 2, 34, ex1_gcd3(31, 2, 34));

}

void ex1_testIsPrime() {
    printf("%d is prime -> %d\n", 2, ex1_isPrime(2));
    printf("%d is prime -> %d\n", 3, ex1_isPrime(3));
    printf("%d is prime -> %d\n", 4, ex1_isPrime(4));
    printf("%d is prime -> %d\n", 5, ex1_isPrime(5));
    printf("%d is prime -> %d\n", 6, ex1_isPrime(6));
    printf("%d is prime -> %d\n", 7, ex1_isPrime(7));
    printf("%d is prime -> %d\n", 8, ex1_isPrime(8));
    printf("%d is prime -> %d\n", 9, ex1_isPrime(9));
    printf("%d is prime -> %d\n", 10, ex1_isPrime(10));
    printf("%d is prime -> %d\n", 11, ex1_isPrime(11));
    printf("%d is prime -> %d\n", 12, ex1_isPrime(12));
    printf("%d is prime -> %d\n", 13, ex1_isPrime(13));
    printf("%d is prime -> %d\n", 14, ex1_isPrime(14));
    printf("%d is prime -> %d\n", 15, ex1_isPrime(15));
    printf("%d is prime -> %d\n", 16, ex1_isPrime(16));
    printf("%d is prime -> %d\n", 17, ex1_isPrime(17));
    printf("%d is prime -> %d\n", 18, ex1_isPrime(18));
    printf("%d is prime -> %d\n", 19, ex1_isPrime(19));
    printf("%d is prime -> %d\n", 20, ex1_isPrime(20));
    printf("%d is prime -> %d\n", 21, ex1_isPrime(21));
    printf("%d is prime -> %d\n", 22, ex1_isPrime(22));
}

void ex1_testArePrimeTwins() {
    printf("%d and %d are prime twins -> %d\n", 3, 5, ex1_arePrimeTwins(3, 5));
    printf("%d and %d are prime twins -> %d\n", 71, 73, ex1_arePrimeTwins(71, 73));
    printf("%d and %d are prime twins -> %d\n", 41, 43, ex1_arePrimeTwins(41, 43));
    printf("%d and %d are prime twins -> %d\n", 2, 3, ex1_arePrimeTwins(2, 3));
    printf("%d and %d are prime twins -> %d\n", 7, 13, ex1_arePrimeTwins(7, 13));
}

void ex1_testPrintPrimeTwins() {
    ex1_printPrimeTwins(3, 500);
}


void ex1_main(void){
    helloWorld();
    ex1_testSum();
    ex1_testDifference();
    ex1_testProduct();
    ex1_testQuotient();
    ex1_testRounding();
    ex1_testMin2();
    ex1_testMax2();
    ex1_testMin3();
    ex1_testMax3();
    ex1_testGcd2();
    ex1_testGcd3();
    ex1_testIsPrime();
    ex1_testArePrimeTwins();
    ex1_testPrintPrimeTwins();
}