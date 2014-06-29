#include<stdio.h>
int rec(int n);
int ans,sum;
int main(void)
{
    while(scanf("%d",&sum)!=EOF)
    {
        ans=0;
        rec(0);
        if(ans==1)
        printf("yes\n");
        else
        printf("no\n");
        
    }
    return 0;
}
int rec(int n)
{
    char c;
    int node;
    int left,right;
    
    while((c=getchar())&&c!='(');
    while((c=getchar()))
    {
        if(c>='0'&&c<='9'||c=='-'||c==')')
        
        break;
    }
    if(c==')')
    {
        /*printf("a");*/
        return 0;
    }
    ungetc(c,stdin);
    scanf("%d",&node);
    /*printf("n=%d\n",node);*/
    left=rec(n+node);
    right=rec(n+node);
   /* printf("%d\n",n+node);*/
    if(left==0&&right==0&&(n+node)==sum)
    ans=1;
    while((c=getchar())&&c!=')');
    return 1;
    
}
