#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void push(int n);
int pop();
int top=0;
int stk[1000]={0};
int main(void)
{
    int ti,n1,n2;
    int i,j;
    char c,c2;
    int num;

    while(scanf("%d",&ti)!=EOF)
    {
        c=getchar();
        for(i=1;i<=ti;i++)
        {
            scanf("%d",&num);

            while((c=getchar()))
            {
                if(c=='-')
                {
                    c2=getchar();
                    if(c2>='0'&&c2<='9')
                    {
                        ungetc(c2,stdin);
                        scanf("%d",&n1);
                        n1=0-n1;
                        push(n1);
                    }
                    else if(c2==' ')
                    {
                        n1=pop();
                        n2=pop();
                        n1=n2-n1;
                        push(n1);
                    }
                    else if(c2=='\n')
                    {
                        n1=pop();
                        n2=pop();
                        n1=n2-n1;
                        push(n1);
                        n1=pop();
                        printf("%d\n",n1);
                        break;
                    }
                }
                else if(c=='+')
                {
                    n1=pop();
                    n2=pop();
                    n1=n1+n2;
                    push(n1);

                }
                else if(c>='0'&&c<='9')
                {
                    ungetc(c,stdin);
                    scanf("%d",&n1);
                    push(n1);
                }
                else if(c=='\n')
                {
                    n1=pop();
                    printf("%d\n",n1);
                    break;
                }
            }
            while(top!=0)
            {
                pop();
                stk[top]=0;

            }
         /*   for(j=top;j<=0;j--)
                ;*/
            top=0;
        }
    }
    return 0;
}
void push(int n)
{
    stk[++top]=n;
}
int pop()
{
    return stk[top--];
}
