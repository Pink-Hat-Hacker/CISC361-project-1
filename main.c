// Zoe Valladares - pink-hat-hacker 9/5/2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * Function: addStudent()
 * Return types: node pointer
 * Params: node pointer to head, Student pointer to newstudent
 * Purpose: add student to the list. base case if head is null and starts the DLL.
 * if head is not null it traverses until the end and adds newStudent.
 */ 
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

/**
 * Fuction: clear()
 * Return type: void
 * Params: none
 * Purpose: frees malloc'd space for each node by traversing the list and freeing the data, data, then the node.
 */
void clear() {
	struct node *current = head;
	while(current != NULL) {
		struct node *next = current->next;
		free(current->data->fname);
		free(current->data->lname);
		free(current->data->curryear);
		free(current->data);
		free(current);
		current = next;
	}
};

/**
 * Function: deleteStudent()
 * Return type: void
 * Params: none
 * Purpose: Prompts user for last name and allocates space for it. traverses the DLL
 * and checks cases head node, first node, middle node, and last node to ensure that deleting 
 * and repointing is done properly
 */
void deleteStudent() {
	char delName[BUFFERSIZE];
	int length;

	printf("Enter the last name of the student to delete: ");
	if (fgets(delName, BUFFERSIZE, stdin) != NULL) {
		length = (int) strlen(delName);
		delName[length - 1] = '\0';
		struct node *temp = head;

		while (temp != NULL) {
			struct node *delete = NULL;
			if (strcmp(temp->data->lname, delName) == 0) {
				delete = temp;
				
				if (temp->prev == NULL && temp->next == NULL) {
					//if prev and next == NULL
					head = NULL;
				} else if (temp->prev == NULL && temp->next != NULL) {
					//fist node
					head = temp->next;
					temp->next->prev = NULL;
				} else if (temp->prev != NULL && temp->next != NULL) {
					//middle node
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
				} else if (temp->prev != NULL && temp->next == NULL) {
					//last node
					temp->prev->next = NULL;
				}
				temp = temp->next;

				printf("\n [%s] DELETING...\n", delete->data->lname);
				free(delete->data->fname);
				free(delete->data->lname);
				free(delete->data->curryear);
				free(delete->data);
				free(delete);
			} else {
				temp = temp->next;
			}
		}
	}
};

/**
 * Function: printIO()
 * Return type: void
 * Params: pointer to head node
 * Purpose: receives pointer to head node and traverses to the end
 * while printing each node
 */
void printIO(struct node *current) { 
	current = head;
	if (current == NULL) {
		return;
	}

	while (current != NULL) {
		printf("\n");
		printf("Name: %s %s, \nID: %ld, \nCurrent Year: %s, \nGraduation Year: %d", current->data->fname, current->data->lname, current->data->id, current->data->curryear, current->data->gradyear);
		current = current->next;
		printf("\n");
	}	       
};

/**
 * Function: printRO()
 * Return type: void
 * Params: pointer to head node
 * Purpose: receives pointer to head and traverses until the end.
 * Finds the end and them traverses back to the beginning while printing each node.
 */
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
		printf("Name: %s %s, \nID: %ld, \nCurrent Year: %s, \nGraduation Year: %d", tail->data->fname, tail->data->lname, tail->data->id, tail->data->curryear, tail->data->gradyear);
		tail = tail->prev;
		printf("\n");
	}
};

int main() {
    int i;
    struct Student *newStudent;
    head = NULL;
    
    while (1) {
        printf("\nList of possible actions:\n");
        printf("1. Add student to the list\n");
        printf("2. Delete student(s) from the list\n");
        printf("3. Print list - Top to Bottom\n");
        printf("4. Print list - Bottom to Top\n");
        printf("5. Exit\n");
        printf("Enter choice NUMBER: ");
        
	if (scanf("%d", &i) <= 0) {
            printf("Error! Only Integer");
            exit(0);
        } else {	
	    switch (i) {
		    case 1:
	    		    newStudent = malloc(sizeof(struct Student));			    
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
			    break;
		    case 2:
			    getchar();
			    if (head == NULL) {
				    printf("List is Empty\n");
			    } else {
				    deleteStudent();
			    }
			    break;
		    case 3:
			    printf("In order print\n");
			    if (head == NULL) {
				    printf("List is Empty\n");
			    } else {
				    printIO(head);
			    }
		    	    break;
		    case 4:
			    printf("Reverse order print\n");
			    if (head == NULL) {
				    printf("List is empty\n");
			    } else {
				    printRO(head);
			    }
			    break;
		    case 5:
			    clear();
			    return 0;
	    }
        }
    }
}
