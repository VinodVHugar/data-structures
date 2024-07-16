#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct node*next;
};
typedef struct Node*head;
Nodehead,newnode,temp;
void insertend(Node);
void insertfront(Node);
void display(head);
void deleteend(Node);
void deletefront(Node);
void exit();

void main()
{
    int choice=0;
    for(;;)
    {
        printf("\n\n****Main Menu****\n");
        printf("\n Choose one option from the following list...\n");
        printf("\n==============================================\n");
        printf("\n 1.Insertend\n 2.Display\n 3.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insertend();break;
            case 2:insertfront();break;
            case 3:display();break;
            case 4:deleteend();break;
            case 5:deletefront();break;
            case 6:exit(0);break;
            default:printf("invalid input\n";break;);
        }
    }
}
node insertend(Node head)
{
    Node new,cur;
    new=getnode();
    if(head==NULL)
    {
        return new;
    }
    cur=head;
    while
}
Node deleteend(Node head)
{
    Node prev,cur;
    if(head==NULL)
    {
        printf("list is empty\n");
        return head;
    }
    if(head->next==head)
    {
        printf("item deleted %d\n",head->item);
        free(head);
        head=NULL;
        return head;

    }
    cur=head;
    prev=NULL;
    while(cur->next!=head)
    {
        prev=cur;
        cur=cur->next;
    }
    prev-.next=head;
    printf("item deleted %d\n",cur->item);
    free(cur);
    return head;
}
Node deletefront (Node head)
{
    Node cur;
    if (head==NULL)
    {
        printf ("list is empty");
        return head;
    }
    if(head->next==head)
    {
        printf("item deleted %d\n",head->item);
        free(head);
        head=NULL;
        return head;

    }
    cur=head;
    while(cur->next=head)
    {
        cur=cur->next;
    }
    temp=head;
    head=temp->next;
    cur->next=head;
    printf("deleted item %d\n",temp->item);
    free(temp);
    return head;
}
