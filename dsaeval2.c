#include<stdio.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

FILE *fp1,*fp2,*fp3;
int a[10000],n;
void random(int p,int q)
{
    int i,k;
    fp1 = fopen("input.txt","w");

    if(fp1==NULL)
    {
        printf("ERROR creating file");
        exit(0);
    }

    for(i=0;i<n;i++)
    {
        k=(rand()%(q-p+1))+p;
        fprintf(fp1,"%d ",k);
    }
    fprintf(fp1,"\n");
    fclose(fp1);
    read();
}

void read()
{
    int i=0;
    fp1 = fopen("input.txt","r");
    if(fp1==NULL)
    {
        printf("File Not Found\n");
        return;
    }

    while(!feof(fp1))
    {
        fscanf(fp1,"%d",&a[i]);
        i++;
    }
    printf("\n\nRANDOM ARRAY ELEMENTS BEFORE SORTING\n");
    display();
    fclose(fp1);
}

void write(int c)
{
    int i;
    fp2 = fopen("output.txt","a");
    if(fp2==NULL)
    {
        printf("ERROR creating file\n");
        exit(0);
    }
    switch(c)
    {
        case 1:  fprintf(fp2,"1. BUBBLE SORT\n");break;

        default: printf("INVALID INPUT\n");
    }
    for(i=0;i<n;i++)
        fprintf(fp2,"%d\t",a[i]);
    fprintf(fp2,"\n\n");
    fclose(fp2);
}

void log(c)
{
    float t;
    fp3 = fopen("log.txt","a");
    if(fp2==NULL)
    {
        printf("ERROR creating file\n");
        exit(0);
    }
    switch(c)
    {
        case 1 : t = n*n;
                 fprintf(fp3,"1. BUBBLE SORT\nInput(n): %d\nTime Efficiency: %.4f\n\n",n,t);
                 break;


        default : printf("INVALID INPUT\n");
    }
}

void display()
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void swap(int b,int c)
{
    int d;
    d=a[b];
    a[b]=a[c];
    a[c]=d;
}


void bubble_sort()
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
                swap(j,j+1);
        }
    }
}


int main()
{
    int p,q;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    printf("Enter range:\nLower and Upper\n");
    scanf("%d%d",&p,&q);
    srand(time(0));
    fp2 = fopen("output.txt","w");
    fp3 = fopen("log.txt","w");
    fprintf(fp3,"Time Complexity for different Sorting Techniques (Worst Case Analysis):\n\n");
    random(p,q);
    printf("1. BUBBLE SORT:\n");
    bubble_sort();
    write(1);
    log(1);
    display();


return 0;
}


