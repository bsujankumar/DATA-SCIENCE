#include<stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

int isFull(){
    return ((rear+1)%N == front);
}
int isEmpty(){
    return (front == -1);
}

void Enqueue(int value){
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

void Dequeue(){
    if(isEmpty()){
        printf("Queue is empty \n");
    }
    else if(front == rear){
        printf("%d is deleted \n",queue[front]);
        front = rear = -1;
    }
    else{
        printf("%d is deleted \n",queue[front]);
        front = (front+1)%N;
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
        printf("1.enqueue  2.dequeue  3.display  4.exit \n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the element :\n");
                    scanf("%d",&value);
                    Enqueue(value);
                    break;
            case 2: Dequeue();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exiting ....\n");
                    return 0;
            default: printf("Invalid choice ...\n");
                     break;
        }
    }
}

