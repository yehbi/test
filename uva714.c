#include<stdio.h>
#include<string.h>
int check(long long int mid);
long long int m,k;
long long int num;
long long int sum[600]={0},page[600]={0},use[500]={0};
int main()
{
    long long int i;
    int test,t;
    long long int low,up,mid;
    long long int cnt ,s;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%lld %lld",&m,&k);
        low=0;
        for(i=0;i<m;i++)
        {
            scanf("%lld",&page[i]);
            sum[i+1]=sum[i]+page[i];
            low=(page[i]>low)?page[i]:low;
        }
        up=sum[m];

        while(low<=up)
        {
            mid=(low+up)/2;
            /*printf("low=%lld up=%lld\n",low,up);*/
            if(check(mid)==1)
            {

                up=mid-1;

            }
            else
            {

                low=mid+1;


            }

        }

        cnt=0;
        s=0;
        for(i=m-1;i>=0;i--)
        {
            if(s+page[i]>low||k-cnt>i+1)
            {
                use[i]=1;
                cnt++;
                s=page[i];

            }
            else
            s=s+page[i];

        }
        for(i=0;i<m-1;i++)
        {
            printf("%lld ",page[i]);
            if(use[i]==1)
            printf("/ ");

        }
        printf("%lld\n",page[m-1]);
        memset(page,0,sizeof(page));
        memset(use,0,sizeof(use));
        memset(sum,0,sizeof(sum));
    }
    return 0;
}

int check(long long int mid)
{
    long long int i,tail,head;
    tail=1;
    head=0;
    num=0;

    while(tail<=m)
    {
        num++;
        while(sum[tail]-sum[head]<=mid&&tail<=m)
        {
            tail++;
            /*printf("num=%lld t=%lld\n",num,tail);*/
        }
        head=tail-1;

    }


    if(num>k)
    return 0;
    else
    return 1;
}
