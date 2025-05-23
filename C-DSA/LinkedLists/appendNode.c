#include <stdio.h>
#include <stdlib.h>          //for malloc functions

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *head = NULL;          // global variable for simplicity
Node *tail = NULL;          //optimised verison for multiple insertion at end

Node *createNode(int data)
{
    Node *temp1 = (Node*)malloc(sizeof(Node));
    if(temp1 == NULL)
    {
        printf("allocation failed\n");
        exit(1);
    }
    temp1->data = data;
    temp1->next = NULL;
    return temp1;
}

void printNodes(Node *head)
{
    Node* temp2 = head;
    while(temp2 !=NULL)
    {
        printf(".data %d\n", temp2->data);
        temp2 = temp2->next;
    }
}
void append(int data )
{
    Node *newNode = createNode(data);

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}



int main(){

    append(4);
    append(5);

    printNodes(head);
}


