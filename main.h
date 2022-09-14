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
    struct Student *data;
    struct node *next;
    struct node *prev;
} *head;

//protos
struct node* addStudent(struct node *, struct Student * );
void clean();
void deleteStudent();
void printIO(struct node * );
void printRO(struct node * );
