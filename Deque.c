#include<stdio.h>
#define N 3
int queue[N];
int front = -1;
int rear = -1;

int isFull(){
    return ((rear+1)%N == front);
}
int isEmpty(){
    return (front == -1 && rear == -1);
}

void EnqueueR(int value){
    if(isFull()){
        printf("Queue is full \n");
        return;
    }
    else if(isEmpty()){
        front = 0;
        rear = 0;
    }
    else{
        rear = (rear+1)%N;
    }
    queue[rear] = value;
    printf("%d is inserted \n",value);
}

void EnqueueF(int value){
    if(isFull()){
        printf("Queue is full \n");
        return;
    }
    else if(isEmpty()){
        front = 0;
        rear = 0;
    }
    else{
        front = (front+N-1)%N;
    }
    queue[front] = value;
    printf("%d is inserted \n",value);
}

void DequeueF(){
    if(isEmpty()){
        printf("Queue is empty \n");
    }
    else if(front == rear){
        printf("%d is deleted \n",queue[front]);
        front = rear = -1;
    }
    else{
        printf("%d is deleted \n",queue[front]);
        front = (front+1) %N;
    }
}

void DequeueR(){
    if(isEmpty()){
        printf("Queue is empty \n");
    }
    else if(front == rear){
        printf("%d is deleted \n",queue[rear]);
        front = rear = -1;
    }
    else{
        printf("%d is deleted \n",queue[rear]);
        rear = (rear+N-1)%N;
    }
}


void display(){
    if(isEmpty()){
        printf("Queue is empty \n");
        return;
    }
    printf("The queue elements are :\n");
    int i ;
    for(i = front ; i != rear; i = (i+1)%N){
        printf("%d\t",queue[i]);
    }
    printf("%d\n",queue[i]);
}

int main(){
    int value, choice;
    while(1){
        printf("Choices are : \n ");
        printf("1.enqueueR 2.enqueueF  3.dequeueF  4.dequeueR  5.display  \n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the element :\n");
                    scanf("%d",&value);
                    EnqueueR(value);
                    break;
            case 2: printf("Enter the element :\n");
                    scanf("%d",&value);
                    EnqueueF(value);
                    break;
            case 3: DequeueF();
                    break;
            case 4: DequeueR();
                    break;
            case 5: display();
                    break;
            default: printf("Invalid choice ...\n");
                     break;
        }
    }
}

