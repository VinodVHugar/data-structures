#include<stdio.h>
#include<stdlib.h>
struct NODE
{
     int data;
     struct NODE *next;
     struct NODE *prev;
};
typedef struct NODE *node;
node head=NULL,temp,newnode,cur,p;
node getnode()
{
    newnode=(node)malloc(sizeof(struct NODE));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter integer data\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
node InsertEnd(node head)
{
    newnode=getnode();
    if(head==NULL)
    {
        return newnode;
    }
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    return head;
}
node InsertFront(node head)
{
    newnode=getnode();
    if(head==NULL)
    {
        return newnode;
    }
    temp=head;
    newnode->next=temp;
    temp->prev=newnode;
    head=newnode;
    return head;
}
node displayf(node head)
{
    if(head==NULL)
    {
        printf("LL is empty\n");
        exit(0);
    }
      printf("\nEntered data is:\n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
node displayb(node head)
{

   if(head==NULL)
    {
        printf("LL is empty\n");
        exit(0);
    }
    printf("\nEntered data in reverse:\n");
    temp=head;
    if(head->next==NULL&&head->prev==NULL)
    {
        printf("%d\n",head->data);
        return head;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
node DeleteFront(node head)
{
    if(head==NULL)
    {
        printf("LL is empty\n");
        exit(0);
    }
    if(head->next==NULL && head->prev==NULL)
    {
        printf("Deleted %d\n",head->data);
        free(head);
        return NULL;
    }
    temp=head;
    head=temp->next;
    temp->next=NULL;
    printf("Deleted %d\n",temp->data);
    free(temp);
    head->prev=NULL;
    return head;
}
node DeleteEnd(node head)
{
   if(head==NULL)
    {
        printf("LL is empty\n");
        exit(0);
    }
    if(head->next==NULL && head->prev==NULL)
    {
        printf("Deleted %d\n",head->data);
        free(head);
        return NULL;
    }
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    cur=temp->prev;
    temp->prev=NULL;
    printf("Deleted %d\n",temp->data);
    free(temp);
    cur->next=NULL;
    return head;
}
node InsertPos(node head)
{
    int count=1,pos;
    printf("Enter Position to be inserted\n");
    scanf("%d",&pos);
    if(head==NULL && pos>1)
    {
        printf("LL is empty\n");
        return head;
    }
    else if(pos==1)
    {
        head=InsertFront(head);
    }
    else
    {
        newnode=getnode();
        temp=head;p=NULL;
        while(temp->next!=NULL && count!=pos)
        {
            p=temp;
            temp=temp->next;
            count++;
        }
        if(pos>count+1)
        {
            printf("Cannot Insert as position is greater than no of nodes\n");
        }
        else if(pos==count+1)
        {
            temp->next=newnode;
            newnode->prev=temp;
        }
        else
        {
            newnode->prev=p;
            p->next=newnode;
            newnode->next=temp;
            temp->prev=newnode;
        }
    }
    return head;
}
node DeletePos(node head)
{
     int count=1,pos;
    printf("Enter Position to be deleted\n");
    scanf("%d",&pos);
    if(head==NULL && pos>=1)
    {
        printf("LL is empty\n");
        return head;
    }
    else if(pos==1)
    {
        head=DeleteFront(head);
    }
    else
    {
        temp=head;
        while(temp->next!=NULL && count!=pos)
        {
            p=temp;
            temp=temp->next;
            count++;
        }
        if(pos==count && temp->next==NULL)
        {
            p->next=NULL;
            temp->prev=NULL;
            printf("Deleted %d\n",temp->data);
            free(temp);
        }
        else if(pos==count && temp->next!=NULL)
        {
            p->next=temp->next;
            temp->next->prev=p;
            printf("Deleted %d\n",temp->data);
            free(temp);
        }
        else if(pos>count)
        {
            printf("Invalid position\n");
        }
    }
    return head;
}
void main()
{
    int choice;
    for(;;)
    {
        printf("\n1 - Insert at end\n2 - Insert at front\n3 - Display Forward\n4 - Display Backward\n5 - Delete Front\n6 - Delete End\n7 - Insert at specific position\n8 - Delete a specific position\n9 - exit\n");
        printf("enter choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : head=InsertEnd(head);break;
            case 2 : head=InsertFront(head);break;
            case 3 : displayf(head);break;
            case 4 : displayb(head);break;
            case 5 : head=DeleteFront(head);break;
            case 6 : head=DeleteEnd(head);break;
            case 7 : head=InsertPos(head);break;
            case 8 : head=DeletePos(head);break;
            case 9 : exit(0);break;
            default : printf("Enter Valid Choice\n");
        }
    }
}
