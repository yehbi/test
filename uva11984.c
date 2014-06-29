#include<stdio.h>

int main(void)
{
    int num,i;
     double c,d,f;
    while(scanf("%d",&num)!=EOF)
    {
        for(i=1;i<=num;i++)
        {
            scanf("%lf %lf",&c,&d);
            f=c*9/5+32;
            c=(f+d-32)*5/9;
            printf("Case %d: %.2lf\n",i,c);
        }

    }




    return 0;
}

