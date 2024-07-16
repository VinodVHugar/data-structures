#include <stdio.h>
int main()

{
   char str[30], rev[30];
   int i, j, count = 0;

   printf("enter word\n");
   gets(str);


   while (str[count] != '\0')
   {
       count++;
       j= count - 1;
   }
   for (i = 0; i < count; i++)
    {
          rev[i] = str[j];
          j--;
    }

   rev[i] = '\0';

   printf("%s\n", rev);

   return 0;
}
