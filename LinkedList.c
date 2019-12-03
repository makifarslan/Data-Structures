#include <stdio.h>
#include <stdlib.h>
#define NUMBEROFSTUDENTS 5

int studentNumbers[] = {1111, 2222, 3333, 4444, 5555};
char* studentNames[] = {"AAAA", "BBBB", "CCCC", "DDDD", "EEEE"};

struct student{
    char* studentName;
    int studentNumber;
    struct student* nextStudent;
};

typedef struct student Student;
void printLinkedList(Student* headOfList);
int checkForEmptyList(Student* headOfList);
int getNumberOfStudents(Student* headOfList);
int findStudent(Student* headOfList, int studentNumber);
void insertList(Student** headOfList, int studentNumber, char* studentName);
void deleteList(Student** headOfList, int studentNumber);


int main(void){
    Student* headOfStudentList = NULL;
    printLinkedList(headOfStudentList);
    printf("\n");

    for(int studentIndex = 0; studentIndex < NUMBEROFSTUDENTS; studentIndex ++){
        insertList(&headOfStudentList, *(studentNumbers + studentIndex), *(studentNames + studentIndex));
    }

    printLinkedList(headOfStudentList);
    printf("\n");
    deleteList(&headOfStudentList, 2222);
    printLinkedList(headOfStudentList);
    printf("\n");
    deleteList(&headOfStudentList, 5555);
    printLinkedList(headOfStudentList);
    printf("\n");
    deleteList(&headOfStudentList, 1111);
    printLinkedList(headOfStudentList);
    return 0;
}

void printLinkedList(Student* headOfList){
    if(headOfList == NULL){
        printf("The list is empty...\n");
    }
    else{
        Student* currentStudent = headOfList;
        while(currentStudent != NULL){
            printf("Name:%-s Number:%-ld\n", currentStudent->studentName, currentStudent->studentNumber);
            currentStudent = currentStudent->nextStudent;
        } 
    }
}

int checkForEmptyList(Student* headOfList){
    if(headOfList == NULL){
        return 0; 
    }
    else{
        return 1;
    }
}

int getNumberOfStudents(Student* headOfList){
    if(checkForEmptyList(headOfList) == 1){
        Student* currentStudent = headOfList;
        int counter = 0;
        while(currentStudent != NULL){
            currentStudent = currentStudent->nextStudent;
            counter++;
        }
        return counter;
    }
    else{
        return 0;
    }
}

int findStudent(Student* headOfList, int studentNumber){
    if(checkForEmptyList(headOfList) == 1){
        Student* currentStudent = headOfList;
        while(currentStudent != NULL && currentStudent->studentNumber != studentNumber){
            currentStudent = currentStudent->nextStudent;
        }
        if(currentStudent == NULL){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}

void insertList(Student** headOfList, int studentNumber, char* studentName){
    Student* newStudent = NULL;
    Student* currentStudent = NULL;
    newStudent = (Student*)malloc(sizeof(Student));
    
    if(newStudent != NULL){
        newStudent->studentName = studentName;
        newStudent->studentNumber = studentNumber;
        newStudent->nextStudent = NULL;
        currentStudent = (*headOfList);

        if(currentStudent == NULL){
            (*headOfList) = newStudent;
        } 
        else{
            while( currentStudent->nextStudent != NULL ){ 
                currentStudent = currentStudent->nextStudent;
            }
            currentStudent->nextStudent = newStudent;
        }
    }
    else{
        printf("There is no memory space for new student...\n");
        exit(EXIT_FAILURE);
    }
}

void deleteList(Student** headOfList, int studentNumber){
    if(findStudent((*headOfList), studentNumber) == 1){
        Student* currentStudent = NULL;
        Student* previousStudent = NULL;
        Student* temporaryStudent = NULL;
        
        if((*headOfList)->studentNumber == studentNumber){
            temporaryStudent = (*headOfList);
            (*headOfList) = (*headOfList)->nextStudent;
            free(temporaryStudent);
        }
        else{
            previousStudent = (*headOfList);
            currentStudent = (*headOfList)->nextStudent;
            while(currentStudent->studentNumber != studentNumber){
                previousStudent = currentStudent;
                currentStudent = currentStudent->nextStudent;
            }
            temporaryStudent = currentStudent;
            previousStudent->nextStudent = currentStudent->nextStudent;
            free(temporaryStudent);
        }
    }
    else{
        printf("Student is not in the linked list...\n");
    }
}
