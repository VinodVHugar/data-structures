#include<stdio.h>
int stack[100],i,j,choice=0,n,top=-1;
void push();
void pop();
void show();
void main()
{
    printf("Enter the number of elements in stack\n");
    scanf("%d",&n);
    printf("*******stack operation using array*********");
    printf("\n-------------------------------\n");
    while(choice!=4)
    {
        printf("choose one from the below options...\n");
        printf("\n 1.push\n 2.pop\n 3.show\n 4.exit");
        printf("\nEnter yoiur choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                show();
                break;
            }
            case 4:
            {
                printf("Exit");
                break;
            }
            default:
                {
                    printf("Invalid choice");
                }
        };
    }
}
void push()
{
    int val;
    if(top==n)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("Enter the value?\n");
        scanf("%d",&val);
        top=top+1;
        stack[top]=val;
    }
}
void pop()
{
    if(top==1)
    {
        printf("underflow");
    }
    else
    {
        top=top-1;
    }
}
void show()
{
    if(top==1)
    {
        printf("stack is empty");
    }
    else
    {
        for(i=top;i>0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

