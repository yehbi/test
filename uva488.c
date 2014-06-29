#include<stdio.h>
int main(void)
{
    int num,i,j,m,n;
    int big,times,flag;

    while(scanf("%d",&num)!=EOF)
    {
        flag=0;
        for(i=1;i<=num;i++)
        {
            if(flag!=0)
            printf("\n");
            flag++;
            scanf("%d %d",&big,&times);
            for(j=1;j<=times;j++)
            {
                for(m=1;m<=big;m++)
                {
                    for(n=1;n<=m;n++)
                    {
                        printf("%d",m);
                    }
                    printf("\n");
                }
                for(m=big-1;m>=1;m--)
                {
                    for(n=1;n<=m;n++)
                    {
                        printf("%d",m);
                    }
                    printf("\n");
                }
                if(j!=times)
                printf("\n");
            }
        }
    }
    return 0;
}
