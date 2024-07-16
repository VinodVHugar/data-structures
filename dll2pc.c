#include<stdio.h>
#include<stdlib.h>

struct employee
{
    char emp_name[20];
    int emp_id;
    char company_name[20];
    char designation[20];
    int emp_age;
    int salary;
    struct employee*next;
    struct employee*prev;
};

typedef struct employee*emp;
emp insertrear(emp head);
emp insertfront(emp head);
emp newnode,prev,cur,temp,head;
void display(emp head);
void main()
{
  int choice;
  while(1)
  {
    printf("\t 1.-->insertend \n2.-->insertbeg\n3.-->display\n 4=-->exit\n");
    printf("Enter choice:\n");
    scanf("%d",&choice);
    switch(choice)
{
    case 1:head=insertrear(head);break;
    case 2:head=insertfront(head);break;
    case 3:display(head);break;
    case 4:exit(0);break;
    default:printf("Invalid input \n");break;

}

  }
}

emp getnode()
{
  newnode=(emp)malloc(sizeof(struct employee));
    if(newnode==NULL)
    {
        printf("memory not allocated\n");
        exit(0);
    }
    printf("Enter the name\n");
    scanf("%s",newnode->emp_name);
     printf("Enter the Id\n");
    scanf("%d",&newnode->emp_id);
     printf("Enter the company name\n");
    scanf("%s",newnode->company_name);
     printf("Enter the designation\n");
    scanf("%s",newnode->designation);
     printf("Enter the age\n");
    scanf("%d",&newnode->emp_age);
     printf("Enter the salary\n");
    scanf("%d",&newnode->salary);
    newnode->next=NULL;
    newnode->prev=NULL;
     return(newnode);
 }
emp insertrear(emp head)
{

    newnode=getnode();
    if(head==NULL)
    {
        return(newnode);

    }
    else
    {
        cur=head;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
           cur->next=newnode;
           newnode->prev=cur;
           return head;
    }
}
emp insertfront(emp head)
{
   newnode=getnode();

   if(head==NULL)
   {
       return(newnode);
   }
   else
   {
       newnode->next=head;
       head->prev=newnode;
       head=newnode;
       return head;
   }
}void display(emp head)
{
    if(head==NULL)
    {
        printf("\nLL is empty \n");
        return head;
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
                printf("%s\n",cur->emp_name);
                printf("%d\n",&cur->emp_id);
                printf("%s\n",cur->company_name);
                printf("%s\n",cur->designation);
                printf("%d\n",&cur->emp_age);
                printf("%d\n",&cur->salary);
                cur=cur->next;
        }
                printf("%s\n",cur->emp_name);
                printf("%d\n",&cur->emp_id);
                printf("%s\n",cur->company_name);
                printf("%s\n",cur->designation);
                printf("%d\n",&cur->emp_age);]
                printf("%d\n",&cur->salary);
    }
}
