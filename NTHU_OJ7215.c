#include<stdio.h>
int times[100000]={0};
int main (void)
{
    int n,num,i,flag;
    int big;
    int flag2=0;

    while(scanf("%d",&num)!=EOF)
    {
        n=2;
        big=0;
        flag=0;
        flag2=0;
        while(num>=2)
        {
            if(n>10000)break;
            if(num%n==0)
            {
                times[n]=times[n]+1;
                num=num/n;
                flag=n;
            }
            else
            {
                n++;
            }
        }
        if(num!=1)/*big means big prime */
        {
            big=num;
        }
        for(i=0;i<=flag;i++)
        {
            if(times[i]!=0)
            {
                printf("%d^%d",i,times[i]);
                if(i!=flag)
                printf("*");
                flag2=1;
                times[i]=0;/*clear*/
            }

        }
        if(big!=0)
        {
            if(flag2==1)
            printf("*%d^1",big);
            else
            printf("%d^1",big);
        }

        printf("\n");


    }
    return 0;
}
