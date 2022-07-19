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
    printf("%dx² + %dx + %d = 0", a, b, c);
    //code here for solving quadratic equation
}


void ex2_test_solve_quadratic_equation() {
    ex2_solve_quadratic_equation();
}

void ex2_main(void) {
    ex2_print_sizeof();
    ex2_print_numbers(125, -39);
    ex2_op(73.3f);
    ex2_test_solve_quadratic_equation();
}
