#include<stdio.h>
#include<stdlib.h>
struct node
{
	int no;
	struct node *next;
};
typedef struct node NODE;
NODE *start=NULL;

NODE * create();
void insert_front();
void delete_front();
void display();

int main()
{
	int ch;
	while(1)
	{
		printf("\n-----SINGLY LINKED LIST MENU-----\n");
		printf("1:Insert Front 2:Delete Front 3: Display 4:Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert_front();
				break;
			case 2: delete_front();
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default: printf("Invalid Choice\n");
		}
	}
	return 0;
}

NODE* create()
{
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	printf("Enter an number: ");
	scanf("%d",&temp->no);
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

void delete_front()
{
	NODE *cur;
	if(start==NULL)
		printf("The list is empty. \n");
	else
	{
		cur=start;
		start=start->next;
		printf("Deleted data is %d \n\n",cur->no);
		free(cur);
	}
}

void display()
{
	NODE *cur;
	if(start==NULL)
		printf("List is empty. \n");
	else
	{
		cur=start;
		printf("Numbers in list are:\n");
		while(cur!=NULL)
		{
			printf("%d ->",cur->no);
			cur=cur->next;
		}
	}
}
