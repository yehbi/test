#include<stdio.h>
#include<string.h>
void put(int c);
int pop();
int top=0;
int stack[1002]={0};
int main(void)
{
    int i,num,c,exit,num2;
    int num3,conti;
    while(scanf("%d",&num)!=EOF&&num!=0)
    {
        exit=0;
        while(!exit)
        {
            conti=1;
            memset(stack,0,sizeof(stack));
            top=0;
            num3=1;
            for(i=1;i<=num;i++)
            {
                scanf("%d",&num2);
                if(num2==0)
                {
                    exit=1;
                    break;
                }
                if(conti)
                {
                    if(num3<num2)
                    {
                        for(;num3<num2;num3++)
                        put(num3);
                        num3++;

                    }
                    else if(num3==num2)
                    num3++;
                    else
                    {
                        if(num2!=pop())
                        conti=0;
                    }
                }

            }
            if(exit==1)
            break;
            else if(conti==1)
            printf("Yes\n");
            else
            printf("No\n");

        }
        printf("\n");
    }

    return 0;
}
void put(int c)
{
    stack[++top]=c;
}
int pop()
{
    return stack[top--];
}
