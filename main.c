// Zoe Valladares - pink-hat-hacker 9/5/2022
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

//node creatiom in main.h

//inserting node at the front
void addFront(struct  Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeOf(struct Node));
    newNode -> data = data;
    newNode -> next = (*head);
    newNode -> prev = NULL;

    if((*head) != NULL){
        (*head) -> prev = newNode;
    }
    (*head) = newNode;
}

//insert after a specific place
void addAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("error cannot be null");
        return;
    }
    //allocate space for new nodde
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;

    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

//inster a new node at the end
void addEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node* temp = *head;

    if (*head == NULL){
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while (temp->next != NULL){
        temp = temp-> next;
    }
}

//main
/**
 * Case 1
 * - add student to list
 * - will prompt for fname, lname, ID, curryear, gradyear
 * - will add to the end of the list
 * Case 2
 * - delete students
 * - will ask for lname
 * - deletes all instances of that lname
 * Case 3
 * - print list from beginning to end
 * Case 4
 * - print list from end to beginning
 * Case 5
 * - exit
 * - When exiting the program, free all dynamically allocated memory to leave no memory leak.
*/