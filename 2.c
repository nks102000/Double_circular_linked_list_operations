//1905622 - NITISH KUMAR SONTHALIA
//Double Circular Linked list
#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next; 
    struct node *prev;
};

void creat_list(struct node ** ,int n);
void display_list(struct node ** );
void add_first_node(struct node ** ,int n);
void add_Last_node(struct node ** ,int n);
void del_first_node(struct node ** );
void del_last_node(struct node **end );

int main(){
     struct node *start = NULL;
    int t;

    int f=1;

    while(f){
    printf("\n MENU ");
    printf("\n 1. Enter An Element ");
    printf("\n 2. Display The List ");
    printf("\n 3. Add First Node ");
    printf("\n 4. Delete First Node ");
    printf("\n 5. Add Last Node ");
    printf("\n 6. Delete Last Node ");
    printf("\n 7. EXIT ");
    scanf("%d",&t);
    int e,p;

    switch (t)
    {

    case 1:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        creat_list(&start,e);
        break;

    case 2:
        display_list(&start);
        break;

    case 3:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        add_first_node(&start,e);
        break;

    case 4:
        del_first_node(&start);
        break;
    case 5:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        add_Last_node(&start,e);
        break;

    case 6:
        del_last_node(&start);
        break;

    case 7:
        f=0;
        break;

    default:
        break;
    }
    }
}

void creat_list(struct node **st ,int n){
    struct node *temp=NULL;

    struct node *new1 = (struct node *)malloc(sizeof(struct node));

    new1->data=n;

    new1->next=NULL;

    new1->prev=NULL;

    if(*st==NULL){
        *st=new1;
        new1->next=*st;

        new1->prev=*st;

        return;
    }
    else{
        temp=*st;
        while(temp->next!=*st){
            temp= temp->next;
        }
        temp->next = new1;
        new1->prev=temp;
        new1->next=*st;
        (*st)->prev=new1;
    }
}

void display_list(struct node **st){

    if (*st == NULL){ 
      printf("\n Empty List"); 
      return ;
    }

    struct node*temp=*st;
    printf("Elements in LIST are:");

    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp->next!=*st);
    printf("%d ",temp->data);
}

void add_first_node(struct node **st ,int n){

    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    struct node *temp=*st;

    ptr->data = n;
    ptr->next=*st;
    ptr->prev=(*st)->prev;
    temp->prev->next=ptr;
    temp->prev=ptr;
    *st=ptr;
}

void add_Last_node(struct node **st ,int n){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    struct node *temp=NULL;
    ptr->data = n;

    temp=*st;
    while(temp->next!=*st){
        temp=temp->next;
    }
        ptr->next=temp->next;
        ptr->prev=temp;
        temp->next->prev=ptr;
        temp->next=ptr;

}

void del_first_node(struct node **st ){

    struct node *ptr=*st;

    ptr->next->prev=ptr->prev;
    ptr->prev->next=ptr->next;
    *st=ptr->next;
    free(ptr);
}

void del_last_node(struct node **st ){

    struct node *t=*st;

    while(t->next!=*st){
        t=t->next;
    }
    t->prev->next=t->next;
    t->next->prev=t->prev;
    t=t->prev;
    free(t);
}