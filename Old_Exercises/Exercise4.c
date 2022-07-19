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
        if(no <= 0){
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

int* fillMatrix(size_t i, size_t j){
    size_t totalSize = i * j;
    int* genericMatrix = (int*) malloc(totalSize * sizeof(int));
    for (int i = 0; i < totalSize; i++) {
        genericMatrix[i] = i +1;
    }
    return genericMatrix;
}

int printMatrix(int* matrix, size_t i, size_t j){
    size_t totalSize = i * j;
    int index = 0;
    int limit = i;
    while(index < totalSize) {
        if (index < limit) {
            if (matrix[index] < 10) { printf("00%d\t\t", matrix[index++]); }
            else if (matrix[index] < 100) { printf("0%d\t\t", matrix[index++]); }
            else { printf("%d\t\t", matrix[index++]); }
        }else{
            printf("\n");
            limit += i;
        }
    }
    return 0;
}


int* multiply(int* A, int* B, int n){
    size_t totalSize = n * n;
    int* R = (int*) malloc(totalSize * sizeof(int));
    int indexA,
          indexB,
          indexR = 0,
          indexALimit = n,
          indexBStart = 0;
    while(indexR < totalSize){
        while(indexB < totalSize){
            while(indexA < indexALimit){
                R[indexR] += A[indexA] * B[indexB];
                indexA++;
                indexB += n;
            }
            indexA = indexALimit - n;
            indexB = ++indexBStart;
            indexR++;
        }
        indexALimit += n;
        indexA += n;
        indexB = 0;
        indexBStart = 0;
    }
    return R;
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
    size_t rows = 10;
    size_t columns = 10;
/*
    printf("Enter no of rows\n");
    scanf("%zd", &rows);
    printf("Enter no of columns\n");
    scanf("%zd", &columns);
*/
    int* genericMatrix = fillMatrix(rows, columns);
    printMatrix(genericMatrix, rows, columns);
    free(genericMatrix);
}


int testMultiply(){
    size_t size = 3;

    int* matrixA = fillMatrix(size, size);
    int* matrixB = fillMatrix(size, size);
    int* result = multiply(matrixA, matrixB, size);
    printMatrix(result, size, size);
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

/*int main(){
    //testCreateArray();
    //testToBinaryString();
    //testFillMatrix();
    testMultiply();
   // testPalindrome();
}
   */



