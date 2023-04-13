#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *ptr;
}*top,*top1,*temp;
typedef struct node* nodeptr;
int count = 0;

void push(int data) {
     if (top == NULL){
        top =(nodeptr)malloc(sizeof(nodeptr));
        top->ptr = NULL;
        top->info = data;
    }else{
        temp =(nodeptr)malloc(sizeof(nodeptr));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
    printf("Node is Inserted\n");
}
int pop() {
     top1 = top;
    if (top1 == NULL){
        printf("\nStack Underflow\n");
        return -1;
    }
    else
        top1 = top1->ptr;
    int popped = top->info;
    free(top);
    top = top1;
    count--;
    return popped;
}
void show() {
    top1 = top;
    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
    }
    printf("The stack is \n");
    while (top1 != NULL){
        printf("%d--->", top1->info);
        top1 = top1->ptr;
    }
    printf("NULL\n");
}

int main() {
    int c, val;
    do{
        printf("----------------------------------\n");
        printf("| Perform operation on stack...  |\n");
        printf("| 1. Push                        |\n");
        printf("| 2. Pop                         |\n");
        printf("| 3. Show                        |\n");
        printf("| 4. Exit                        |\n");
        printf("----------------------------------\n");
        printf("\nEnter your choice : ");
        scanf("%d", &c);
        switch (c) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            printf("Popped element is :%d\n", pop());
            break;
        case 3:
            show();
            break;
        default:
            printf("\nGood_Bay\n");
            break;
        }
    }while(c!=4);
}