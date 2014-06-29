#include<stdio.h>
int main(void)
{
    int a,b,i,j;
    int ans[100]={0};
    int temp;
    while(scanf("%d %d",&a,&b)!=EOF)
    {

        i=0;
        while(a%b!=0)
        {
            ans[i]=a/b;
            i++;
            printf("%d %d\n",a,b);
            temp=b;
            b=a%b;
            a=temp;

        }
        ans[i]=a;
        printf("[%d;",ans[0]);
        for(j=1;j<=i;j++)
        {
            if(j!=i)
            printf("%d,",ans[j]);
            else
            printf("%d",ans[i]);


        }
        printf("]\n");
    }
    return 0;
}
