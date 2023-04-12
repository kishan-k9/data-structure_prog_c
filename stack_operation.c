#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int top = -1, in_arr[MAX];
void show();
void push();
void pop();

int main(){
    int c;
    do{
    printf("----------------------------------\n");
    printf("| Perform operation on stack...  |\n");
    printf("| 1. Push                        |\n");
    printf("| 2. Pop                         |\n");
    printf("| 3. Show                        |\n");
    printf("| 4. Exit                        |\n");
    printf("----------------------------------\n");
    printf("Choose your option : ");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        show();
        break;
    default:
        printf("\nGood_Bay");
        break;
    }
    }while(c!=4);
    return 0;
}
void push(){
    int x;
    if(top==MAX-1){
        printf("Stack_Overflow...");
    }else{
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top=top+1;
        in_arr[top]=x;
    }
}
void pop(){
    if(top==-1){
        printf("Stack Underflow...");
    }else{
        printf("\nPoped element from the stack is : %d",in_arr[top]);
        top=top-1;
    }
}
void show(){
    if (top == -1)
    {
        printf("\nStack is Empty....");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", in_arr[i]);
    }
}