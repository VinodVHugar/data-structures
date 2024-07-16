#include<stdio.h>
#include<stdlib.h>
struct list
{
int item;
struct list *next;
};

typedef struct list *NODE;
NODE head,newnode,temp;
NODE insert_end(NODE);
NODE insert_beg(NODE);
NODE delete_front(NODE head);
NODE delete_end(NODE head);
void display(head);
NODE getnode()
{

    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct list));
    if(newnode==NULL)
    {
        printf("Not created\n");
        exit(0);
    }
    printf("Enter item\n");
    scanf("%d",&newnode->item);
    newnode->next=newnode;
    return newnode;
}


NODE head=NULL;
void  main()
{
    NODE head;
    int choice,item;
    while(1)
    {
        printf("\n 1->Insert end \n 2->Insert beg \n 3->delete front\n 4->delete end\n 5->Display \n 6->Exit\n");
        printf("\nEnter the choice?\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                head=insert_end(newnode);
            break;
            case 2:
                head=insert_beg(newnode);
                break;
            case 3:
                head=delete_front(newnode);
            case 4:
                head=delete_end(newnode);
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
                break;
        }
    }
}
NODE insert_end(NODE head)
{
    NODE newnode,cur;
    newnode=getnode();
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    cur=head;
    while(cur->next!=head)
        {
        cur=cur->next;
    }
    cur->next=newnode;
    newnode->next=head;
    return head;
}


void display(NODE head)
{
    NODE cur;
    if(head=NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    cur=head;
    while(cur->next=head)
    {
        printf("%d",cur->item);
        cur=cur->next;
    }
    printf("%d",cur->item);
}
NODE insert_beg(NODE head)
{
    NODE newnode,cur;
    newnode=getnode();
    if(head=NULL)
    {
        head=newnode;
        return head;
    }
    cur=head;
    while(cur->next!=head)
    {
        cur=cur->next;
    }
    newnode->next=head;
    cur->next=newnode;
    head=newnode;
    return head;
}

NODE delete_end(NODE head)
{
    NODE prev,cur;
    if(head==NULL)
    {
        printf("List empty\n");
        return head;
    }
    if(head->next==head)
    {
        printf("Item deleted:%d\n",head->item);
        free(head);
        head=NULL;
        return head;
    }
    cur=head;prev=NULL;
    while(cur->next!=head)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=head;
    printf("Item deleted %d\n",cur->item);
    free(cur);
    return head;
}
NODE delete_front(NODE head)
{
    NODE temp,cur=head;
    if(head==NULL)
    {
        printf("List empty\n");
        return NULL;
    }
    if(head->next==head)
    {
        printf("Deleted item:%d\n",head->item);
        free(head);
        return NULL;
    }
    while(cur->next!=head)
    {
        cur=cur->next;
    }
    temp=head;
    head=temp->next;
    cur->next=head;
    printf("Deleted item:%d\n",temp->item);
    free(temp);
    return head;
}
NODE Insert_pos(NODE head,int pos)
{
    NODE cur,prev;
    newnode=getnode();
    int i=1; int count=1;
    if(head==NULL)
    {
        return newnode;
    }
    if(pos==1)
    {
        cur=head;
        while(cur ->next=head)
        {
            cur=cur ->next;
        }
        cur ->next=newnode;
        newnode ->next=head;
        head=newnode;
        return head;
    }
    count=1 ;prev=NULL; cur=head;
    while(cur->next!=head && count!=pos)
    {
        prev=cur;
        cur=cur ->next;
        count++;
    }
    if(count==pos)
    {
        prev->next=newnode;
        newnode->next=head;
        return head;
    }
    else{
        printf("Invalid position\n");
        return head;
    }
}
