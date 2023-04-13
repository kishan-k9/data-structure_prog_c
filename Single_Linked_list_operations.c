#include<stdio.h>
#include<stdlib.h>                              // for dynamic memory allocation
struct node
{
    int data;
    struct node* next;
};
typedef struct node* nodeptr;
nodeptr start = NULL;

nodeptr getnode(){                               //1 getnode()
    nodeptr p = (nodeptr)malloc(sizeof(nodeptr));
    if(p==NULL){
        printf("unable to create node...\n");
        return 0;
    }
    return p;
}
void freenode(nodeptr p){                        //2 freenode()
        if(p==NULL)
            printf("Pointer not exist..\n");
        else
            free(p);
}
void traverse(){                                //3 traverse or display 
        nodeptr ptr;
        ptr=start;
        while (ptr!=NULL)
        {
            printf("# %d #",ptr->data);
            ptr=ptr->next;
        }
}
nodeptr ib(nodeptr head, int info){             //4 insert node at begining    
    nodeptr q;
    q=getnode();
    q->data=info;
    if(q==NULL){
        printf("overflow....");
        return 0;
    }
    if(start==NULL)
        q->next=NULL;
    else
        q->next=start;
    start=q;
    return start;
}
nodeptr ie(nodeptr head,int info){               //5 insert node at end   
    nodeptr q,loc; 
    q = getnode();
    q->data=info;
    q->next=NULL;
    if(start==NULL){
        start=q;
    }else{
        loc=start;
        while(loc->next!=NULL){
            loc=loc->next;
        }
        loc->next=q;
    }
    return start;
}
void ian(nodeptr pos,int info){                  //6 insert after a node
    nodeptr q;
    q=getnode();
    q->data=info;
    if(pos==NULL){
        printf("Void insertion..Linked list not exist....\n");
    }else{
        q->next=pos->next;
        pos->next=q;
    }
}
void db(){                                       //7 delete node from begining
    nodeptr p;
    if(start==NULL){
        printf("No nodes are available...");
    }else{
        p=start;
        start=start->next;
        freenode(p);
    }
}
void de(){                                        //8 delete node from end  
    nodeptr p,prev;
    if(start==NULL){
        printf("No nodes are available...");
    }else{
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
void dan(nodeptr p){                              //9 delete after a node
    nodeptr q;
    if(p==NULL || p->next==NULL){
        printf("Empty node can not be deleted...\n");
    }else{
        q=p->next;
        p->next = q->next;
        freenode(q);
    }
}
int cont(){                                      //10 count the number of nodes in LInked List     
    nodeptr q;
    int count=0;
    q=start;
    while(q!=NULL){
        count++;
        q=q->next;
    }
    return count;
}
nodeptr find_ptr_to_loc(int loc){                //11 find the location of a pointer  
    nodeptr q;
    int i;
    q = start;
    for(i=1;i<loc;i++){
        q = q->next;
    }
    return q;
}
int main(){                                      // main function
    int sc;
    do{
        int x,s,c,loc,pl;
        nodeptr p;
        printf("\n------ Linked List Operations ---------");
        printf("\n| 1: Insert node at the beginning      |");
        printf("\n| 2: Insert node at the end            |");
        printf("\n| 3: Insert node after a given node    |");
        printf("\n| 4: Delete a node from the beginning  |");
        printf("\n| 5: Delete a node from the end        |");
        printf("\n| 6: Delete a node after a given node  |");
        printf("\n| 7: Number of nodes in a list         |");
        printf("\n| 8: Traverse/Display a list           |");
        printf("\n| 9: EXIT                              |");
        printf("\n---------------------------------------");
        printf("\n Choose your option : ");
        scanf("%d", &sc);
        switch (sc)
        {
        case 1:
            printf("Enter The value : ");
            scanf("%d",&x);
            ib(start,x);
            break;
        case 2:
            printf("Enter The value : ");
            scanf("%d",&x);
            ie(start,x);
            break;
        case 3:
            printf("Enter The location : ");
            scanf("%d",&loc);
            p=find_ptr_to_loc(loc);
            printf("Enter The value : ");
            scanf("%d",&x);
            ian(p,x);
            break;
        case 4:
            db();
            break;
        case 5:
            de();
            break;
        case 6:
            printf("Enter The Location : ");
            scanf("%d",&loc);
            p=find_ptr_to_loc(loc);
            dan(p);
            break;
        case 7:
            c=cont();
            printf("The number of node in LInked List is : %d",c);
            break;
        case 8:
            traverse();
            break;
        default:
            printf("...Good_Bay...");
            break;
        }
    }while(sc!=9);
    return 0;
}