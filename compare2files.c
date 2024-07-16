#include<stdio.h>
void compareFiles(FILE *fp1, FILE *fp2)
{

    char ch1 = getc(fp1);
    char ch2 = getc(fp2);

    int error = 0;
    while (ch1 != EOF && ch2 != EOF)
    {
        if (ch1 != ch2)
        {
            error++;
            break;
        }
        ch1 = getc(fp1);
        ch2 = getc(fp2);
    }
    if(error>0)
        printf("Both the file content are not same\n ");
    else
        printf("Both the file content are same\n ");
}

main()
{

    FILE *fp1 = fopen("file1.txt", "r");
    FILE *fp2 = fopen("file2.txt", "r");

    if (fp1 == NULL || fp2 == NULL)
    {
       printf("Error : Files not open");
       exit(0);
    }

    compareFiles(fp1, fp2);
    fclose(fp1);
    fclose(fp2);
}
