#include<stdio.h>

int main(void)
{

    int num,i,j,a,b,sum;

    while(scanf("%d",&num)!=EOF)
    {
        for(i=1;i<=num;i++)
        {
            scanf("%d %d",&a,&b);
            if(a%2==0)
            a=a+1;

            sum=0;

            if(b%2==0)
            b=b-1;
            for(j=a;j<=b;j=j+2)
            {
               // printf("sum=%d\n",sum);
              //  printf("j=%d\n",j);
                sum=sum+j;

            }
            printf("Case %d: %d\n",i,sum);
        }
    }

    return 0;
}
