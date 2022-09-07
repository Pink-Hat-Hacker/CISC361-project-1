// Zoe Valladares - pink-hat-hacker 9/5/2022
//#include "main.h"
#include <stdio.h>
#include <stdlib.h>

//node creatiom in main.h

//inserting node at the front
// void addFront(struct  Node** head, int data){
//     struct Node* newNode = (struct Node*)malloc(sizeOf(struct Node));
//     newNode -> data = data;
//     newNode -> next = (*head);
//     newNode -> prev = NULL;

//     if((*head) != NULL){
//         (*head) -> prev = newNode;
//     }
//     (*head) = newNode;
// }

// //insert after a specific place
// void addAfter(struct Node* prevNode, int data) {
//     if (prevNode == NULL) {
//         printf("error cannot be null");
//         return;
//     }
//     //allocate space for new nodde
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = prevNode->next;
//     prevNode->next = newNode;
//     newNode->prev = prevNode;

//     if (newNode->next != NULL) {
//         newNode->next->prev = newNode;
//     }
// }

// //inster a new node at the end
// void addEnd(struct Node** head, int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     struct Node* temp = *head;

//     if (*head == NULL){
//         newNode->prev = NULL;
//         *head = newNode;
//         return;
//     }

//     while (temp->next != NULL){
//         temp = temp-> next;
//     }
// }

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

int main() {
    int i;
    // struct student *newStudent;
    // struct node *n;
    // head = NULL;
    while (1) {
        //print cases
        printf("\nList of possible actions:\n");
        printf("1. Add student to the list\n");
        printf("2. Delete student(s) from the list\n");
        printf("3. Print list - Top to Bottom\n");
        printf("4. Print list - Bottom to Top\n");
        printf("5. Exit\n");
        printf("Enter choice NUMBER: ");
        //scan for number
        if (scanf("%d", &i) <= 0) {
            printf("Error! Only Integer");
            //main();
            exit(0);
        } else {
            //printf("else");
	    //break;
	    switch (i) {
		    case 1:
			    printf("add student");
			    break;
		    case 2:
			    printf("delete student");
			    break;
		    case 3:
			    printf("top to bottom");
		    	    break;
		    case 4:
			    printf("bottom to top");
			    break;
		    case 5:
			    return 0;
	    }
        }
    }
}

/**
 * Notes from class:
 * - makefile
 * - gcc -g
 * - put everything in one executable
 * - EX:
 * --- list: main.c list.h list.c
 * --- gcc -g main.c list.c -o list
 * - Clean up
 * 
 * - comments:
 * --- for functions
 * --- what it does, inputs, returns
 * --- does it modify
*/
