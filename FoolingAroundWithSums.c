//
// Created by 0x1nbetw33n on 09/05/22.
//

#include <stdio.h>


int calculatePartialSums(int n){
    int* partialSums[n];
    for (int i = 0; i < n; ++i) {
        partialSums[i] = (int)((i -2) * (i +1) * (i / 2.));
        printf(" Sum no %d : %d\n", i, partialSums[i]);
    }
    return 0;
}

/*
 * int main(){
    calculatePartialSums(10);
}
 */