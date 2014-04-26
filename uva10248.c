#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int arr[10][10]={0};
void dfs(int x);
int stac[200]={0};
int use[10][10]={0};
int top;
int main()
{
   
    
    int n,m,i,j,a,b,flag;
    int out[10]={0};
    int in[10]={0};
    int firstout=1,last[2]={0},src[2]={0};
    memset(stac,-1,sizeof(stac));
    memset(last,-1,sizeof(last));
    while(scanf("%d %d",&m,&n)!=EOF)
    {
       
        
       
        for(i=m;i<=n;i++)
        {
            
            if(i>=10)
            {
                a=i/10;
                b=i%10;
                arr[a][b]=1;
                out[a]++;
                in[b]++;
              
            }
           
            
        }
        /*for(i=0;i<=9;i++)
        {
            printf("%d\n",i);
            for(j=0;j<=9;j++)
            if(arr[i][j]==1)
            printf(" %d\n",j);
        }*/
        for(i=0;i<=9;i++)
        {
            while(out[i]>in[i])
            {
                
                for(j=0;j<=9;j++)
                {
                    if(in[j]>out[j])
                    {
                      /*  printf("i=%d j=%d\n",i,j);
                        printf("outi%d ini%d outj%d inj%d\n",out[i],in[i],out[j],in[j]);*/
                        
                        arr[j][i]++;/*can be more than one edge*/
                      
                        out[j]++;
                        in[i]++;
                        last[0]=j;
                        last[1]=i;
                        break;
                        
                    }
                    
                }
                
            }
            
            
        }
        if(last[1]!=-1)
        {
            arr[last[0]][last[1]]--;/*i out>in   j in>out*/
            out[last[0]]--;/*record j as the end point in euler path, i as the start*/
            in[last[1]]--;
        }
        /*printf("lastin%d %d\n",last[0],last[1]);
        
        for(i=0;i<=9;i++)
        {
            printf("%d",i);
            printf("in%d out%d\n",in[i],out[i]);
            for(j=0;j<=9;j++)
            if(arr[i][j]>0)
            printf(" %d",j);
            printf("\n");
        }*/
        
        top=0;
        if(m==n)
        printf("%d\n",m);
        else 
        {
            if(last[1]!=-1)/*last[1]=-1 m,n single num*/
            dfs(last[1]);

            for(i=top-1;i>=0;i--)
            printf("%d",stac[i]);
            
            for(i=m;i<=n;i++)
            {
                flag=1;
                if(i<=9)
                {
                    for(j=0;j<top;j++)
                    {
                        if(stac[j]==i)
                        {
                            flag=0;
                            break;
                        }
                        else flag=1;
                    }
                    if(flag==1)
                    printf("%d",i);
                    
                }
                else break;
            }
            printf("\n");
            
        }
        memset(arr,0,sizeof(arr));
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        memset(use,0,sizeof(use));
        memset(stac,-1,sizeof(stac));
        memset(last,-1,sizeof(last));
        
        
        
    }
    return 0;
}
void dfs(int x)
{
    int k;
   
    for(k=0;k<=9;k++)
    {
        if(arr[x][k]>0)
        {
            arr[x][k]--;
            dfs(k);
        }
    }

     stac[top++]=x;
    
}
