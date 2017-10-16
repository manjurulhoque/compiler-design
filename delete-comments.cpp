#include<stdio.h>
#include<stdlib.h>

FILE *fp, *fp1;

int main()
{
    fp = fopen("comments.txt", "r");
    fp1 = fopen("without-comment.txt", "w");
    char a, b;

    while((a=fgetc(fp)) != EOF)
    {
        if(a == '/')
        {
            a = fgetc(fp);
            if(a == '/')
            {
                while((b = fgetc(fp)) != EOF)
                {
                    if(b == '\n')
                    {
                        printf("\n");
                        fputc('\n', fp1);
                        break;
                    }
                }
            }
            else if(a == '*')
            {
                while((b = fgetc(fp)) != '*')
                {
                    char c, d;
                    if(b == '*')
                    {
                        while((d = fgetc(fp)) == '/')
                        {
                            if(d == '/')
                            {
                                /// do nothing
                            }
                        }
                    }
                }
            }
        }
        else
        {
            putchar(a);
            fputc(a, fp1);
        }
    }


    return 0;
}
