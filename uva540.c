#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node NODE;
struct node
{
  int value;
  NODE *next;
};
int team[1000000]={0};
NODE arr[1055]={0};
int order[1055]={0};
int main(void)
{
    int num2,num1;
    num2=0;
    int n1,n2;
    int i,j,or;
    char str[10]={0};
    NODE *head,*next ,*temp;
    int val;
    or=1;/*order*/
    int an;
    int po;
    int flagw=0;
    while(scanf("%d",&num1)!=EOF&&num1!=0)
    {
        flagw=0;
        po=1;
        or=1;
        an=1;
        num2++;
        printf("Scenario #%d\n",num2);
        memset(team,0,sizeof(team));
        for(i=1;i<=num1;i++)/*line*/
        {
            scanf("%d",&n1);/*member num*/
            for(j=1;j<=n1;j++)
            {
                scanf("%d",&n2);
                team[n2]=i;/*each member in which team;*/
            }

        }
        memset(order,0,sizeof(order));
        for(i=1;i<=1001;i++)
		{
			arr[i].next=NULL;/*clear*/
		}
        head=NULL;
        while(scanf("%s",str))
        {

            if(str[0]=='E')/*enqueue*/
            {
                scanf("%d",&val);
                if(team[val]==0)/*no member in group*/
                {
                    num1=num1+1;
                    team[val]=num1;
                }
                if(order[team[val]]==0)
                {
                    order[team[val]]=or;/*r start =1*/
                    head=&arr[or];

                    temp=(NODE *)malloc(sizeof(NODE));
                    temp->value=val;
                    temp->next=head->next;
                    head->next=temp;
                    or++;
                }
                else/*in one of the team*/
                {
                    j=order[team[val]];
                    head=&arr[j];
                    while(head->next!=NULL)/*check if first num*/
                    head=head->next;

                    temp=(NODE *)malloc(sizeof(NODE));
                    temp->value=val;
                    temp->next=head->next;
                    head->next=temp;

                }

            }
            else if(str[0]=='D')/*dequeue*/
            {
                /*if(arr[po].next==NULL)
                {
                    po++;
                    order[an]=0;
                    
                }
                if(arr[po].next!=NULL)
                {
                    
                    an=team[arr[po].next->value];
                    printf("%d\n",arr[po].next->value);
                    temp=arr[i].next;
                    arr[po].next=arr[po].next->next;
                    free(temp);
                    if(arr[po].next==NULL)
                    {
                        po++;
                        order[an]=0;
                    
                    }
                }*/
                i=1;
                while(arr[i].next==NULL)
                {
                    order[an]=0;
                    i++;
                    if(i>or)
                    {
                        flagw=1;
                        break;
                    }
                }
                if(flagw==0)
                {
                    an=team[arr[i].next->value];
                    printf("%d\n",arr[i].next->value);
                    temp=arr[i].next;
                    arr[i].next=arr[i].next->next;
                    free(temp);
                    if(arr[i].next==NULL)
                    order[an]=0;
                }
                flagw=0;

            }
            else
            break;


        }
        printf("\n");



    }
    return 0;
}
