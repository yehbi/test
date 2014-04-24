#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node NODE;
struct node
{
    int len;
    int point;
    int use;
    NODE *next;
    int num;
};
NODE arr[50];
int stac[2000]={0};
int top;
int isdone[2000]={0};
void fun(int x,int xlen);
int main()
{
    int a,b,c,endd=0;
    int asmall;
    int i;
    for(i=0;i<50;i++)
    {
        arr[i].next=NULL;
        arr[i].num=0;
    }
    top=0;
    int flag=0;
    int first=0;
    NODE *head=NULL,*tmp=NULL;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if(a==0&&b==0&&endd==0)
        {
            /*printf("%d %d\n",asmall,lensmall);
            for(i=1;i<=3;i++)
            {
                head=&arr[i];
                head=head->next;
                printf("%d \n",i);
                while(head!=NULL)
                {
                    printf("%d %d\n",head->point,head->len);
                    head=head->next;
                }
            }
            printf("======================\n");*/
            for(i=1;i<50;i++)
            {
                if(arr[i].num%2==1)
                {
                    printf("Round trip does not exist.\n\n");
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                fun(asmall,0);
                for(i=top-2;i>=1;i--)
                printf("%d ",stac[i]);
                printf("%d\n\n",stac[0]);
                memset(stac,0,sizeof(stac));
                memset(isdone,0,sizeof(isdone));
                top=0;

            }
            flag=0;
            endd=1;
            for(i=0;i<50;i++)
            {
                arr[i].next=NULL;
                arr[i].num=0;
            }
            first=0;
        }
        else if(a==0&&b==0&&endd==1)
        {
            break;


        }
        else
        {

            endd=0;
            scanf("%d",&c);

            if(first==0)
            {

                asmall=a<b?a:b;
                first=1;
            }
            head=&arr[a];
            head->num++;
            while(head->next!=NULL&&head->next->len<c)
                head=head->next;
            tmp=(NODE *)malloc(sizeof(NODE));
            tmp->point=b;
            tmp->len=c;
            tmp->use=0;
            tmp->next=head->next;
            head->next=tmp;

            head=&arr[b];
            head->num++;
            while(head->next!=NULL&&head->next->len<c)
                head=head->next;
            tmp=(NODE *)malloc(sizeof(NODE));
            tmp->point=a;
            tmp->len=c;
            tmp->use=0;
            tmp->next=head->next;
            head->next=tmp;

        }


    }
    return 0;

}
void fun(int x,int xlen)
{
    /*NODE *s=&arr[x];
    s=s->next;
    while(s!=NULL)
    {
        if(s->len==xlen)
            break;
        else s=s->next;
    }
    s->use=1;

    NODE *t=&arr[s->point];
    t=t->next;
    while(t!=NULL)
    {
        if(t->point==x&&t->len==xlen)
            break;
        else t=t->next;
    }
    t->use=1;*/

    NODE *hd;
    hd=&arr[x];
    hd=hd->next;
    isdone[xlen]=1;
    while(hd!=NULL)
    {
        if(isdone[hd->len]==0)
        {

            fun(hd->point,hd->len);
        }



        hd=hd->next;

    }
    stac[top++]=xlen;

}
