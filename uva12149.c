#include<stdio.h>

int main(void)
{
    int num,i,ans;
    while(scanf("%d",&num)!=EOF&&num!=0)
    {
        ans=0;
        for(i=1;i<=num;i++)
        {
            ans=ans+i*i;
        }
        printf("%d\n",ans);

    }
    return 0;
}
