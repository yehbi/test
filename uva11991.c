#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node NODE;
struct node
{
    int order,val;
    int times;
};
NODE arr[100000]={0};
int ti[1000000]={0};
int cmp(const void *p,const void *q);
int main(void)
{
    int n,m;
    int i,j;
    int k,v;
    int up,low,mid;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(ti,0,sizeof(ti));
        memset(arr,0,sizeof(arr[0]));
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i].val);
            ti[arr[i].val]++;
            arr[i].times=ti[arr[i].val];
            arr[i].order=i;
        }
        qsort(arr,n,sizeof(NODE),cmp);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&k,&v);
            low=0;
            up=n-1;


            if(k>ti[v])
            printf("0\n");
            else
            {
                while(low<=up)
                {
                    mid=(low+up)/2;
                    if(arr[mid].val>v)
                    up=mid-1;
                    else if(arr[mid].val<v)
                    low=mid+1;
                    else
                    {

                        if(arr[mid].times>k)
                        up=mid-1;
                        else if(arr[mid].times<k)
                        low=mid+1;
                        else
                        break;

                    }
                }
                printf("%d\n",arr[mid].order+1);

            }


        }
    }
    return 0;
}
int cmp(const void *p,const void *q)
{
    NODE a=*((NODE*)p),b=*((NODE*)q);
    if(a.val!=b.val)return a.val>b.val?1:-1;
    if(a.times!=b.times)return a.times>b.times?1:-1;
    return 0;
}
