/*at the start of the linked list*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *head = NULL;
Node *createNode(int data)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL) exit(1);
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insert_node(int data){

    Node *new_node = createNode(data);
    new_node->next = head;
    head = new_node;
}
void print_node()
{
    Node* read_node = head;
    while(read_node!=NULL){
        printf("data: %d",read_node->data);
        read_node = read_node->next;  //  move forward
    }
    printf("\n");
}
int main(){
    printf("How many nodes to insert?\n");
    int n, data;
    scanf("%d",&n);
    for(int i =0; i< n; i++)
    {
        printf("enter number: ");
        scanf("%d", &data);
        insert_node(data);
    }
    printf("Inserted list :\n");
    print_node();
}