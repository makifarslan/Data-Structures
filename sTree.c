#include <stdio.h>
#include <stdlib.h>

struct treeNode{
    char* data;
    struct treeNode* leftTreeNode;
    struct treeNode* rightTreeNode;
};

char* studentNames[] = {"Dogan", "Bastan", "Kaptan", "Ozcan", "Kalkan", "Canan", "Arslan", "Iyigun", "Aydin"};

typedef struct treeNode TreeNode;

void preorderTravelsal(TreeNode* rootOfTree);
void inorderTravelsal(TreeNode* rootOfTree);
void postorderTravelsal(TreeNode* rootOfTree);
void insertTreeNode(TreeNode** rootOfTree, char* data);
void findTreeMaximum(TreeNode* rootOfTree);
void findTreeMinimum(TreeNode* rootOfTree);


int main(){
    //Define root of tree
    TreeNode* rootOfTree = NULL;
    //Define root of tree

    //Insert tree node
    insertTreeNode(&rootOfTree, *(studentNames + 0));
    insertTreeNode(&rootOfTree, *(studentNames + 1));
    insertTreeNode(&rootOfTree, *(studentNames + 2));
    insertTreeNode(&rootOfTree, *(studentNames + 3));
    insertTreeNode(&rootOfTree, *(studentNames + 4));
    insertTreeNode(&rootOfTree, *(studentNames + 5));
    insertTreeNode(&rootOfTree, *(studentNames + 6));
    insertTreeNode(&rootOfTree, *(studentNames + 7));
    insertTreeNode(&rootOfTree, *(studentNames + 8));
    //Insert tree node

    //Tree maximum
    printf("Tree maximum: ");
    findTreeMaximum(rootOfTree);
    printf("\n");
    //Tree maximum

    //Tree minimum
    printf("\nTree minimum: ");
    findTreeMinimum(rootOfTree);
    printf("\n");
    //Tree minimum

    //Preorder travelsal
    printf("\nPreorder travelsal:\n");
    preorderTravelsal(rootOfTree);
    printf("\n");
    //Preorder travelsal

    //Inorder travelsal
    printf("\nInorder travelsal:\n");
    inorderTravelsal(rootOfTree);
    printf("\n");
    //Inorder travelsal

    //Postorder travelsal
    printf("\nPostorder travelsal:\n");
    postorderTravelsal(rootOfTree);
    printf("\n");
    //Postorder travelsal
    return 0;
}

void preorderTravelsal(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    if(currentTreeNode != NULL){
        printf("%-6s ", currentTreeNode->data);
        preorderTravelsal(currentTreeNode->leftTreeNode);
        preorderTravelsal(currentTreeNode->rightTreeNode);
    }
}

void inorderTravelsal(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    if(currentTreeNode != NULL){
        inorderTravelsal(currentTreeNode->leftTreeNode);
        printf("%-6s ", currentTreeNode->data);
        inorderTravelsal(currentTreeNode->rightTreeNode);
    }
}

void postorderTravelsal(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    if(currentTreeNode != NULL){
        postorderTravelsal(currentTreeNode->leftTreeNode);
        postorderTravelsal(currentTreeNode->rightTreeNode);
        printf("%-6s ", currentTreeNode->data);
    }
}

void insertTreeNode(TreeNode** rootOfTree, char* data){
    TreeNode* currentTreeNode = (*rootOfTree);
    if(currentTreeNode == NULL){
        TreeNode* newTreeNode = (TreeNode*)malloc(sizeof(TreeNode));
        if(newTreeNode == NULL){
            printf("There is no memory space for new tree node...\n");
            exit(EXIT_FAILURE);
        }
        else{
            newTreeNode->data = data;
            newTreeNode->leftTreeNode = NULL;
            newTreeNode->rightTreeNode = NULL;
            (*rootOfTree) = newTreeNode;
        }
    }
    else{
        if(data < currentTreeNode->data){
            insertTreeNode(&(currentTreeNode->leftTreeNode), data);
        }
        else if(data > currentTreeNode->data){
            insertTreeNode(&(currentTreeNode->rightTreeNode), data);
        }
        else{
            printf("Duplicate records are not allowed...\n");
        }
    }
}

void findTreeMaximum(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    while(currentTreeNode->rightTreeNode != NULL){
        currentTreeNode = currentTreeNode->rightTreeNode;
    }
    printf("%-6s", currentTreeNode->data);
}

void findTreeMinimum(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    while(currentTreeNode->leftTreeNode != NULL){
        currentTreeNode = currentTreeNode->leftTreeNode;
    }
    printf("%-6s", currentTreeNode->data);
}