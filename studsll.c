#include<stdio.h>
#include<stdlib.h>
struct node
{
	char name[20], usn[20];
	int rollno;
	float cgpa;
	struct node *next;
};
typedef struct node NODE;
NODE *start=NULL;

NODE * create();
void insert_front();
void insert_end();
void delete_front();
void delete_end();
void display();

int main()
{
	int choice;
	while(1)
	{
		printf("\n-----SINGLY LINKED LIST MENU-----\n");
		printf("1:Ins Fr 2:Del Fr 3:Ins End 4:Del End 5: DISP 6:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert_front();
				break;
			case 2: delete_front();
				break;
			case 3: insert_end();
				break;
			case 4: delete_end();
				break;
			case 5: display();
				break;
			case 6: exit(0);
			default: printf("Invalid Choice\n");
		}
	}
	return 0;
}

NODE* create()
{
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	printf("Enter Student Details: \n");
	printf("Enter Name: ");
	scanf("%s",temp->name);
	printf("Enter usn: ");
	scanf("%s",temp->usn);
	printf("Enter roll number: ");
	scanf("%d",&temp->rollno);
	printf("Enter cgpa: ");
	scanf("%f",&temp->cgpa);
	temp->next=NULL;
	return(temp);
}

void insert_front()
{
	NODE *temp;
	temp=create();
	if(start==NULL)
		start=temp;
	else
	{
		temp->next=start;
		start=temp;
	}
}

void insert_end()
{
	NODE *cur,*temp;
	temp=create();
	if(start==NULL)
		start=temp;
	else
	{
		cur=start;
		while(cur->next!=NULL)
			cur=cur->next;
		cur->next=temp;
	}
}

void delete_front()
{
	NODE *cur;
	if(start==NULL)
		printf("The Student list is empty. \n");
	else
	{
		cur=start;
		start=start->next;
		printf("Deleted student name is %s \n",cur->name);
		free(cur);
	}
}

void delete_end()
{
	NODE *cur,*temp,*prev;
	if(start==NULL)
		printf("The Student list is empty. \n");
	else if(start->next==NULL)
	{
		printf("Deleted student name is %s \n",start->name);
		start=NULL;
		free(start);
	}
	else
	{
		cur=start;
		while(cur->next!=NULL)
		{
			prev=cur;
			cur=cur->next;
		}
		prev->next=NULL;
		printf("Deleted student name is %s \n",cur->name);
		free(cur);
	}
}

void display()
{
	NODE *cur;
	if(start==NULL)
		printf("Student List is empty. \n");
	else
	{
		cur=start;
		printf("Student details in list is:\n");
		printf("Name\tUSN\tRoll No\tCgpa\n");
		while(cur!=NULL)
		{
			printf("%s\t%s\t%d\t%f\n ",cur->name,cur->usn,cur->rollno,cur->cgpa);
			cur=cur->next;
		}
	}
}

