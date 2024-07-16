#include<stdio.h>*
#include<stdlib.h>

struct emp
{
  char emp_name[20];
  int empid;
  char company_name[20];
  char designation[20];
  int emp_age;
  int salary;
  struct e *next;
  struct e*prev;
};
typedef struct emp*e;
e head,newnode,temp;
e insertrear(e head);
e insertfront(e head);
e delete_empid(e head);
void display(e head);
e cur=NULL;prev;
e head=NULL;

void main()
{
  int choice;
  while(1)
  {
    printf("1.insertfront\n 2.insertrear\n 3.deleteempid\n 4.display\n 5.exit\n");
    printf("Enter choice:\n");
    scanf("%d",&choice);
    switch(choice)
{
    case 1:head=insertfront(newnode);break;
    case 2:head=insertfront(newnode);break;
    case 3:head=delete_empid(head);break;
    case 4:display(head);break;
    case 5:exit(0);break;
    default:printf("Invalid input \n");break;
}

  }
}

e getnode()
{
  e newnode;
  newnode=(e)malloc(sizeof(struct emp));
    if(newnode==NULL)
    {
        printf("memory not alloated\n");
        exit(0);
    }
      newnode->prev=NULL;
     newnode->next=NULL;
     printf("enter emp_name\n empid\n company_name\n designation\n emp_age\n salary\n");
     scanf("%s%d%s%s%d%d",&newnode->emp_name,empid, company_name,designation,emp_age,salary);
     return newnode;
 }

e insert_end(e head)
{
    node temp,cur;
    temp=getnode();
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)
    {   head=temp;
        return head;

    }
        cur=head;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
           cur->next=temp;
           temp->prev=cur;
            return(head);
}

e insertfront(e head)
{  e temp;
   temp=getnode();
   if(head==NULL)
   {    head=temp;
       return head;
   }

       temp->next=head;
       head->prev=temp;
       head=temp;
       return head;

}
void display

