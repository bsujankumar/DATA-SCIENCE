#include<stdio.h>
#define size 5
int queue[size];
int rear = -1;
int front = -1;
void enqueue(int);
void dequeue();
void display();

int main(){
    int choice, value;
    while(1){
        printf("Choices are \n");
        printf("1.enqueue 2.dequeue 3.display 4.exit \n");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("Enter the value :\n");
                     scanf("%d",&value);
                     enqueue(value);
                     break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exiting...\n");
                    break;
            default: printf("Invalid choice \n");
                     return 0;
        }

    }

}
void enqueue(int value){
    if(rear == size -1){
        printf("queue overflow \n");
        return ;
    }
    if(front == -1){
        front = 0;
    }
    rear ++;
    queue[rear] = value;
    printf("%d is inserted \n",value);
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("Queue underflow \n");
    }
    printf("%d is removed \n",queue[front]);
    front ++;
}
void display(){
    if(front == -1){
        printf("Queue is empty");
    }
    printf("Queue elements are : \n");
    for(int i = front ; i <= rear; i++){
        printf("%d \t",queue[i]);
    }
    printf("\n");
}

