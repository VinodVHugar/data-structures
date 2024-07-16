#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student_details
{
    char name[20],hometown[20];
    int age,rank;
    struct student_details *next;
};
typedef struct student_details *node;
node temp,head=NULL,newnode,prev,follow;
int pos;
node getnode()
{
    newnode=(node)malloc(sizeof(struct student_details));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");exit(0);
    } newnode->next=NULL;
return newnode;
}
node read_details()
{
    temp=getnode();
    printf("Enter name,age,rank and hometown of the student\n");
    scanf("%s%d%d%s",temp->name,&temp->age,&temp->rank,temp->hometown);
return temp;
}
node insertbeg(node head)
{
    newnode=read_details();
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
        newnode->next=head;
        head=newnode;
        return head;
}
node insertend(node head)
{
    newnode=read_details();
    if(head==NULL)
    {
        return newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return head;
}
node insertbefore(node head)
{  char NAME[20];
   newnode=read_details();
   temp=head;prev=NULL;
   if(head==NULL)
   {
       return newnode;
   }
  else
   {   printf("Before whose name should the student be inserted?\n");
   scanf("%s",NAME);
    if(head->next==NULL||strcmp(head->name,NAME)==0)
   {
       newnode->next=head;
       head=newnode;
       return head;
   }
   else
       {while(temp->next!=NULL)
       {
           if(strcmp(temp->name,NAME)==0)
           {break;}
           else
           {
               prev=temp;
               temp=temp->next;
           }
       }
       prev->next=newnode;
       newnode->next=temp;
   }}
   return head;
}
node deletebeg(node head)
{
    if(head==NULL)
    {
        printf("LL is empty\n");
    }
    else
    {
        if(head->next==NULL)
        {
            printf("Deleted %s details\n",head->name);
            free(head);
            head=NULL;
            return head;
        }
        else
        {
            printf("Deleted %s details\n",head->name);
            free(head);
            head=head->next;
            return head;
        }
    }

}
node deletend(node head)
{
    if (head==NULL)
    {
        printf("LL is empty\n");
    }
    else
    {
        if(head->next==NULL)
        {
            printf("Deleted %s details\n",head->name);
            free(head);
            head=NULL;
            return head;
        }
        else
        {
           prev=NULL;temp=head;
           while(temp->next!=NULL)
           {
               prev=temp;
               temp=temp->next;
           }
           printf("Deleted %s details\n",temp->name);
           free(temp);
           prev->next=NULL;
           return head;
        }
    }
}
node deletespecific(node head)
{    char NAME[20];
    if(head==NULL)
    {
        printf("LL is empty\n");
    }
    else
    {
        printf("Enter the student's name to be deleted\n");
        scanf("%s",NAME);
        if(head->next==NULL&& strcmp(head->name,NAME)==0)
        {
            printf("Deleted %s details\n",NAME);
            free(head);
            head=NULL;
                return head;
        }
        else
        {
            if(strcmp(head->name,NAME)==0)
            {
                printf("Deleted %s details\n",NAME);
                free(head);
                head=head->next;
                return head;
            }
            else
           {
            temp=head;prev=NULL;
            while(temp->next!=NULL)
            {
                if(strcmp(temp->name,NAME)==0)
                {
                    break;
                }
                else
                {
                    prev=temp;
                    temp=temp->next;
                }
            }
           }
            printf("Deleted %s details\n",NAME);
            prev->next=temp->next;
            free(temp);
            return head;
        }
    }
}
node insertpos(node head,int pos)
{
   int count=1;
   newnode=read_details();

   if(head==NULL&&pos==1)
   {
       return newnode;
   }
   if(head==NULL)
   {
       printf("Invalid Position\n");
       return head;
   }
   if(pos==1)
       {
           newnode->next=head;
           head=newnode;
           return head;
       }
       else
       {   prev=NULL;temp=head;
           while(temp!=NULL&&count!=pos)
           {
               prev=temp;
               temp=temp->next;
               count++;
           }
           if(count==pos)
           {
               prev->next=newnode;
               newnode->next=temp;
               return head;
           }
           else
            {printf("Invalid Position\n");
           return head;}
       }

}
node deletepos(node head,int pos)
{
    int count;
    if(head==NULL)
    {
       printf("LL is empty\n");
       return NULL;
    }
    if(pos==1)
    {
        temp=head;
        head=head->next;
        printf("Deleted %s details\n",temp->name);
        free(temp);
        return head;
    }
    else
    {   count=1;
        prev=NULL;temp=head;
        while(temp!=NULL&&count!=pos)
        {
            prev=temp;
            temp=temp->next;
            count++;
        }
        if(pos==count&&temp!=NULL)
        {
            prev->next=temp->next;
            printf("Deleted %s details\n",temp->name);
            free(temp);
            return head;
        }
        else
        {
            printf("Invalid position\n");
            return head;

        }
    }
}
node reverse(node head)
{
    prev=NULL;temp=head;follow=head;
    if(head==NULL)
    {
        printf("LL is empty\n");
    }
    else
    {while(follow!=NULL)
    {
        follow=follow->next;
        temp->next=prev;
        prev=temp;
        temp=follow;
    }
    head=prev;printf("Data is reversed\n");}
    return head;
}
void display(node head)
{    temp=NULL;
    if(head==NULL)
    {
        printf("LL is empty\n");exit(0);
    }
    else
    {   printf("Entered data is:\n");
        temp=head;
        while(temp!=NULL)
        {
            printf("%s\n%d\n%d\n%s\n",temp->name,temp->age,temp->rank,temp->hometown);
            temp=temp->next;printf("\n");
        }
    }
}
void main()
{
    int choice,pos;
    for(;;)
    {
        printf("\n\n1.Insert at the beginning\n2.Insert at the end\n3.Insert before a given name\n4.Delete at the beginning\n5.Delete at the end\n6.Delete a specific name\n7.Insert at a particular position\n8.Delete a specific position\n9.Reverse the list\n10.Display\n11.Exit\n");
        printf("Select one from the above options\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head=insertbeg(head);break;
            case 2: head=insertend(head);break;
            case 3: head=insertbefore(head);break;
            case 4: head=deletebeg(head);break;
            case 5: head=deletend(head);break;
            case 6: head=deletespecific(head);break;
            case 7: printf("Enter the position to be inserted\n");
                    scanf("%d",&pos);
                    head=insertpos(head,pos);break;
            case 8: printf("Enter the position to be deleted\n");
                    scanf("%d",&pos);
                    head=deletepos(head,pos);break;
            case 9: head=reverse(head);break;
            case 10: display(head);break;
            case 11: exit(0);break;
            default: printf("Enter a valid choice\n");
        }
    }
}
