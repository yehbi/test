#include<stdio.h>
int ans(long long int b,long long int p,long long int m);
int main(void)
{
    long long int b,p,m;
    while(scanf("%lld %lld %lld",&b,&p,&m)!=EOF)
    {
        printf("%d\n",ans(b,p,m));
    }
    return 0;

}
int ans(long long int b,long long int p,long long int m)
{
    if(m==1)
        return 0;
    if(p==0)
        return 1;

    else if(p==1)
        return b%m;
    else
    {
        long long int a=ans(b,p/2,m);
        if(p%2==1)
        return a*a*b%m;
        else
        return a*a%m;

    }

}
