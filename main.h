// Zoe Valladares - pink-hat-hacker 9/5/2022

typedef struct student
{
    /* data */
    char *lname;
    char *fname;
    long id;
    char *curryear;
    int gradyear;
}

struct node {
    int data;
    struct node *next;
    struct node *prev;
}