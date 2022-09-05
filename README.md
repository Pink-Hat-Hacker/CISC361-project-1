# Programming Assignment 1
#### C Programming

### NOTE: This is an individual project.  You should not share code, or work on this project together.

**Objective**
> The primary objective of this assignment is to practice/review C coding, including the use of C structs and pointers for later use in the programming assignments.

**Details**
> Write a C program that will allow the user to enter Student data into a doubly linked list, remove student entries and view the contents of the list. Your program will be graded based on its correctness, code structure and documentation.

> You should have a .h file that declares function prototypes, structs, etc. Your .c file(s) should #include only .h files and contain all the actual C code. You need to make a C struct to hold information of a student. In this struct you should have:at a minimum

- The last name of the student stored in a char*
- The first name of the student stored in a char*
- The student's id number stored as a long
- The year of the student (i.e. freshman, sophomore) stored in a char*
- The year of expected graduation stored as an int
- A "next" pointer to another one of these structs (so you can make a linked list)
- A "prev" pointer to another one of these structs (so you can make it a doubly linked list)