#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
typedef struct node* nodeptr;
nodeptr start = NULL;

nodeptr getnode(){                          //1
 nodeptr p;   
 p=(nodeptr)malloc(sizeof(nodeptr));
 if(p==NULL){
    printf("unable to create a node\n");
    return 0;
 }
 return p;
}
void freenode(nodeptr p){                   //2
    if(p==NULL)
    printf("Pointer does not exist\n");
    else
    free(p);
}
void traverse(){                             //3
    nodeptr ptr;
    ptr=start;
    while(ptr!=NULL){
        printf("# %d #",ptr->data);
        ptr=ptr->next;
    }
}
nodeptr ins_at_beg(nodeptr head,int x){      //4
    nodeptr q;
    q=getnode();
    q->data=x;
    if(q==NULL){
        printf("overflow can't locate memory.....");
        return head;
    }
    if(start==NULL){
        q->next=NULL;
    }
    else{
        q->next=start;
    }
    start = q;
    return start;
}
nodeptr ins_at_end(nodeptr head,int x)       //5
{
    nodeptr q,loc;
    q = getnode();
    q->data = x;
    q->next = NULL;
    if(start == NULL)
    {
        start = q;
    }
    else{
        loc = start;
        while(loc->next !=NULL)
        {
            loc = loc->next;
        }
        loc->next = q;  
    }
    return start; 
}
void ins_after_node(nodeptr p,int x){        //6
    nodeptr q;
    q=getnode();
    q->data=x;
    if(p==NULL){
        printf("void insertion : linked list not exist....\n");
        return;  //dout
    }
    else{
        q->next=p->next;
        p->next=q;
        return;  //dout
    }
}
void del_at_beg(){                                  //7
    nodeptr p;
    if(start==NULL){
        printf("No node are available....\n");
        return;  //dout
    }
    else{
        p=start;
        start=start->next;  
        freenode(p);
    }
}
void del_at_end(){                                   //8 
    nodeptr p,prev;
    if(start==NULL){
        printf("No node are available....\n");
        return; //dout
    }
    else{
        p=start;
        prev=start;
        while(p->next!=NULL){
            prev=p;
            p=p->next;
        }
        prev->next=NULL;
        freenode(p);
    }
}
void del_after(nodeptr p){                         //9
    nodeptr q;
    if(p==NULL || p->next==NULL){
        printf("Cannot Delete");
        return;
    }
    else{
        q=p->next;
        p->next = q->next;
        freenode(q);
    }
}
int cont(){                                               //10
    nodeptr q;
    int count = 0;
    q=start;
    while(q!=NULL){
        count++;
        q=q->next;
    }
    return count;
}
nodeptr find_ptr_to_loc(int loc){
    nodeptr q;
    int i;
    q = start;
    if(q==NULL){
        printf("Empty linked list...");
        return 0;
    }
    else{
        for(i=1;i<loc;i++){
        q = q->next;
        }
        printf("pointer is : %d",q);
        return 0;
    }
}
int main(){
    int sc;
    do
    {   int x,s,c,loc,pl;
        nodeptr p;
        printf("\n\n * ****MAIN MENU * ****");
        printf("\n 1: Insert node at the beginning");
        printf("\n 2: Insert node at the end");
        printf("\n 3: Insert node after a given node");
        printf("\n 4: Delete a node from the beginning");
        printf("\n 5: Delete a node from the end");
        printf("\n 6: Delete a node after a given node");
        printf("\n 7: Number of nodes in a list");
        printf("\n 8: Traverse/Display a list");
        printf("\n 9: Find pointer to location");
        printf("\n 10: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &sc);
        switch(sc)
        { 
            case 1:
                printf("enter value to inserted : ");
                scanf("%d",&x); 
                ins_at_beg(start,x);
                break;
            case 2:
                printf("enter value to inserted : ");
                scanf("%d",&x); 
                ins_at_end(start,x);
                break;
            case 3:
                printf("Enter a location node after which you want to insert : ");
                scanf("%d",&loc);
                p = find_ptr_to_loc(loc);
                printf("enter value to inserted : ");
                scanf("%d",&x);
                ins_after_node(p, x);
                break;
            case 4: 
                del_at_beg();
                break;
            case 5: 
                del_at_end();
                break;
            case 6:
                printf("Enter a location node after which you want to insert : ");
                scanf("%d",&loc);
                p = find_ptr_to_loc(loc); 
                del_after(p);
                break;
            case 7:
                c = cont();
                printf("no.of nodes in Linked list is : %d",c);
                break;
            case 8:
                traverse();
                break;
            case 9:
                printf("Enter to find pointer at location : ");
                scanf("%d",&pl);
                find_ptr_to_loc(pl);
                break;
            default:
                printf("Thankyou...");
        }
    }while(sc!=10);
    return 0;
}