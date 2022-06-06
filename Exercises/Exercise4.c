//
// Created by 0x1nbetw33n on 25/05/22.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ArrayList.h"


int* createArray(){
    const size_t LENGTH = 10;
    int *genericIntArray = (int*) malloc(LENGTH * sizeof(int));
    for (int i = 0; i <LENGTH; i++) {
        genericIntArray[i] = i + 1;
    }
    return genericIntArray;
}

char* toBinaryString(int integer){
    if(integer <= 0){
        return (char *) -1;
    }
    const size_t LENGTH = 32;
    char *binaryStringPtr;
    char binaryString[LENGTH];
    binaryStringPtr = binaryString;
    int zeroCounter = 0;
    //DECIMAL -> BINARY (LEAST SIGNIFICANT BIT STORED AT LAST INDEX ETC.)
    for (int i = LENGTH - 1; i > 0; i--) {
        if(!(integer > 0)){
            //COUNTS LEADING ZEROS
            zeroCounter = i +1;
            break;
        }
        binaryString[i] = integer % 2;;
        integer /= 2;
    }
    char *binaryStringWithoutLeadingZerosPtr;
    char binaryStringWithoutLeadingZeros[LENGTH - zeroCounter];
    binaryStringWithoutLeadingZerosPtr = binaryStringWithoutLeadingZeros;
    //REMOVES LEADING ZEROs
    for (int i = zeroCounter; i < sizeof(binaryStringWithoutLeadingZeros); i++) {
        binaryStringWithoutLeadingZeros [i - zeroCounter] = binaryString[i];
    }
    return binaryStringWithoutLeadingZerosPtr;
}

int* multiply(int** A, int** B, int n){
    int matrixA[n][n];
    for (int i = 0; i < sizeof(A); i++) {
        for (int j = 0; j < sizeof(A) ; ++j) {
            A[i][j] += A[i][j] * B[i][j];
        }
    }
    return A;
}

int* fillMatrix(int matrix[][3]){
    int counter = 0;
    for (int i = 0; i < sizeof(matrix); i++) {
        for (int j = 0; j < sizeof(matrix) ; ++j) {
            matrix[i][j] = ++counter;
        }
    }
}

void printMatrix(int* matrix[]){
    for (int i = 0; i < sizeof(matrix); i++) {
        for (int j = 0; j < sizeof(matrix) ; ++j) {
            int columnIndexCounter = 0;
            if(columnIndexCounter < sizeof(matrix[0])){
                printf("%d | ", matrix[i][j]);
            } else {
                printf("%d\n", matrix[i][j]);
            }
        }
    }
}

int checkIfPalindrome(char* string){
    for (int i = 0, reverseCounter = sizeof(string); i < sizeof(string); i++) {
        if (string[i] != string[--reverseCounter]){
            return -1;
        }
    }
}

int testCreateArray(){
    const size_t LENGTH = 10;
    for (int i = 0; i < LENGTH; i++) {
        printf("%d\n", createArray()[i]);
    }
    return 0;
}

int testToBinaryString(){
    const size_t LENGTH = sizeof(toBinaryString(17));
    for (int i = 0; i < LENGTH; i++) {
        printf("%d | ", toBinaryString(17)[i]);
    }
    return 0;
}

int testMatrix(){
    int* matrix[3];
    fillMatrix(matrix);
    printMatrix(matrix);
    return 0;
}

int testPalindrome(){
    size_t length;
    char character;
    printf("Enter string length\n");
    scanf("%zd\n", &length);
    char* string = (char*) malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        printf("Enter char\n");
        scanf("%c\n", &character);
        string[i] = character;
    }
    checkIfPalindrome(string);
    return 0;
}

/*
int main(){
    //testCreateArray();
    testToBinaryString();
    //testMatrix();
    //testPalindrome();
}
 */


