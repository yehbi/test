#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int done[10000]={0};
int dfs(int num);
int first=1;
typedef struct node NODE;
struct node
{
    int value;
    NODE *next;
};
NODE arr[10000]={0};
NODE *temp,*head,*next;
int ch[10000]={0};
int p=0;
int stack[10000]={0};
int main(void)
{
    int n,m,num1,num2;
    int i;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
        break;
        for(i=1;i<=n;i++)
        {
            arr[i].next=NULL;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&num1,&num2);
            head=&arr[num1];
            while(head->next!=NULL&&head->next->value<num2)
            head=head->next;
            temp=(NODE*)malloc(sizeof(NODE));
            temp->value=num2;
            temp->next=head->next;
            head->next=temp;
            ch[num2]=1;
        }
        for(i=1;i<=n;i++)
        {
            if(ch[i]==0)
            dfs(i);
        }
        
        printf("%d",stack[p-1]);
        for(i=p-2;i>=0;i--)
        printf(" %d",stack[i]);
        for(i=1;i<=n;i++)
        {
            arr[i].next=NULL;
        }
        p=0;
        memset(stack,0,sizeof(stack));
        memset(done,0,sizeof(done));
        memset(ch,0,sizeof(ch));
        printf("\n");
        
        
        
    }
    
    return 0;
}
int dfs(int num)
{
    int k;
    done[num]=1;
    
    NODE *hd;
    hd=&arr[num];
    hd=hd->next;
    while(hd!=NULL)
    {
        if(!done[hd->value])
        dfs(hd->value);
        
        hd=hd->next;
    }
    stack[p]=num;
    p++;
}
