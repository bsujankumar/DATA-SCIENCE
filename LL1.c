#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    struct node *head = NULL;
    struct node *n1, *n2, *n3;
    n1 = (struct node *)malloc(sizeof(struct node));
    n2 = (struct node *)malloc(sizeof(struct node));
    n3 = (struct node *)malloc(sizeof(struct node));
    head = n1;
    // printf("%p\n",head);
    // printf("%p\n",&head);
    n1->data = 1;
    n1->next = n2;
    n2->data = 2;
    n2->next = n3;
    n3->data = 3;
    n3->next = NULL;
    struct node *temp = head;
    while(temp!= NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}