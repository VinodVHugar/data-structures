#include<stdio.h>
typedef struct cricket_player
{
    char player_name[30];
    char team_name[20];
    float average;
    int highest_score;
    int centuries;
    int ODI_rank;
}PLR;

void read (PLR p[],int n);
void display(PLR p[],int n);

main()
{
    PLR p[11];
    int n;
    printf("Enter number of player:");
    scanf("%d",&n);
    read(p,n);
    display(p,n);
}

void read (PLR p[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nEnter player name\n");
        scanf("%s",p[i].player_name);
        printf("Enter team name\n");
        scanf("%s",p[i].team_name);
        printf("Enter average\n");
        scanf("%f",&p[i].average);
        printf("Enter highest score\n");
        scanf("%d",&p[i].highest_score);
        printf("Enter centuries\n");
        scanf("%d",&p[i].centuries);
        printf("Enter ODI rank\n");
        scanf("%d",&p[i].ODI_rank);
    }
}

void display(PLR p[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n============\n");
    printf("player name:%s\n",p[i].player_name);
    printf("team name:%s\n",p[i].team_name);
    printf("average:%f\n",p[i].average);
    printf("Highest score:%d\n",p[i].highest_score);
    printf("Centuries:%d\n",p[i].centuries);
    printf("ODI rank:%d\n",p[i].ODI_rank);
    }
}
