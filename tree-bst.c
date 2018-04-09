#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
    int key;
    struct node *LEFT, *RIGHT;
}*root = NULL;

struct node* newNode(int key){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> key = key;
    temp -> LEFT = NULL;
    temp -> RIGHT = NULL;
    return temp;
}

struct node* insert(struct node *ptr, int key){
    if(ptr == NULL)
        return newNode(key);
    if(key < ptr -> key)
        ptr -> LEFT = insert(ptr -> LEFT, key);
    else
        ptr -> RIGHT = insert(ptr -> RIGHT, key);
    return ptr;
}

struct node* deleteNode(struct node *ptr, int key){
    if(ptr == NULL)
        return ptr;
    if(ptr -> key == key){
        if(ptr -> LEFT == NULL && ptr -> RIGHT == NULL){
            //if it is a leaf node
            struct node *temp = NULL;
            free(ptr);
            return temp;
        }
        //either one child is empty
        else if(ptr -> LEFT == NULL){
            struct node *temp;
            temp = ptr -> RIGHT;
            free(ptr);
            return temp;
        }
        else if(ptr -> RIGHT == NULL){
            struct node *temp;
            temp = ptr -> LEFT;
            free(ptr);
            return temp;
        }
        else{
            //node with two children
            struct node *temp;
            temp = ptr -> RIGHT;
            while (temp -> LEFT != NULL)
                temp = temp -> LEFT;n
            ptr -> key = temp -> key;
            root -> RIGHT = deleteNode(root -> RIGHT, temp -> key);
        }
    }
    if(ptr -> key > key)
        ptr -> LEFT = deleteNode(ptr -> LEFT, key);
    else
        ptr -> RIGHT = deleteNode(ptr -> RIGHT, key);
}

void inOrder(struct node *ptr){
    if (ptr != NULL){
        inOrder(ptr -> LEFT);
        printf("%d ", ptr -> key);
        inOrder(ptr -> RIGHT);
    }
}

int main(){
    int op, n;
    printf("Enter key of root: ");
    scanf("%d", &n);
    root = insert(root, n);
    do{
        printf("MENU\n----\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display Tree\n");
        printf("4. EXIT\n");
        printf("\nEnter option: ");
        scanf("%d", &op);
        switch(op){
            case 1:
            printf("Enter key to insert: ");
            scanf("%d", &n);
            insert(root, n);
            break;
            case 2:
            printf("Enter key to delete: ");
            scanf("%d", &n);
            deleteNode(root, n);
            break;
            case 3:
            inOrder(root);
            break;
            case 4:
            exit(0);
        }
        printf("\n\n");
    }while(op > 0 && op < 5);
    return 0;
}
