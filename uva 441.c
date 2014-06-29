#include<stdio.h>
int main(void)
{
    int a[15],c[15],i,j,num,t;
    t=0;
    while(scanf("%d",&num)!=EOF&&num!=0)
    {
        if(t!=0)
        printf("\n");
        t=1;
        for(i=0;i<num;i++)
        scanf("%d",&a[i]);
        for(i=0,c[i]=-1;i>=0;)
        {
            if(i==6)
            {
                for(j=0;j<6;j++)
                {
                    if(j==5)
                    printf("%d\n",a[c[j]]);
                    else
                    printf("%d ",a[c[j]]);
                }
                i--;
            }
            else if(++c[i]>=num)
            {
                i--;

            }
            else
            {
                c[i+1]=c[i];

                i++;
            }
        }
    }
    return 0;
}
