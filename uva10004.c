#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int done[10000]={0};
int dfs(int num,int col);
int first=1;
typedef struct node NODE;
struct node
{
    int value;
    NODE *next;
    int color;
};
NODE arr[10000]={0};
NODE *temp,*head,*next;

int flagb=0;
int main(void)
{
    int n,m,num1,num2;
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        break;
        scanf("%d",&m);
        for(i=0;i<=n;i++)
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
            temp->color=-1;
            temp->next=head->next;
            head->next=temp;
            
            head=&arr[num2];
            while(head->next!=NULL&&head->next->value<num1)
            head=head->next;
            temp=(NODE*)malloc(sizeof(NODE));
            temp->value=num1;
            temp->color=-1;
            temp->next=head->next;
            head->next=temp;
            
        }
        for(i=0;i<n;i++)
        {
            if(!done[i])
            dfs(i,0);
        }
        if(flagb==1)
        printf("NOT BICOLORABLE.");
        else
        printf("BICOLORABLE.");
        
        
        for(i=0;i<=n;i++)
        {
            arr[i].next=NULL;
        }
     
       /* memset(paint,0,sizeof(stack));*/
        memset(done,0,sizeof(done));
        
        printf("\n");
        flagb=0;
        
        
    }
    
    return 0;
}
int dfs(int num,int col)
{
    int k;
    done[num]=1;
    
    NODE *hd;
    hd=&arr[num];
    hd->color=col;
    hd=hd->next;
    while(hd!=NULL)
    {
        if(!done[hd->value])
        {
            
            dfs(hd->value,(col+1)%2);
          /* printf("c%d %d %d\n",hd->value,arr[hd->value].color,arr[num]);*/
            
        }   
        else
        {
            if(arr[hd->value].color==arr[num].color)
            {
                /*printf("r%d %d\n",arr[hd->value].color,arr[num].color);*/
            flagb=1;
            }
        }
        
        
        hd=hd->next;
    }
   
}
