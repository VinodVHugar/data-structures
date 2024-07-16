//Program to read and display cricket player details using nested structures.
#include<stdio.h>
struct achievements
{
int man_of_matches;
int man_of_series;
int no_of_centuries;
};
typedef struct cricket_player
{
char player_name[20];
char team_name[20];
// structure within structure
int ODI_rank;
struct achievements achieved;
}PLR;
PLR read(PLR p[],int n);
void display(PLR p[],int n);
main( )
{
PLR p[10];
int n;
printf("Enter n:");
scanf("%d",&n);
read(p,n);
display(p,n);
}
PLR read(PLR p[10],int n)
{
int i;
for(i=0;i<n;i++)
{
printf ( "\nEnter player name ");
scanf ("%s", p[i]. player_name );
printf ( "\nEnter team name ");
scanf ("%s", p[i]. team_name );
printf ( "\nEnter ODI rank");
scanf ("%d", &p[i]. ODI_rank);
printf("Enter man of the matches");
scanf("%d",&p[i].achieved. man_of_matches);
printf("Enter man of the series");
scanf("%d",&p[i].achieved.man_of_series);
printf("Enter no of centuries");
scanf("%d",&p[i].achieved.no_of_centuries);
}
}
void display( PLR p[10],int n)
{
int i;
for(i=0;i<n;i++)
{
printf ( "Player Name: %s\n",p[i].player_name);
printf ( "Team Name: %s\n",p[i].team_name);
printf ( "ODI rank: %d\n",p[i].ODI_rank);
printf ( "man_0f_the_match: %d\n",p[i].achieved. man_of_matches);
printf("man_of_the_series: %d\n",p[i].achieved.man_of_series);
printf("no_of_centuries:%d\n",p[i].achieved.no_of_centuries);
}
}
