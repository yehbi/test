#include<stdio.h>
#include<string.h>
char stack[1002]={0};
int top=0;
void push(char c);
char pop();
int main(void)
{
    int num,i,no;
    char c;
    while(scanf("%d",&num)!=EOF)
    {
        c=getchar();
        for(i=1;i<=num;i++)
        {
            while(c=getchar())
            {
                if(c>='0'&&c<='9')
                {
                    ungetc(c,stdin);
                    scanf("%d",&no);
                    printf("%d",no);
                }
                else if(c=='(')
                    push(c);
                else if(c==')')
                {
                    if(stack[top]=='(')
                       pop();
                    while(stack[top]!='(')
                    {
                        if(top>0)
                        printf("%c",pop());
                        if(stack[top]=='(')
                        {
                            pop();
                            break;
                        }
                        if(top==0)
                        break;
                    }
                }
                else if(c=='+'||c=='-')
                {
                    while(top!=0&&stack[top]!='(')
                    printf("%c",pop());
                    push(c);

                }
                else if(c=='*'||c=='/')
                {
                    while(top!=0&&(stack[top]=='*'||stack[top]=='/'))
                    printf("%c",pop());
                    push(c);

                }
                else if("\n")
                {
                    while(top!=0)
                    printf("%c",pop());
                    printf("\n");
                    top=0;
                    break;
                }



            }


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
