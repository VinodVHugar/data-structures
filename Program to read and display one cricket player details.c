//Program to read and display one cricket player details.
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
main( )
{
PLR p1;
p1=read(p1);
display(p1);
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
