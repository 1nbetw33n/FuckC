//
// Created by 0x1nbetw33n on 25/05/22.
//

#include "ArrayList.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int"

//ALLOCATES MEMORY
/*
 * USAGE:
 *  ArrayList * list = createArrayList();
 */
ArrayList * createArrayList(){
    ArrayList * list = malloc(sizeof(list));
    if(list == NULL){
        return NULL;
    } else {
        list->size = 0;
        list->data = calloc(0, sizeof(void *));
        if(list->data == NULL){
            free(list);
            return NULL;
        }
        return list;
    }
}

//CLEARS INTERNAL ARRAY
clear(ArrayList * list){
    list->data = 0;
    free(list->data);
    list->data = NULL;
    return 0;
}

//SETS INTERNAL ARRAY
setData(ArrayList * list, void ** data, int max, int clearData){
    clearData ? clear(list) : NULL;
    list->data = data;
    list->size = max;
}

void * get(ArrayList * list, int index){return list->data[index];}

//SEARCHES FOR element IN list - IF FOUND: RETURN ELEMENT; ELSE: RETURNS -1
getPosition(ArrayList * list, void * element){
    for (int i = 0; i < list->size; i++) {
        if(element == get(list, i)){
            return i;
        }
        return -1;
    }
}

//RETURNS MEMORY SIZE OF INTERNAL ARRAY
size_t getSizeOf(ArrayList * list){return sizeof(*list->data);}

//RETURNS NO OF ELEMENTS IN INTERNAL ARRAY
size_t getArrayListSize(ArrayList * list){return list->size;}

//ADDS 1 GENERIC POINTER ELEMENT TO INTERNAL ARRAY
addElementToArrayList(ArrayList * list, void * element){
    void ** newData = realloc(list->data, getSizeOf(list));
    assert(newData != NULL);
    newData[list->size] = element;
    setData(list, newData, list->size + 1, 0);
}

//REMOVES 1 ELEMENT AT index
removeElement(ArrayList * list, int index, int freeIt){
    if(index > list->size -1){
        return -1;
    } if(list->size == 0){
        return -1;
    }
    if(freeIt){
        free(get(list, index));
    }
    for (int i = index; i < list->size; i++) {
        if(i == list->size -1){
            list->data[i] = NULL;
        } else {
            list->data[i] = list->data[i + 1];
        }
        void ** newData = realloc(list->data, getSizeOf(list));
        --list->size;
        assert(newData != NULL);
        setData(list, newData, list->size, 0);
        return 0;
    }
}

//DEALLOCATES THE INTERNAL ARRAY
//NO FURTHER USAGE ALLOWED AFTER FUNCTION CALL
destroy(ArrayList * list){
        free(list->data);
        free(list);
    return 0;
}

//PRINT FOR INTEGER ARRAYLIST
printIntArray(ArrayList * integerList){
    for(int i = 0; i < integerList->size; i++){
    printf("%d | ", integerList->data[i]);
    }
}

testArrayList(){
    ArrayList * list = createArrayList();
    void * element;
    for (int i = 0; i < 10; i++) {
        printf("Enter an int // -.- FUCK C -.-\n");
        scanf("%d", &element);
        addElementToArrayList(list,  element);
    }
    printIntArray(list);

}
/*
int main(){
    testArrayList();
}
 */
#pragma clang diagnostic pop