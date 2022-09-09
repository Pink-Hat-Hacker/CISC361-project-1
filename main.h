// Zoe Valladares - pink-hat-hacker 9/5/2022

#define BUFFERSIZE 128

typedef struct Student
{
    /* data */
    char *lname;
    char *fname;
    long id;
    char *curryear;
    int gradyear;
} student;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

//protos
void addStuddent(struct Student * );
