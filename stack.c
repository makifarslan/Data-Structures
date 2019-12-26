#include <stdio.h>
#include <stdlib.h>

int studentNumbers [] = {1111, 2222, 3333};
char* studentNames [] = {"AAAA", "BBBB", "CCCC"};

struct student{
    int studentNumber;
    char* studentName;
    struct student* nextStudent;
};

typedef struct student Student;

void pushStudent(Student** headOfStack, int studentNumber, char* studentName);
void printStack(Student* headOfStack);
void popStudent(Student** headOfStack, Student* temporaryStudent);

int main(){
    Student* headOfStack = NULL;
    Student* temporaryStudent = (Student*)malloc(sizeof(Student));

    printStack(headOfStack);
    pushStudent(&headOfStack, *(studentNumbers + 0), *(studentNames + 0));
    pushStudent(&headOfStack, *(studentNumbers + 1), *(studentNames + 1));
    pushStudent(&headOfStack, *(studentNumbers + 2), *(studentNames + 2));
    printStack(headOfStack);
    printf("\nPop Students from stack.\n");
    popStudent(&headOfStack, temporaryStudent);
    printStack(headOfStack);
    printf("\nPop Students from stack.\n");
    popStudent(&headOfStack, temporaryStudent);
    printStack(headOfStack);
    return 0;
}

void popStudent(Student** headOfStack, Student* temporaryStudent){
    Student* currentStudent = (*headOfStack);
    if(currentStudent == NULL){
        printf("popStudent: There is no student in the stack...\n");
    }
    else{
        temporaryStudent->studentName = currentStudent->studentName;
        temporaryStudent->studentNumber = currentStudent->studentNumber;

        //Set new head of stack
        (*headOfStack) = currentStudent->nextStudent;
        //Set new head of stack

        //Delete student from stack
        free(currentStudent);
        //Delete student from stack
    }
}

void printStack(Student* headOfStack){
    Student* currentStudent = headOfStack;
    if(currentStudent == NULL){
        printf("There is no student in stack...\n");
    }
    else{
        while(currentStudent != NULL){
            printf("Number:%-d Name:%-s\n", currentStudent->studentNumber, currentStudent->studentName);
            currentStudent = currentStudent->nextStudent;
        }
    }
}

void pushStudent(Student** headOfStack, int studentNumber, char* studentName){
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if(newStudent == NULL){
        printf("pushStudent: There is no space for new student...\n");
        exit(EXIT_FAILURE);
    }
    else{
        newStudent->studentName = studentName;
        newStudent->studentNumber = studentNumber;
        newStudent->nextStudent = (*headOfStack);

        //Set new head of stack
        (*headOfStack) = newStudent;
        //Set new head of stack
    }
}