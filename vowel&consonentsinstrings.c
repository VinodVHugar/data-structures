
#include<stdio.h>
#include<string.h>
void read (char str[]);
void vowcons(char str[]);
void digits(char str[]);
void space(char str[]);
int main()
{
    char str[30],ch;
    int C;
    printf("Enter string name\n");
    read(str);
    vowcons(str);
    digits(str);
    space(str);

return 0;
}
void read(char str[])
{
    gets(str);
    puts(str);
}
void vowcons(char str[])
{
    int i,count1=0,count2=0;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='A' || str[i]<='Z' || str[i]>='a' || str[i]<='z')
        {
            if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' || str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
            {
                count1++;
            }
            else
            {
                count2++;
            }
        }
    }
    printf("\nVowels: %d\nConsonants: %d\n",count1,count2);
}
void digits(char str[])
{
    int count3=0,i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='0' || str[i]<='9')
        {
           count3++;
        }
    }
    printf("Digits: %d\n",count3);
}
void space(char str[])
{
    int count4=0,i;
   for(i=0;str[i]!='\0';i++)
   {
       if(str[i]==' ')
       {
           count4++;
       }
   }
   printf("White Spaces: %d\n",count4);

}
