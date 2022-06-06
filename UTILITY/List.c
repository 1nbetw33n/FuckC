//
// Created by 0x1nbetw33n on 26/05/22.
//

#include <stdlib.h>
#include <stdio.h>
#include "List.h"


size_t getSize(List * list){return list->size;}

List* getElementAt(List* list, int index){return list->data[index];}

List* newList(){
    List * list = (void*) malloc(getSize(list) * sizeof(list));
    list->size = 0;
    list->data = calloc(0, sizeof(void*));
    return list;
}

addElement(List* list, void* element){
    //CREATES A NEW LIST WITH 1 ELEMENT MORE THAN THE PREVIOUS ONE
    List * newList = (void*) malloc((getSize(list) + 1)* sizeof(list));
    //COPIES EVERY ELEMENT OF list TO newList
    for(int i = 0; i < newList->size; i++){
        newList->data[i] = list->data[i];
    }
    //ADDS THE ELEMENT AT newLists LAST INDEX
    newList->data[newList->size++] = element;
}

printList(List* list){
    for(int i = 0; i < getSize(list); i++){
        printf("%d | ", list->data[i]);
    }
}
testNewList(){
    List* list = newList();
    printList(list);
    void* element;
    printf("Enter value\n");
    scanf("%d\n", &element);
    addElement(list, element);
    printList(list);
}
/*
int main(){
    testNewList();
}
 */