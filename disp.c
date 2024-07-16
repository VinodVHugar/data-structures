#include<stdio.h>
char stringlength(char[][],int i);
void main ()
{
    char s[10] [100];
    int i,m;
    printf("Enter the lines\n");
    for(i=0;i<10;i++)
    {
        gets (s[i][100]);
        m=stringlength (s,i);
    }
    printf ("the longest line is %d",m);
}

char stringlength (char)
