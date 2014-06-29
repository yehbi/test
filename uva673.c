#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void put(char c);
char pop();
char stack[200]={0};
int top=0;
int main(void)
{
    int i,num;
    char c;
    char c2;
    int flagno=0,flagy=0,flagem=0;
    while(scanf("%d",&num)!=EOF)
    {
        c=getchar();
        for(i=1;i<=num;i++)
        {
            while((c=getchar())!='\n')
            {
                if(c=='(')
                put(c);
                else if(c=='[')
                put(c);
                else if(c==']')
                {
                    if(top!=0)/*not empty*/
                    c2=pop();
                    else
                    flagem=1;
                    if(c2!='[')
                    flagno=1;
                    else
                    flagy=1;
                }
                else if(c==')')
                {
                    if(top!=0)/*not empty*/
                    c2=pop();
                    else
                    flagem=1;
                    if(c2!='(')
                    flagno=1;
                    else
                    flagy=1;

                }
            }
            while(top>0)
            {
                pop();
                flagno=1;
            }
            memset(stack,'0',sizeof(stack));
            if(flagno==1||flagem==1)
            printf("No\n");
            else
            printf("Yes\n");
            flagno=0;
            flagy=0;
            flagem=0;
        }
    }
    return 0;
}
void put(char c)
{
    stack[++top]=c;
}
char pop()
{
    return stack[top--];
}
