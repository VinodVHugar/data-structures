//Program to read and display N number of cricket players info using Pointers to Strctures
#include<stdio.h>
typedef struct cricket_player
{ char player_name[20];
char team_name[20];
float average;
int highest_score;
int centuries;
int ODI_rank;
}PLR;
PLR read(PLR *p,int n);
void display( PLR *p,int n);
void highest_batting_average(PLR *p,int n);
void sort_by_ODI_rank(PLR *p,int n);
main( )
{
PLR p[11];
int n;
printf("Enter number of players:");
scanf("%d",&n);
read(p,n);
display(p,n);
highest_batting_average(p,n);
sort_by_ODI_rank(p,n);
printf("Player details after sorting in ascending order based on the ODI_rank\n");
display(p,n);
}
PLR read(PLR *p,int n)
{
int i;
for(i=0;i<n;i++)
{
printf ( "\nEnter player name ");
scanf ("%s", p->player_name );
printf ( "\nEnter team name ");
scanf ("%s", p-> team_name );
printf ( "\nEnter Batting average");
scanf ("%f",&p->average);
printf ( "\nEnter highest score");
scanf ("%d", &p-> highest_score );
printf ( "\nEnter Centuries ");
scanf ("%d", &p->centuries );
printf ( "\nEnter ODI rank");
scanf ("%d", &p->ODI_rank);
p++;
}
}
void display( PLR *p,int n)
{
int i;
for(i=0;i<n;i++)
{
printf ( "Player Name: %s\n",p->player_name);
printf ( "Team Name: %s\n",p->team_name);
printf ( "Batting Average: %f\n",p->average);
printf ( "Highest score: %d\n",p->highest_score);
printf ( "Centuries: %d\n",p->centuries);
printf ( "ODI rank: %d\n",p->ODI_rank);
p++;
}
}
void highest_batting_average(PLR *p,int n)
{
int i,index=0;
float h;
h=p[0].average;
for(i=1;i<n;i++)
{
if(p[i].average>h)
{
h=p[i].average;
index=i;
}
}
printf("The player who is having highest batting average\n");
printf ( "Player Name: %s\n",p[index].player_name);
printf ( "Team Name: %s\n",p[index].team_name);
printf ( "Average: %f\n",p[index].average);
printf ( "Highest score: %d\n",p[index].highest_score);
printf ( "Centuries: %d\n",p[index].centuries);
printf ( "ODI rank: %d\n",p[index].ODI_rank);
}
void sort_by_ODI_rank(PLR *p, int n)
{
int i,j;
PLR swap;
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(p[j].ODI_rank>p[j+1].ODI_rank)
{
swap=p[j];
p[j]=p[j+1];
p[j+1]=swap;
}
}
}
}
