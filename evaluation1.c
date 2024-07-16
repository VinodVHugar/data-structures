#include<stdio.h>
typedef struct customer_information
{
    char customer_name[20];
    char address[30];
    float Bank_Balance;
}CI;
void read (CI C[],int n);
void display (CI C[],int n);
void print_customer_name_Balance_less_than_200(CI C[],int n);
main()
{
    CI C[1000];
    int n;
    printf("enter the number of customers\n");
    scanf("%d",&n);
    read( C,n);
    display( C,n);
    print_customer_name_Balance_less_than_200 ( C,n);
}
void read (CI C[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
    printf("enter the customer name\n");
    scanf("%s",C[i].customer_name);
    printf("enter the address\n");
    scanf("%s",C[i].address);
    printf("enter the Bank Balance\n");
    scanf("%f",&C[i].Bank_Balance);
    }
}
void display (CI C[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("customer name:%s\n",C[i].customer_name);
        printf("address:%s\n",C[i].address);
        printf("Bank Balance:%f\n",C[i].Bank_Balance);
    }
}
void print_customer_name_Balance_less_than_200(CI C[],int n)
{   int i;
    int Bank_Balance;
    char customer_name[20];
    for(i=0;i<n;i++)
    {
        if( C[i].Bank_Balance< Bank_Balance)
        {

       if (C==0)
        {
            printf("customer name\n");
        }
        if(C==1)
         {
             printf("customer not found\n");
         }
        }
    }



}
