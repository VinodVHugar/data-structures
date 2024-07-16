#include<stdio.h>
#include<string.h>
void read(name);
void repetation(name);

void main()
{
    char name[30];
     char ch;
    printf("enter the name\n");
    read(name);
    repetation(name);
}
void read(name)
{
    gets(name);
    printf("Entered name is:\n");
    puts(name);

}
void repetation(char name[30])
{
    int i,count=0;
    char ch;
    printf("enter character be checked\n");
    scanf("%c",&ch);
    for(i=0;name[i]!='\0';i++)
    {
        if (name[i]==ch)
        {
            count++;

        }

    }
     printf("%c is repeating %d times",ch,count);

}
