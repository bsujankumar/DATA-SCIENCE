#include<stdio.h>
#define size 5
void push(int);
void pop();
void display();

int stack[size] , top = -1;
int main(){
    int value, choice;
    while(3){
        printf("Your choice are:\n");
        printf("1.Push , 2.Pop, 3.display, 4.exit \n");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter the value:\n");
                    sacnf("%d",&value);
                    push(value);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4:printf("Exiting ......\n");
                   return 0;
            default:printf("Invalid choice \n");
        }
    }
}

void push(int value){
    if(top == size-1){
        printf("Stack overflow \n");
    }
    else{
        top ++;
        stack[top] = value;
        printf("%d pushed to stack \n",value);
    }
}

void pop(){
    if(top == -1){
        printf("Stack underflow \n");
    }
    else{
        printf("%d popped from stack \n",stack[top]);
        top --;
    }
}

void display(){
    if(top == -1){
        ptintf("Stack is empty \n");
    }
    else{
        printf("Stack elements are :\n");
        for(int i = top; i >=0; i--){
            printf("%d \n",stack[top]);
        }
    }
}
