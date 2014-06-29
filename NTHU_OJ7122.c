#include<stdio.h>
#include<string.h>
void mergesort(int b[50003][3],int left,int right,int order[50003]);
void merge(int b[50003][3],int left,int right,int mid,int order[50003]);
int c[50001][3]={0};


int main(void)
{
    int order[50003]={0};
   
    int b[50003][3]={0};
    int num,qu1,qu2,i,j;
    int cas=0;
    int left,right,mid;
    while(scanf("%d",&num)!=EOF)
    {
        cas++;
        
        printf("Case %d:\n",cas);
        
        
        for(i=0;i<num;i++)
        {
            scanf("%d",&b[i][0]);
            
            b[i][1]=0;
            b[i][2]=i;
        }
        left=0;
        right=i-1;
        mid=(left+right)/2;
        mergesort(b,left,right,order);
      
        scanf("%d",&qu1);
        for(i=0;i<qu1;i++)
        {
            scanf("%d",&qu2);
            printf("%d\n",order[qu2]);
        }
        printf("\n");
        memset(b,0,sizeof(b));
        memset(order,0,sizeof(order));
        
        memset(c,0,sizeof(c));
        
    }
    return 0;
}
void mergesort(int b[50003][3],int left,int right,int order[50003])
{
    int mid=(left+right)/2;
    if(left<right)
    {
        mergesort(b,left,mid,order);
        mergesort(b,mid+1,right,order);
        merge(b, left, right, mid,order);
    }
    
}
void merge(int b[50003][3],int left,int right,int mid,int order[50003])
{
    int i, j, k;
    i=left;
    j=mid+1;
    k=left;
    int flag=mid-i+1;
    while(i<=mid&&j<=right)
    {
        
        if(b[i][0]<b[j][0])
        {
          
            c[k][0]=b[j][0];
            b[j][1]=b[j][1]+flag;
            c[k][1]=b[j][1];
            c[k][2]=b[j][2];
            
            
            k++;
            j++;
             
            
            
        }
        else
        {
            if(flag>0)
            flag--;
            c[k][0]=b[i][0];
            c[k][1]=b[i][1];
            c[k][2]=b[i][2];
            k++;
            i++;
           
        }
    }
    while(i<=mid)
    {
        c[k][0]=b[i][0];
        
        c[k][1]=b[i][1];
        c[k][2]=b[i][2];
        k++;
        i++;
        
        
    }
    while(j<=right)
    {
        
        c[k][0]=b[j][0];
        
        c[k][1]=b[j][1];
        c[k][2]=b[j][2];
        
        k++;
        j++;
        
    }
    for(i=left;i<k;i++)
    {
        b[i][0]=c[i][0];
        b[i][1]=c[i][1];
        b[i][2]=c[i][2];
        order[b[i][2]]=c[i][1];
        
    }
}
