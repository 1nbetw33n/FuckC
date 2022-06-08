//
// Created by 0x1nbetw33n on 25/05/22.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* C IS SO EXTREMELY FUCKED UP */
static size_t binaryStringWithoutLeadingZerosLength;

int* createArray(){
    const size_t LENGTH = 10;
    int* genericIntArray = (int*) malloc(LENGTH * sizeof(int));
    for (int i = 0; i <LENGTH; i++) {
        genericIntArray[i] = i + 1;
    }
    return genericIntArray;
}

char* toBinaryString(int no){
    if(no <= 0){
        return (char*) -1;
    }
    const size_t LENGTH = 32;
    char* binaryString = (char*) malloc((sizeof(char) * LENGTH));;
    int zeroCounter = 0;
    //DECIMAL -> BINARY (LEAST SIGNIFICANT BIT STORED AT LAST INDEX ETC.)
    for (int i = LENGTH - 1; i > 0; i--) {
        if(!(no > 0)){
            //COUNTS LEADING ZEROS
            zeroCounter = i + 1;
            break;
        }
        binaryString[i] = no % 2;;
        no /= 2;
    }
    binaryStringWithoutLeadingZerosLength = LENGTH - zeroCounter;
    char* binaryStringWithoutLeadingZeros = (char*) malloc(sizeof(char) * (binaryStringWithoutLeadingZerosLength));
    //REMOVES LEADING ZEROs
    for (int i = zeroCounter; i < LENGTH; i++) {
        binaryStringWithoutLeadingZeros [i - zeroCounter] = binaryString[i];
    }
    return binaryStringWithoutLeadingZeros;
}

/*
int* multiply(int* A, int* B, int n){
    for (int i = 0; i < sizeof(A); i++) {
        for (int j = 0; j < sizeof(A) ; ++j) {
            A[i][j] += A[i][j] * B[i][j];
        }
    }
    return A;
}
*/
int* fillMatrix(size_t size){
    int counter = 0;
    int* matrix[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = (int*) malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size ; j++) {
            matrix[i][j] = ++counter;
        }
    }
    return matrix;
}

int printMatrix(int** matrix, size_t size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++){
            if(j < size - 1){
                if(matrix[i][j] < 10){printf("0%d\t", matrix[i][j]);}
                else{printf("%d\t", matrix[i][j]);}
            }else{
                if(matrix[i][j] < 10){printf("0%d\n", matrix[i][j]);}
                else{printf("%d\n", matrix[i][j]);}
            }
        }
    }
    return 0;
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
    int no;
    printf("Enter decimal number\n");
    scanf("%d", &no);
    char* binaryString = toBinaryString(no);
    printf("| ");
    for (int i = 0; i < binaryStringWithoutLeadingZerosLength; i++) {
        printf("%d | ", binaryString[i]);
    }
    free(binaryString);
    return 0;
}

int testFillMatrix() {
size_t size = 4;
/*
    printf("Enter matrix' size\n");
    scanf("%zd", &size);
    */
    int* genericMatrix = fillMatrix(size);
    printMatrix(genericMatrix, size);
}
/*
int testMatrix(){
    int* matrix[3];
    fillMatrix(matrix);
    printMatrix(matrix, size);
    return 0;
}
*/
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


int main(){
    //testCreateArray();
    //testToBinaryString();
    testFillMatrix();
    //testMatrix();
   // testPalindrome();
}


