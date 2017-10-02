#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node{
    int key;
    struct node *LEFT, *RIGHT;
} *root = NULL;

struct node* newNode(int key){
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp -> key = key;
    temp -> LEFT = NULL;
    temp -> RIGHT = NULL;
    return temp;
}

void addNode(int parent[], struct node *created[], int i){
    if(created[i] != NULL){
        return;
    }
    created[i] = newNode(i);
    if(parent[i] == -1){
        root = created[i];
        return;
    }
    if (created[parent[i]] == NULL)
        addNode(parent, created, parent[i]);
    struct node *p = created[parent[i]]; //parent node
    if (p -> LEFT == NULL)
        p -> LEFT = created[i];
    else
        p -> RIGHT = created[i];
}

void createTree(){
    int n, i;
    printf("Enter size of parent array: ");
    scanf("%d", &n);
    int parent[n];
    struct node* created[n];
    printf("Enter array: ");
    for(i = 0; i < n; i++){
        created[i] = NULL;
        scanf("%d", &parent[i]);
    }
    for(i = 0; i < n; i++)
        addNode(parent, created, i);
}

void inOrder(struct node *root){
    if (root != NULL){
        inOrder(root -> LEFT);
        printf("%d ", root -> key);
        inOrder(root -> RIGHT);
    }
}

void preOrder(struct node *root){
    if (root != NULL){
        printf("%d ", root -> key);
        inOrder(root -> LEFT);
        inOrder(root -> RIGHT);
    }
}

void postOrder(struct node *root){
    if (root != NULL){
        inOrder(root -> LEFT);
        inOrder(root -> RIGHT);
        printf("%d ", root -> key);
    }
}


int main(){
    int op;
    do{
        printf("MENU\n----\n");
        printf("1. Create Tree\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. EXIT\n");
        printf("\nEnter option: ");
        scanf("%d", &op);
        switch(op){
            case 1:
            createTree();
            break;
            case 2:
            printf("IN-ORDER: ");
            inOrder(root);
            break;
            case 3:
            printf("PRE-ORDER: ");
            preOrder(root);
            break;
            case 4:
            printf("POST-ORDER: ");
            postOrder(root);
            break;
            case 5:
            exit(0);
        }
        printf("\n\n");
    }while(op > 0 && op < 6);
    return 0;
}
