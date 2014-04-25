#include<stdio.h>
#include<string.h>
void pop();
void push(int x);
int now,size,parent,noneedswap,tmp;
int arr[100000]={0};

int main(void)
{
    int N,Q;
    int i,num,j,first=1,k;
    char str[5]={0};
    int bag=0;
    while(scanf("%d %d",&N,&Q)!=EOF)
    {
        size=0;
        bag=0;
        for(i=1;i<=Q;i++)
        {
            first=1;
            scanf("%s",str);
            scanf("%d",&num);
            if(str[0]=='P')
            {
                bag++;
                if(bag>N)
                {
                    
                    
                    if(arr[1]>num)
                    {
                        
                        pop();
                       
                        push(num);
                    }
                    bag--;
                    
                }
                else
                push(num);
                
                /*for(k=0;k<5;k++)
                printf("%d ",arr[k]);
                printf("\n");*/
            }
            else 
            {
                for(j=1;j<=num;j++)
                {
                    bag--;
                    if(first)
                    printf("%d",arr[1]);
                    else
                    printf(" %d",arr[1]);
                    
                    first=0;
                    pop();
                }
                printf("\n");
            }
            
        }
        
    }
    return 0;
}
void push(int x)
{
    size++;
    arr[size]=x;
    
    now=size;
    
    while(now>1)
    {
    
        parent=now/2;
        if(arr[parent]>=arr[now])
        break;
        
        
        tmp=arr[parent];
        arr[parent]=arr[now];
        arr[now]=tmp;
        now=parent;
    }
}
void pop()
{
    arr[1]=arr[size];
    arr[size]=0;
    size--;
    now=1;
    int change;
    while(2*now<=size)
    {
        noneedswap=1;
        if(arr[2*now]>arr[now])
        noneedswap=0;
        if(2*now+1<=size && arr[2*now+1]>arr[now])
        noneedswap=0;
        if(noneedswap)
        break;
        
        change=2*now;
        if(2*now+1<=size && arr[2*now+1]>arr[2*now])
        change=2*now+1;
        
        tmp=arr[now];
        arr[now]=arr[change];
        arr[change]=tmp;
        
        now=change;
    }
}


