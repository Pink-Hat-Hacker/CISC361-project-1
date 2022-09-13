// Zoe Valladares - pink-hat-hacker 9/5/2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

struct node* addStudent(struct node *head, struct Student *newStudent) {
	struct node * temp;
	if (head == NULL) {
		temp = (struct node *) malloc(sizeof(struct node));
		temp->data = newStudent;
		head = temp;
		head->next = NULL;
		head->prev = NULL;
		return head;
	} else {
		struct node * temp1;
		struct node * temp2;
		temp1 = (struct node *) malloc(sizeof(struct node));
		temp2 = head;
		
		while (temp2->next != NULL) {
			temp2 = temp2->next;
		}

		temp2->next=temp1;
		temp1->prev=temp2;
		temp1->data = newStudent;
		temp1->next = NULL;
		return head;
	}
};

void deleteNode(struct node *toDelete) {
	free(toDelete->data->lname);
	free(toDelete);
};

void deleteStudent() {
	struct node *current = head;
	struct node *next;
	int length;
	char *deleteName;
	char stuTemp[BUFFERSIZE];

	if (head == NULL) {
		return;
	}
	if (fgets(stuTemp, BUFFERSIZE, stdin) != NULL) {
		length = (int) strlen(stuTemp);
		stuTemp[length-1] = '\0';
		deleteName = (char *) malloc(length);
		strcpy(deleteName, stuTemp);
	}
	while (current != NULL) {
		if (strcmp(current->data->lname, deleteName) == 0) {
			next = current->next;
			deleteNode(current);
			current = next;
		} else {
			current = current->next;
		}
	}
	free(deleteName);
}


void printIO(struct node *current) { 
	current = head;
	if (current == NULL) {
		return;
	}

	while (current != NULL) {
		printf("\n");
		printf("Name: %s %s, \nID: %ld, \nCurrent Year: %s", current->data->fname, current->data->lname, current->data->id, current->data->curryear);
	       current = current->next;
	       printf("\n");
	}	       
}
void printRO(struct node *current) {
	current = head;
	if (current == NULL) {
		return;
	}
	struct node *tail = current;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	while(tail != NULL){
		printf("\n");
		printf("Name: %s %s, \nID: %ld, \nCurrent Year: %s", tail->data->fname, tail->data->lname, tail->data->id, tail->data->curryear);
		tail = tail->prev;
		printf("\n");
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

int main() {
    int i;
    struct Student *newStudent;
    // struct node *n;
    head = NULL;
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
            exit(0);
        } else {	
	    newStudent = malloc(sizeof(struct Student));
	    switch (i) {
		    case 1:
			    //printf("add student");			    
			    int length;
			    getchar();

			    printf("Enter student first name: \n");
			    char fnameBuff[BUFFERSIZE];
			    if(fgets(fnameBuff, BUFFERSIZE, stdin) != NULL) {
			    	length = (int) strlen(fnameBuff);
				fnameBuff[length - 1] = '\0';
				newStudent->fname = (char *) malloc(length);
				strcpy(newStudent->fname, fnameBuff);
			    }

			    printf("Enter student last name: \n");
                            char lnameBuff[BUFFERSIZE];
			    if(fgets(lnameBuff, BUFFERSIZE, stdin) != NULL) {
				length = (int) strlen(lnameBuff);
                                lnameBuff[length - 1] = '\0';
                                newStudent->lname = (char *) malloc(length);
                                strcpy(newStudent->lname, lnameBuff);
			    }

			    printf("Enter student ID: \n");
			    long tempID = 0;
			    scanf("%ld", &tempID);
			    newStudent->id = tempID;

			    scanf("%*[^\n]");scanf("%*c");
			    printf("Enter current year: \n");
			    char currYearBuff[BUFFERSIZE];
			    if(fgets(currYearBuff, BUFFERSIZE, stdin) != NULL) {
			    	length = (int) strlen(currYearBuff);
				currYearBuff[length - 1] = '\0';
				newStudent->curryear = (char *) malloc(length);
				strcpy(newStudent->curryear, currYearBuff);
			    }

			    printf("Enter student graduation year: \n");
                            int tempGradYear = 0;
                            scanf("%d", &tempGradYear);
                            newStudent->gradyear = tempGradYear;
			    
			    head=addStudent(head, newStudent);
			    printf("%d\n",head->data->gradyear);
			    break;
		    case 2:
			    getchar();
			    if (head == NULL) {
				    printf("List is Empty\n");
			    } else {
				    printf("Enter the last name of the student to delete: ");
				    deleteStudent();
			    }
			    /*if (head == NULL) {
				    printf("List is Empty\n");
			    } else {
			    	printf("Enter the last name of the student to delete: ");
				char studToDeleteBuffer[BUFFERSIZE];
                                if (fgets(studToDeleteBuffer, BUFFERSIZE, stdin) != NULL) {
					length = (int) strlen(studToDeleteBuffer);
                                        studToDeleteBuffer[length - 1] = '\0';
                                        //printf("%s", studToDeleteBuffer);
				}
				if (delete(studToDeleteBuffer)) {
                                      	printf("%s deleted successfully\n", studToDeleteBuffer);
                                } else {
					printf("%s not found in the list\n", studToDeleteBuffer);
                                }
			    }*/
			    break;
		    case 3:
			    printf("In order print\n");
			    printIO(head);
		    	    break;
		    case 4:
			    printf("Reverse order print\n");
			    printRO(head);
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
