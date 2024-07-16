#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*head;

void insert();
void display();
void exit();

void main()
{
    int choice=0;
    for(;;)
    {
        printf("\n\n****Main Menu****\n");
        printf("\n Choose one option from the following list...\n");
        printf("\n==============================================\n");
        printf("\n 1.Insert\n 2.Display\n 3.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert();break;
            case 2:display();break;
            case 3:exit(0);break;
            default:printf("Please enter valid choice...");
        }
    }
}
void insert()
{
    struct node*ptr,*temp;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\n Memory not allocated");
    }
    else
    {
        printf("\n Enter value ?\n");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL)
        {
            head=ptr;
            ptr->next=NULL;
            printf("\n Node inserted \n");
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
            printf("\n Node inserted\n");

        }
    }
}
void display()
{
    struct node*ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("\nNothing to print \n");
    }
       else
       {
           printf("\nPrinting values......\n");
           while(ptr!=NULL)
           {
               printf("\n%d",ptr->data);
               ptr=ptr->next;
           }
       }
  }
