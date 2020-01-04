#include <stdio.h>
#include <stdlib.h>

struct treeNode{
    int data;
    struct treeNode* leftTreeNode;
    struct treeNode* rightTreeNode;
};

typedef struct treeNode TreeNode;

void preorderTravelsal(TreeNode* rootOfTree);
void inorderTravelsal(TreeNode* rootOfTree);
void postorderTravelsal(TreeNode* rootOfTree);
void insertTreeNode(TreeNode** rootOfTree, int data);
int findTreeMaximum(TreeNode* rootOfTree);
int findTreeMinimum(TreeNode* rootOfTree);


int main(){
    //Define root of tree
    TreeNode* rootOfTree = NULL;
    //Define root of tree

    //Insert tree node
    insertTreeNode(&rootOfTree, 38);
    insertTreeNode(&rootOfTree, 83);
    insertTreeNode(&rootOfTree, 35);
    insertTreeNode(&rootOfTree, 593);
    insertTreeNode(&rootOfTree, -346);
    //Insert tree node

    //Tree maximum
    printf("\nTree maximum: %d\n", findTreeMaximum(rootOfTree));
    //Tree maximum

    //Tree minimum
    printf("\nTree minimum: %d\n", findTreeMinimum(rootOfTree));
    //Tree minimum

    //Preorder travelsal
    printf("\nPreorder travelsal:\n");
    preorderTravelsal(rootOfTree);
    //Preorder travelsal

    //Inorder travelsal
    printf("\nInorder travelsal:\n");
    inorderTravelsal(rootOfTree);
    //Inorder travelsal

    //Postorder travelsal
    printf("\nPostorder travelsal:\n");
    postorderTravelsal(rootOfTree);
    //Postorder travelsal
    return 0;
}

void preorderTravelsal(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    if(currentTreeNode != NULL){
        printf("%-6d ", currentTreeNode->data);
        preorderTravelsal(currentTreeNode->leftTreeNode);
        preorderTravelsal(currentTreeNode->rightTreeNode);
    }
}

void inorderTravelsal(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    if(currentTreeNode != NULL){
        inorderTravelsal(currentTreeNode->leftTreeNode);
        printf("%-6d ", currentTreeNode->data);
        inorderTravelsal(currentTreeNode->rightTreeNode);
    }
}

void postorderTravelsal(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    if(currentTreeNode != NULL){
        postorderTravelsal(currentTreeNode->leftTreeNode);
        postorderTravelsal(currentTreeNode->rightTreeNode);
        printf("%-6d ", currentTreeNode->data);
    }
}

void insertTreeNode(TreeNode** rootOfTree, int data){
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

int findTreeMaximum(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    while(currentTreeNode->rightTreeNode != NULL){
        currentTreeNode = currentTreeNode->rightTreeNode;
    }
    return currentTreeNode->data;
}

int findTreeMinimum(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    while(currentTreeNode->leftTreeNode != NULL){
        currentTreeNode = currentTreeNode->leftTreeNode;
    }
    return currentTreeNode->data;
}