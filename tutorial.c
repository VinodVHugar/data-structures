#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
 typedef  struct Node*node;
 node head,newnode,temp;
 node insertend(node);
 node insertbeg(node);
void display(head);
void main()
{
    int choice=0;
    while(1)
    {
        printf("\n\n****Main Menu****\n");
        printf("\n Choose one option from the following list...\n");
        printf("\n==============================================\n");
        printf("\n 1-->Insertend\n 2--> Insertbeg\n 3-->Display\n 4-->Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:head=insertend(newnode);break;
            case 2:head=insertbeg(newnode);break;
            case 3:display(head);break;
            case 4:exit(0);break;
            default:printf("invalid input\n");break;
        }
    }
}
node getnode()
{
    newnode=(node)malloc(sizeof( struct node));
    if(newnode==NULL)
    {
        printf("memory not allocated\n");
        exit(0);
    }
    return newnode;
}
node read_details(  node newnode)
{
    printf("enter data\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    return newnode;
}
node insertend(node newnode)
{
    newnode=getnode();
    newnode=read_details(newnode);
    if(head==NULL)
    {
        head=newnode;
        return(head);
    }
    else
        {
            temp=head;
          while(temp->next!=NULL)
          {
              temp=temp->next;
          }
          temp->next=newnode;
          return(head);
        }
}
node insertbeg(node newnode)
{
    newnode=getnode();
    newnode=read_details(newnode);
    if(head==NULL)
    {
        head=newnode;
        return(head);
    }
    else
    {
        newnode->next=head;
        head=newnode;
        return(head);
    }
}
void display(node head)
{
    if(head==NULL)
    {
        printf("NULL is empty\n");
        exit(0);
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

