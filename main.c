// Zoe Valladares - pink-hat-hacker 9/5/2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void addStudent(struct Student *newStudent) {
	printf("adding student...");
	int i = 0;
	struct node *temp;
	temp = head;

	if (temp == NULL) {
		add(newStudent);
	} else {
		while (temp != NULL) {
			if(temp->data->lname < newStudent->lname){
				i++;
			}
			temp->prev = temp;
			temp = temp->next;
		}
		if (i == 0) {
			add(newStudent);
		} else if (i < count()){
			addStudentAfter(newStudent, i++);
		} else {
			appendStudent(newStudent);
		}
	}
};

voidd add(struct Student *newStudent) {
	printf("@ add");
	struct node *temp;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = newStudent;
	if (head == NULL) {
		head = temp;
		head->next = NULL;
		head->prev = NULL;
	} else {
		temp->next = NULL;
		temp->prev = head->prev;
		head = temp;
	}
}
void addStudentAfter(struct Student *newStudent, int location) {
	printf("@ add student after");
	struct node *temp;
	struct node *left;
	struct node *right;
	int i;

	right = head;
	for (i = 0; i < location; i++) {
		left = right;
		right = right->next;
	}

	temp = (struct node *) malloc(sizeof(struct node));

	temp->data = newStudent;
	left->next = temp;
	right->prev = temp;
	left = temp;
	left->next = right;
}
void apppend(struct Student *newStudent) {
	printf("@ append");
	struct node *temp;
	struct node *right;
	
	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = newStudent;
	right = (struct node *) head;

	while (right->next != NULL) {
		right = right->next;
	}
	right->next = temp;
	temp->prev = right;
	right = temp;
	right->next = NULL;
}

int count() {
	struct node *n;
	int i = 0;
	n = head;
	while (n != NULL) {
		n = n->next;
		i++;
	}
	return i;
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
            //main();
            exit(0);
        } else {
            //printf("else");
	    //break;
	    switch (i) {
		    case 1:
			    printf("add student");
			    newStudent = malloc(sizeof(struct Student));			    
			    int length;
			    getchar();
			    printf("Enter student first name: \n");
			    char fnameBuff[BUFFERSIZE];
			    printf("Enter student last name: \n");
			    char lnameBuff[BUFFERSIZE];

			    if(fgets(fnameBuff, BUFFERSIZE, stdin) != NULL) {
			    	length = (int) strlen(fnameBuff);
				fnameBuff[length - 1] = '\0';
				newStudent->fname = (char *) malloc(length);
				strcpy(newStudent->fname, fnameBuff);
			    }
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
			    
			    addStudent(newStudent);
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
