// Write a modular C program to add two complex numbers using pointer to structures.c
#include<stdio.h>
typedef struct complex
{
float real, imag;
}COMP;
void read(COMP *);
void add(COMP *,COMP *,COMP *);
COMP read_complex(COMP *a)
{
scanf("%f%f",&a->real,&a->imag);
}
COMP add_complex(COMP *a, COMP *b,COMP *r)
{
r->real=a->real+b->real;
r->imag=a->imag+b->imag;
}
int main()
{
COMP c1,c2,c3,*a,*b,*result;
a=&c1;
b=&c2;
result=&c3;
printf("Enter a complex number 1 \n");
read_complex(a);
printf("Enter a complex number 2 \n");
read_complex(b);
add_complex(a,b,result);
printf("%f+i%f\n",c3.real,c3.imag);
}
