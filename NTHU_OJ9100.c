#include<stdio.h>
#include<string.h>
void push(char c);
char pop();
char stack[1002]={0};
int top=0;
int main()
{
    char c,c2;
    int num,i;
    int flagno=0,flagy=0,flagem=0;
    while(scanf("%d",&num)!=EOF)
    {
        c=getchar();
        for(i=1;i<=num;i++)
        {
            while((c=getchar())!='\n')
            {
                if(c=='('||c=='{'||c=='<'||c=='[')
                   push(c);
                else if(c==')')
                {
                    if(top!=0)
                    c2=pop();
                    else
                    flagem=1;

                    if(c2=='(')
                    flagy=1;
                    else
                    flagno=1;
                }
                else if(c==']')
                {
                    if(top!=0)
                    c2=pop();
                    else
                    flagem=1;

                    if(c2=='[')
                    flagy=1;
                    else
                    flagno=1;
                }
                else if(c=='}')
                {
                    if(top!=0)
                    c2=pop();
                    else
                    flagem=1;

                    if(c2=='{')
                    flagy=1;
                    else
                    flagno=1;
                }
                else if(c=='>')
                {
                    if(top!=0)
                    c2=pop();
                    else
                    flagem=1;

                    if(c2=='<')
                    flagy=1;
                    else
                    flagno=1;
                }
            }
            while(top>0)
            {
                pop();
                flagno=1;
            }
            if(flagem==1||flagno==1)
            printf("Case %d: No\n",i);
            else
            printf("Case %d: Yes\n",i);
            memset(stack,'0',sizeof(stack));
            top=0;
            flagno=flagy=flagem=0;
        }

    }


    return 0;
}
void push(char c)
{
    stack[++top]=c;
}
char pop()
{
    return stack[top--];
}
