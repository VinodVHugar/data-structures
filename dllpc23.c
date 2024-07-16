#include<stdio.h>*
#include<stdlib.h>

struct Node
{
  int item;
  struct node *next;
  struct node *prev;
};
typedef struct Node*node;
node head,newnode,temp;
node insert_end(node);
node insert_beg(node);
node insert_pos(node head);
node delete_end(head);
node delete_beg(head);
node delete_pos(node head);
void display_forward(head);
void display_reverse(head);
node cur=NULL;prev;
node head=NULL;

void main()
{
  int choice;
  while(1)
  {
    printf("1.Insert_end \n 2.insert_beg\n 3.insert_pos\n 4.delete_end\n 5.delete_beg\n 6.delete_pos\n 7.display_forward\n 8.display_reverse\n 9.exit\n");
    printf("Enter choice:\n");
    scanf("%d",&choice);
    switch(choice)
{
    case 1:head=insert_end(newnode);break;
    case 2:head=insert_beg(newnode);break;
    case 3:head=insert_pos(newnode);break;
    case 4:head=delete_end(head);break;
    case 5:head=delete_beg(head);break;
    case 6:head=delete_beg(head);break;
    case 7:display_forward(head);break;
    case 8:display_reverse(head);break;
    case 9:exit(0);break;
    default:printf("Invalid input \n");break;
}

  }
}

node getnode()
{
  node newnode;
  newnode=(node)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("memory not alloated\n");
        exit(0);
    }
      newnode->prev=NULL;
     newnode->next=NULL;
     printf("enter item\n");
     scanf("%d",&newnode->item);
     return newnode;
 }

node insert_end(node head)
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

node insert_beg(node head)
{  node temp;
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
node insert_pos(node head)
{
    node newnode;
    node cur=head, p=NULL;
    int pos,count=1;
    printf("enter the position\n");
    scanf("%d",&pos);
    if(head==NULL&&pos<1)
    {
        printf("list is empty \n");
    }
    if(pos==1)
    {
        head=insertfront(head);
    }
    else
    {
        newnode = getnode();
        while(cur->next!=NULL&&count!=pos)
        {
            p=cur;
            cur=cur->next;
            count++;
        }
    }
    if (pos>count+1)
    {
     printf("cannot insert,position is greater than number of nodes\n");
    }
    else if(pos==count+1)
    {
        cur->next=newnode;
        newnode->prev=cur;
    }
    else
    {
        p->next=newnode;
        newnode->prev=p;
        newnode->next=cur;
        cur->prev=newnode;
    }
    return head;
}



node delete_beg(node head)
{
    node cur;
    if(head==NULL)
    {
        printf("Linked List is empty\n");
        exit(0);
    }
    else
    {
        if((head->next==NULL) &&(head->prev==NULL))
        {
            printf("deleted=%d\n",head->item);
            free(head);
            return NULL;
        }
       cur=head;
       head=head->next;
       head->prev=NULL;
       printf("%d=deleted",cur->item);
        cur->next=NULL;
        free(cur);
        return(head);
        }
    }

node delete_end(node head)
{   node cur=head, back=NULL;
    if(head==NULL)
    {
        printf(" DLL List is empty\n");
        exit(0);
    }
    else
    {
        if((head->next==NULL)&&(head->prev==NULL))
        {
            printf("deleted=%d\n",head->item);
            free(head);
            return(head);
        }
        else
        {
            temp=NULL;
            cur=head;
         while(cur->next!=NULL)
         {
             temp=cur;
             cur=cur->next;
         }

         printf("deleted item %d\n",cur->item);
         temp->next=NULL;
         cur->prev=NULL;
         free(cur);
         return head;
        }
    }
}
node delete_pos(node head)
{
    node c,p;
    int pos,count=1;
    printf("enter the position\n");
    scanf("%d",&pos);
    if(head==NULL&&pos>=1)
    {
        printf("list is empty\n");
        return head;
    }
    else if(pos==1)
    {
        head=delete_front(head);
    }
    else
    {
        c=head;
        while(c->next!=NULL&&pos!=count)
        {
            p=c;
            c=c->next;
            count++;
        }
        if(pos==count)
        {
            p->next=c->next;
            c->next->prev=p;
            printf("deleted item=%d",c->data);
            free(c);
        }
        if(pos>count)
        {
            printf("invalid pos\n");
        }
    }
    return head;
}



void display_forward(node head)
{    node cur;
    if(head==NULL)
    {
        printf("list is is empty \n");
         exit(0);
    }
    else
    {
        cur=head;
        while(cur!=head)
        {
                printf("%d\t",cur->item);
                cur=cur->next;
        }
        printf("%d",cur->item);
    }
}
void display_reverse(node head)
{
    node cur,temp=NULL;
     if(head==NULL)
    {
        printf("list is empty \n");
         exit(0);
    }
    cur=head;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    temp=cur;
    while(temp!=NULL)
    {
        printf("%d\t",temp->item);
        temp=temp->prev;
    }
}

