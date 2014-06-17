#include<stdio.h>
#include<string.h>
int dfs(int level,int sum);
int arr[1000000]={0};
int num,j=-1,total=0;
int b=0;
int mini=1000000;
int main()
{
    int i;

    while(scanf("%d",&num)!=EOF)
    {
        if(num==0)
            break;
        for(i=0;i<num;i++)
        {
            scanf("%d",&arr[i]);
            total=total+arr[i];

        }

        dfs(1,0);
        printf("%d\n",mini);
        mini=1000000;
        memset(arr,0,sizeof(arr));
        b=0;
        total=0;
        j=-1;
    }
    return 0;
}
int dfs(int level,int sum)
{
    if(level==num)
    {
        int delta;
        b=total-sum;
        delta=sum-b;
        if(delta<0)delta=0-delta;
        /*printf("%d=%d-%d\n",delta,sum,b);*/
        mini=(mini<delta)? mini:delta;

        return mini;
    }
    else
    {
        j++;
       /* printf("sum%d j=%d arr[j]%d\n",sum,j,arr[j]);*/
        dfs(level+1,sum+arr[j]);
        /*printf("sum%d\n",sum);*/
        dfs(level+1,sum);
        j--;

    }
    return mini;
}
