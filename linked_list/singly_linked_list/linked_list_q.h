/***
 *
 * This file contains all the functions prototype as questions which are solved/implemented in the source file
 * since the basic linked list problems are all dependent on each other.
 * - This way I can reuse alot of functions that I already have solved.
 *
 **/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student_info{
    char name[20];
    int rollno;
    float marks;
    struct student_info *next;
}STI;

// Function Prototype
void add_begin(STI**);
void print_node(STI*);
void add_end(STI**);
void add_middle(STI**);
void count_node(STI*);
void save_file(STI*);
void read_file(STI**);

