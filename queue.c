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

void printQueue(Student* headOfQueue);
void enqueueStudent(Student** headOfQueue, int studentNumber, char* studentName);
void dequeueStudent(Student** headOfQueue, Student* temporaryStudent);

int main(){
    Student* headOfQueue = NULL;
    Student* temporaryStudent = (Student*)malloc(sizeof(Student));

    printQueue(headOfQueue);
    enqueueStudent(&headOfQueue, *(studentNumbers + 0), *(studentNames + 0));
    enqueueStudent(&headOfQueue, *(studentNumbers + 1), *(studentNames + 1));
    enqueueStudent(&headOfQueue, *(studentNumbers + 2), *(studentNames + 2));
    printQueue(headOfQueue);
    printf("\nDelete student from queue.\n");
    dequeueStudent(&headOfQueue, temporaryStudent);
    printQueue(headOfQueue);
    printf("\nDelete student from queue.\n");
    dequeueStudent(&headOfQueue, temporaryStudent);
    printQueue(headOfQueue);
    return 0;
}

void printQueue(Student* headOfQueue){
    Student* currentStudent = headOfQueue;
    if(currentStudent == NULL){
        printf("There is no student in queue...\n");
    }
    else{
        while(currentStudent != NULL){
            printf("Number:%-d Name:%-s\n", currentStudent->studentNumber, currentStudent->studentName);
            currentStudent = currentStudent->nextStudent;
        }
    }
}

void dequeueStudent(Student** headOfQueue, Student* temporaryStudent){
    Student* currentStudent = (*headOfQueue);
    if(currentStudent == NULL){
        printf("dequeueStudent: There is no student in the queue...\n");
    }
    else{
        temporaryStudent->studentName = currentStudent->studentName;
        temporaryStudent->studentNumber = currentStudent->studentNumber;

        //Set new head of Queue
        (*headOfQueue) = currentStudent->nextStudent;
        //Set new head of Queue

        //Delete student from Queue
        free(currentStudent);
        //Delete student from Queue
    }
}

void enqueueStudent(Student** headOfQueue, int studentNumber, char* studentName){
    Student* newStudent = (Student*)malloc(sizeof(Student));
    Student* currentStudent = NULL;
    if(newStudent == NULL){
        printf("enqueueStudent: There is no space for new student...\n");
        exit(EXIT_FAILURE);
    }
    else{
        newStudent->studentName = studentName;
        newStudent->studentNumber = studentNumber;
        newStudent->nextStudent = NULL;
        currentStudent = (*headOfQueue);
        if(currentStudent == NULL){
            (*headOfQueue) = newStudent;
        } 
        else{
            while( currentStudent->nextStudent != NULL ){ 
                currentStudent = currentStudent->nextStudent;
            }
            currentStudent->nextStudent = newStudent;
        }
    }
}