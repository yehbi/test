#include<stdio.h>
long long int arr[1000002]={0};
int main()
{
    
    long long int n,m,t;
    while(scanf("%lld",&n)!=EOF)
    {
        m=n;
        t=n;
        while(n>1)
        {
            if(arr[t]!=0)
            {
               
                m=m>arr[t]?m:arr[t];
                
                n=1;
            }
            else
            {
                if(n%2==0)
                n=n/2;
                else
                n=3*n+1;
                
                m=m>n?m:n;
            }
            
        }
        arr[t]=m;
      
        printf("%lld\n",m);
        
    }
    return 0;
}
