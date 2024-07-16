//Write a program to sort the structure using ODI_rank.
#include<stdio.h>
typedef struct cricket_player
{ char player_name[20];
char team_name[20];
float average;
int highest_score;
int centuries;
int ODI_rank;
}PLR;
PLR read( PLR);
void display( PLR);
void highest_rank(PLR,PLR,PLR);
main()
{
PLR p1,p2,p3;
p1=read(p1);
p2=read(p2);
p3=read(p3);
display(p1);
display(p2);
display(p3);
printf("Details of the players who scored Highest rank\n");
highest_rank(p1,p2,p3);
}
PLR read( PLR p1)
{
printf ( "\nEnter player name ");
scanf ("%s", p1. player_name );
printf ( "\nEnter team name ");
scanf ("%s", p1. team_name );
printf ( "\nEnter Batting average");
scanf ("%f",&p1.average);
printf ( "\nEnter highest score");
scanf ("%d", &p1. highest_score );
printf ( "\nEnter Centuries ");
scanf ("%d", &p1. centuries );
printf ( "\nEnter ODI rank");
scanf ("%d", &p1. ODI_rank);
return p1;
}
void display( PLR p1)
{
printf ( "Player Name: %s\n",p1.player_name);
printf ( "Team Name: %s\n",p1.team_name);
printf ( "Average: %f\n",p1.average);
printf ( "Highest score: %d\n",p1.highest_score);
printf ( "Centuries: %d\n",p1.centuries);
printf ( "ODI rank: %d\n",p1.ODI_rank);
}
void highest_rank(PLR p1,PLR p2,PLR p3)
{
if((p1.ODI_rank>=p2.ODI_rank)&&(p1.ODI_rank>=p3.ODI_rank))
display(p1);
else if(p2.ODI_rank>=p3.ODI_rank)
display(p2);
else
display(p3);
}
