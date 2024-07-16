#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*next;
    struct Node*prev;

};
typedef struct Node *node;
node insert_rear(int item,node first);
node insert_front(int item,node first);
node getnode();
void display_list_forwad(node first);
void display_list_backward(node first);
node delete_rear(node first);
node delete_front(node last);
node delete_pos(node first,int pos);


node getnode()
{
    node t;
    t=(node)malloc(sizeof(struct Node));
     if(t==NULL)
       {
          printf("Not created\n");
           exit(0);
       }
        t->next=t;
        t->prev=t;
        return t;
}

node insert_front(int item,node first)
{
    node t,c;
    t=getnode();
    t->data=item;
    if(first==NULL)
        return t;
    else
    {
        node last=first->prev;
        t->next=first;
        first->prev=t;
        first=t;
        last->next=first;
        first->prev=last;
        return first;
    }
}

node insert_rear(int item,node first)
{
    node t,c;
    t=getnode();
    t->data=item;
    if(first==NULL)
        return t;
    else
    {
        node last=first->prev;
        t->next=first;
        first->prev=t;
        last->next=t;
        t->prev=last;
        return first;
    }

}
void display_list_forward(node first)
{
    node t;
    if(first==NULL)
    {
        printf("Empty List\n");
        return;
    }
    printf("Elements are\n");
    t=first;
    while(t->next!=first)
    {
        printf("%d\t",t->data);
        t=t->next;
    }
    printf("%d\t",t->data);
    return;
}
void display_list_backward(node first)
{
    node t,p;
    if(first==NULL)
    {
        printf("Empty List\n");
        return;
    }
    printf("Elements are\n");
    p=first->prev;
    while(p!=first)
    {
        printf("%d\t",p->data);
        p=p->prev;
    }
    printf("%d\t",p->data);
    return;
}


node delete_front(node first)
{
    node last,t=first;
    if(first==NULL)
    {
        printf("empty list\n");
        return NULL;
    }
    if(first->next==first&&first->prev==first)
    {
        printf("element to be deleted is:%d\n",first->data);
        free(first);
        return NULL;
    }
    else
    {
        last=first->prev;
        first=t->next;
        first->prev=last;
        last->next=first;
        printf("element to be deleted is:%d\n",t->data);
        free(t);
    }
    return first;
}

node delet_rear(node first)
{
     node t,c;
    if(first==NULL)
    {
        printf("empty list\n");
        return NULL;
    }
    if(first->next==first&&first->prev==first)
    {
        printf("element to be deleted is:%d\n",first->data);
        free(first);
        return NULL;
    }
    t=first;
    while(t->next!=first)
    {
        t=t->next;
    }
    t->prev->next=first;
    first->prev=t->prev;
    printf("element to be deleted is:%d\n",t->data);
    free(t);
    return first;
}
 node delete_pos (node first,int pos)
 {
     node t,pr;
     int i,count=1;
     t=first
 }



