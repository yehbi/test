#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long int fun(long long int n);

long long int done[50000]={0};
long long int a[50000]={0};
int main()
{

    long long int num;
    while(scanf("%lld",&num)!=EOF)
    {

        printf("%lld\n",fun(num));
    }
    return 0;
}

long long int fun(long long int n)
{
    if(n==1)
        return 1;
    else if(2<=n&&n<=13)
        return ((fun(n-1))*(4*n-2)/(n+1))%1573921;
    else if(n>13)
    {
        long long int k,mi,tmp;
        if(done[n]==1)
            return a[n];
        else
        {
            mi=1573921;

            for(k=1;k<=10;k++)
            {
                tmp=(k*(fun(n-k))*(fun(n-(10-k+1))))%1573921;
                mi=(tmp<mi)?tmp:mi;
               /* a[k-1]=tmp;*/

            }
           /* qsort(a,10,sizeof(long long int),cmp);*/
            a[n]=mi;
            done[n]=1;
            return mi;
        }
    }
    else
        return 0;

}
