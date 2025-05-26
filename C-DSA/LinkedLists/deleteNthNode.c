#include <stdio.h>
#include <stdlib.h>          //for malloc functions

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *head = NULL;          // global variable for simplicity
Node *tail = NULL;          //optimised verison for multiple insertion at end

Node *createNode(int data){
    Node *temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL) exit(1);

    temp->data = data;
    temp-> next = NULL;
    return temp;
}

void insert(int data){
    Node *new_node = createNode(data);

    if(head == NULL){
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
}

void print(){

    Node *temp = head;
    while(temp!= NULL)
    {
        printf(".%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete(int n){
    
    Node *temp_delete = head;
    if(n==1)
    {
        //delet the 1st node 
        head = temp1->next;
        free(temp1);
    }
    else{
        //delet other than n nodes
    }

}


int main(){

    //1st create a list
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print();
    //delete the nth node
    int n;
    printf("enter a position from 1 to 4 to delete");
    scanf("%d",&n);
    delete(n);
    print();
}