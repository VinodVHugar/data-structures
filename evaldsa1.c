#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct news_list
{
    char news[1000];
};
struct news_list nl[100];
int global_count=0;

void read (char asentence [][100],int n )
{for(int i=0;i<n;i++)
{
gets(asentence[i]);
}
}
void display(char bsentence[][100],int n)
{
int max,max1=0,k,c,tp;
char key[10];
printf('Enter the key word that you want to search for\n');

scanf("%s",key);
for(int i=0;i<n;i++)
{
    tp=check(bsentence[i],key);
    if(tp==1)
    {
        puts(bsentence[i]);

    }
}
}
int check (char bsentence[],char key[])
{
    int a[10],i=0,j=1,tp=0;
    while(bsentence[i]!='\0')
    {
        tp=0;
        if (bsentence[i]==key[0])
        {
            while(key[j]!='\0')
            {
                if(bsentence[i+j]!=key[j])
                {
                    break;
                }
                j++;
            }
            if(key[j]=='\0')
            {
                tp=1;
                break;
            }
            else
                {
                    j=0;
                }
                }
            i++;
            }
  return tp;  }


void load_from_file()
{
    FILE *fp;

    fp=fopen("News_list.txt","r");

    if(fp==NULL)
    {
        printf("File Not Found\n");
        return;
    }

    while(!feof(fp))
    {
        //fscanf(fp,"%s",nl[global_count].news);
        fgets(nl[global_count].news,1000,fp);
        printf("%s",nl[global_count].news);
        global_count++;
    }
    fclose(fp);
}

int main()
{

    int M,i;
    load_from_file();
    int n;
char sentence[100][100];
printf("Enter the number of lines\n");
scanf('%d',&n);
getchar();
read(sentence,n);
display(sentence,n);

return 0;
}

