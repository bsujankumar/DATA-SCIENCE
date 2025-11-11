#include<stdio.h>
void tower(int n, char frompeg, char topeg, char auxpeg){
    if(n == 1){
        printf("Move disk 1 from peg %c to peg %c \n",frompeg,topeg);
        return;
    }
    tower(n-1,frompeg,auxpeg,topeg);
    printf("Move disk %d from peg %c to peg %c \n",n,frompeg,topeg);
    tower(n-1,auxpeg,topeg,frompeg);
}
int main(){
    int n ;
    printf("Enter the number of disks :\n");
    scanf("%d",&n);
    printf("The sequence of moves involved : \n");
    tower(n,'A','C','B');
    return 0;
}
