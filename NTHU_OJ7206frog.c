#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long int stone[500000]={0};
long long int dis[500000]={0};
int com(const void *p, const void *q);
long long int test(long long int mid);
long long int sh;
long long int L,N,M;
int main(void)
{

    long long int t,i;
    long long int low,up,mid;

    while(scanf("%lld %lld %lld",&L,&N,&M)!=EOF)
    {
        sh=L;
        stone[0]=0;
        for(i=1;i<=N;i++)
        scanf("%lld",&stone[i]);
        stone[i]=L;
        qsort(stone,N+1,sizeof(long long int),com);

        for(i=0;i<=N;i++)
        {
            dis[i]=stone[i+1]-stone[i];

        }
        qsort(dis,N+1,sizeof(long long int),com);

        /*for(i=0;i<=N;i++)
        printf("%lld ",dis[i]);*/


        low=dis[N];
        up=L;

        while(low<=up)
        {
            mid=(low+up)/2;
            if(mid*M>=L)
            {
                t=test(mid);
                if(t==1)
                up=mid-1;
                else
                low=mid+1;
            }
            else
            {
                low=mid+1;
            }
            

        }

        printf("%lld\n",sh);

        for(i=0;i<=N+1;i++)
        {
            stone[i]=0;
            dis[i]=0;
        }



    }
    return 0;
}
int com(const void *p, const void *q)
{
    long long int a=*((long long int*)p),b=*((long long int*)q);
    if(a!=b)return a>b?1:-1;
    return 0;
}
long long int test(long long int mid)
{
    long long int i,tail,head,num;
    tail=1;
    head=0;
    num=0;
    while(tail<=N+1)/*FOR */
    {
        num++;
        while(mid>=stone[tail]-stone[head]&&tail<=N+1)
        tail++;
        head=tail-1;

    }
    if(num>M)
    return 0;
    else
    {
        if(mid<sh)
        sh=mid;
        return 1;

    }
}
