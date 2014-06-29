#include<stdio.h>
typedef struct node NODE;
struct node
{
    long long int a,b,c,d;
};

NODE ans(long long int n,long long int m);

int main(void)
{
    long long int n;
    long long int m,m0;
    int j;
    while(scanf("%lld %lld",&n,&m0)!=EOF)
    {
        m=1;
        for(j=1;j<=m0;j++)
        m=m*2;
        printf("%lld\n",ans(n-1,m).a);
    }

    return 0;
}
NODE ans(long long int n, long long int m)
{
    NODE sq;
    if(n==1)
    {
        sq.a=1;
        sq.b=1;
        sq.c=1;
        sq.d=0;

        return sq;
    }
    else
    {
        NODE k=ans(n/2,m);
        if(n%2==1)
        {


            sq.a=(k.a*k.a+k.b*k.c+k.a*k.b+k.b*k.d)%m;
            sq.b=(k.a*k.a+k.b*k.c)%m;
            sq.c=(k.c*k.a+k.d*k.c+k.c*k.b+k.d*k.d)%m;
            sq.d=(k.c*k.a+k.d*k.c)%m;
            return sq;
        }
        else
        {
            sq.a=(k.a*k.a+k.b*k.c)%m;
            sq.b=(k.a*k.b+k.b*k.d)%m;
            sq.c=(k.c*k.a+k.d*k.c)%m;
            sq.d=(k.c*k.b+k.d*k.d)%m;
            return sq;
        }


    }


}
