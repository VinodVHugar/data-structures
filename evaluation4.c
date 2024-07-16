#include<stdio.h>
#include<stdlib.h>
struct student_details
{
    char student_name[20];
    int score;
    int roll_no;
    char gender;
    struct student_details *next;
};
typedef struct student_details *node;
node head=NULL,temp,newnode,cur;
node insertend(node newnode);
node insertbeg(node newnode);
node delete_male_students(head);
node getnode();
node read_details(node newnode);
void display(head);
void main()
{
    int choice;
    for(;;)
    {
        printf("1.Insertend\n 2.Insertbeg\n 3.Delete_male_students\n 5.Display_student-details\n 6.Exit\n");
        printf("Select one choice from the above list\n");
        scanf("%d",&choice);

    switch(choice)
    {
        case 1: head=insertend(newnode);break;
        case 2: head=insertbeg(newnode);break;
        case 3: head=delete_male_students(head);break;
        case 5: display_student_list(head);break;
        case 6: exit(0);break;
        default: printf("Enter valid choice\n");
    }
    }
}
node getnode()
{
    newnode=(node)malloc(sizeof(struct student_details));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
return newnode;
}
node read_details(node newnode)
{   printf("student_name\n");
    scanf("%s",newnode->student_name);
     printf("score\n");
    scanf("%d",&newnode->score);
     printf("roll_no\n");
    scanf("%d",&newnode->roll_no);
     printf("gender\n");
    scanf("%s",newnode->gender);
    newnode->next=NULL;
     return(newnode);
}
node insertend(node newnode)
{
    newnode=getnode();
    newnode=read_details(newnode);
    if(head==NULL)
         {
             head=newnode;
             return head;
         }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {temp=temp->next;}
        temp->next=newnode;
        return head;
    }
}
node insertbeg(node newnode)
{
    newnode=getnode();
    newnode=read_details(newnode);
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    else
    {
        newnode->next=head;
        head=newnode;
        return head;
    }
}

void display(head)
{   printf("The entered data is:\n");
    if(head==NULL)
    {
        printf("LL is empty\n");
        exit(0);
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%s%d%d%s\n",temp->student_name,temp->score,temp->roll_no,temp->gender);
            temp=temp->next;
        }printf("\n");

    }
}
node delete_male_students(head)
{
     node prev=NULL ,cur=head, char nm[6];
     char student_name[20];
     printf("enter name of student\n");
     scanf("%s",nm);
     if(head==NULL);
{
    printf("candidate list is empty \n");

}
if(head->next=NULL && strcmp(head->name,nm)==0)
{
    printf("deleted candidate=%s\n",head->name);
    free(head);
    return NULL;

}
if(strcmp(head->name,nm)==0)
{
    cur=head;
    head=head->next;
    free(cur);
    return head;
}
while(cur->next!=NULL)
{
    if(strcmp(cur->name,nm)==0)
    {
        break;
    }
}
}

