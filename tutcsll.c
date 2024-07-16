
#include<stdio.h>*
#include<stdlib.h>

struct list
{
  int item;
  struct list *next;
};
typedef struct list*node;
node head,newnode,temp;
node insert_end(node);
node insert_beg(node);
node insert_pos(node head,int pos);
node delete_end(head);
node delete_beg(head);
void display(head);
node cur=NULL;int pos;
node head=NULL,prev;

void main()
{
  int choice;
  while(1)
  {
    printf("1.Insert_end \n 2.insert_beg\n 3.insert pos\n 4.delete_end\n 5.delete_beg\n  6.display\n 7.exit\n");
    printf("Enter choice:\n");
    scanf("%d",&choice);
    switch(choice)
{
    case 1:head=insert_end(newnode);break;
    case 2:head=insert_beg(newnode);break;
    case 3:head=insert_pos(head,pos);break;
    case 4:head=delete_end(head);break;
    case 5:head=delete_beg(head);break;
    case 6:display(head);break;
    case 7:exit(0);break;
    default:printf("Invalid input \n");break;
}

  }
}

node getnode()
{
  node newnode;
  newnode=(node)malloc(sizeof(struct list));
    if(newnode==NULL)
    {
        printf("memory not alloated\n");
        exit(0);
    }
 }

 node read_details(node newnode)
 {
     temp=getnode();
     printf("enter item\n");
     scanf("%d",&newnode->item);
     newnode->next=NULL;
     return newnode;
 }

node insert_end(node head)
{
    node newnode,cur;
    newnode=getnode();
    newnode=read_details(newnode);
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
           newnode->next=head;
            return(head);
        }
    }
node insert_beg(node head)
{
   newnode=getnode();
   newnode=read_details(newnode);
   if(head==NULL)
   {
       return(newnode);
   }
   else
   {
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
}
node insert_pos(node head,int pos)
{
    newnode=getnode();
    int i=1,count=1;
    if(head==NULL)
    {
      return newnode;
    }
    if(pos==1)
    {
        cur=head;
        while(cur->next!=head)
        {
            cur=cur->next;
        }
        cur->next=newnode;
        newnode->next=head;
        head=newnode;
        return head;
    }
    count=1;prev=NULL;cur=head;
    while(cur->next!=head&&count!=pos)
    {
        prev=cur;
        cur=cur->next;
        count++;
    }
    if(count==pos)
    {
        prev->next=newnode;
        newnode->next=cur;
    }
    if(count+1==pos)
    {
        cur->next=newnode;
        newnode->next=head;
        return head;
    }
    else
    {
        printf("invalid postion\n");
        return head;
    }
}

node delete_end(node head)
{
    node prev,cur;
    if(head==NULL)
    {
        printf("Linked List is empty\n");
        exit(0);
    }
    else
    {
        if(head->next==NULL)
        {
            printf("deleted=%d\n",head->item);
            free(head);
            head=NULL;
            return(head);
        }
        else
        {
         cur=head,prev=NULL;
          while(cur->next!=head)
        {
           prev=cur;
           cur=cur->next;
        }
        prev->next=head;
        printf("item deleted%d\n cur->item");
        free(cur);
        return(head);
        }
    }
}

node delete_beg(node head)
{
    if(head==NULL)
    {
        printf("Linked List is empty\n");
        exit(0);
    }
    else
    {
        if(head->next==NULL)
        {
            printf("deleteend=%d\n",head->item);
            free(head);
            head=NULL;
            return(head);
        }
        else
        {
         cur=head;
         while(cur->next!=head)
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
    }
}


void display(node head)
{
    if(head==NULL)
    {
        printf("\NULL is empty \n");
        exit(0);
    }
    else
    {
        cur=head;
        while(cur->next!=head)
        {
                printf("%d->",cur->item);
                cur=cur->next;
        }
        printf("%d",cur->item);
    }
}

