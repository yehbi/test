#include<stdio.h>
#include<ctype.h>
int aeiou(char c);
int main(void)
{
    char c,first;

    while((c=getchar())!=EOF)
    {
        if(isalpha(c))
        {
            if(aeiou(c)==1)
            {
                while(isalpha(c))
                {
                    printf("%c",c);
                    c=getchar();
                }
                printf("ay");
            }
            else
            {
                first=c;
                c=getchar();
                while(isalpha(c))
                {
                    printf("%c",c);
                    c=getchar();
                }
                printf("%cay",first);
            }
        }
        printf("%c",c);
    }
    return 0;
}
int aeiou(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
    return 1;
    else
    return 0;
}
