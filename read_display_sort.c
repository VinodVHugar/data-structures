#include<stdio.h>
typedef struct student_information
{
    char student_name[20];
    char USN[20];
    int roll_number;
}SI;
void read (SI *R,int n);
void display(SI *R,int n);
void sort_by_roll_number(SI *R,int n);
main()
{
    SI R[100];
    int n;
    printf("enter the number of students \n");
    scanf("%d",&n);
    read (R,n);
    display (R,n);
    sort_by_roll_number(R,n);
    display(R,n);

}
void read (SI *R,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    printf("enter the student name\n");
    scanf("%s",R->student_name);
    printf("enter the USN\n");
    scanf("%s",R->USN);
    printf("enter the roll number\n");
    scanf("%d",&R->roll_number);
    R++;
  }
}
void display(SI *R,int n)
{
      int i;
      for(i=0;i<n;i++)
      {
          printf("student name:%s\n",R->student_name);
          printf("USN:%s\n",R->USN);
          printf("roll number:%d\n",R->roll_number);
          R++;

      }

}
void sort_by_roll_number(SI *R,int n)
{
    int i,j;
    SI temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if((*(R+j)).roll_number>(*(R+(j+1))).roll_number)
            {
                temp=(*(R+j));
                (*(R+j))=(*(R+(j+1)));
                (*(R+(j+1)))=temp;

            }
        }
    }
}
