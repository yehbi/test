#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void dfs(int num,int col);
typedef struct node NODE;
struct node
{
    int val,col;
    NODE *next;
};
NODE arr[10000];
int ans=0;
int done[10000]={0};
int main()
{
    int n,i,n2,j2,a,b;
    NODE *head,*next,*temp;
    head=temp=next=NULL;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;



        for(i=1;i<=n;i++)
        {
            arr[i].next=NULL;


        }
        scanf("%d",&n2);
       
        for(j2=1;j2<=n2;j2++)
        {
            scanf("%d %d",&a,&b);
            head=&arr[a];
            while(head->next!=NULL&&head->next->val<b)
            head=head->next;
            temp=(NODE*)malloc(sizeof(NODE));
            temp->val=b;
            temp->next=head->next;
            head->next=temp;

            head=&arr[b];
            while(head->next!=NULL&&head->next->val<a)
            head=head->next;

            temp=(NODE*)malloc(sizeof(NODE));
            temp->val=a;
            temp->next=head->next;
            head->next=temp;
            


        }
        for(i=1;i<=n;i++)
        {
            if(done[i]==0)
            dfs(i,0);

        }

        if(ans==1)
        printf("You discover a BIG Secret!!\n");
        else
        printf("Successful\n");
        for(i=1;i<=n;i++)
        {
           
            head=&arr[i];
            while(head->next!=NULL)
            {
                temp=head->next;
                head=head->next;
                free(temp);
            }
            
            done[i]=0;
            
        }
        

        ans=0;





    }

    return 0;
}
void dfs(int num,int col)
{
    done[num]=1;

    NODE *hd;
    hd=&arr[num];
    arr[num].col=col;
    /*hd->val=col;*/
   /* printf("!!%d %d\n",num,arr[num].col);*/
    hd=hd->next;
    while(hd!=NULL)
    {
        if(done[hd->val]==0)
        {
            hd->col=(arr[num].col+1)%2;
           /* printf("!%d %d\n",hd->val,hd->col);*/
            dfs(hd->val,hd->col);
        }
        else if(done[hd->val]==1)
        {
           /* printf("val=%d\n",hd->val);*/

            if(arr[hd->val].col==arr[num].col)
            {
              /*   printf("?%d %d\n",arr[hd->val].col,arr[num].col);*/

                ans=1;
            }

        }
        hd=hd->next;
    }

}
