#include<stdio.h>
int main(void)
{
    long long int n,m,n1,m1;
    long long int ans;
    long long int i,j;
    while(scanf("%lld %lld",&n1,&m1)!=EOF)
    {
        if(n1==0&&m1==0)
        break;

        n=(n1>=m1)?n1:m1;
        m=(n1<=m1)?n1:m1;

        i=j=1;
        if(m>n/2)
        m=n-m;
        for(i=1;i<=m;i++)
        {
            j=j*n/i;
            n=n-1;

        }
        ans=j;

        printf("%lld\n",ans);
    }
    return 0;
}

