#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
void addFirst(Node **head, int value){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = value;
    if(*head == NULL){
      *head = new_node;
      return;
    }
    new_node -> next = *head;
    *head = new_node;
}
void addLast(Node **head, int value){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = value;
    new_node -> next = NULL;
    if(*head == NULL){
      *head = new_node;
      return;
    }
    Node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp -> next = new_node;
}
void addPos(Node **head, int pos, int value){
    if(pos == 1){
        addFirst(head, value);
        return;
    }
    Node *temp = *head;
    int i = 1;
    while(i < pos - 1 && temp -> next != NULL){
        temp = temp -> next;
        i++;
    }
    if(i < pos -1){
        printf("Position out of range \n");
        return;
    }
    if(temp -> next == NULL){
        addLast(head, value);
        return;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = temp -> next;
    temp -> next = newNode;
}
void display(Node **head){
    Node *temp = *head;
    while(temp!= NULL){
        printf("%d -> ",temp->data);
        temp = temp -> next;
    }
    printf("NULL");
}
int main(){
    Node *head = NULL;
    addFirst(&head,20);
    addFirst(&head,10);
    addLast(&head,40);
    addLast(&head,50);
    display(&head);


}
