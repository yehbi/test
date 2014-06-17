#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node NODE;
struct node
{
    int a[5][5];
    int step;
    NODE *next;
};
int repeat(NODE global[1000000],NODE *t);
NODE global1[1000000];

void lastcmp();
int ans;

NODE *head;
NODE *tail;
int last[5][5]={0};

int main()
{


    int mov[8][2]={{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2}};

    int test,i,j,k;
    NODE *newone;
    NODE *cur;
    NODE *tmp;
    cur=NULL;
    newone=NULL;
    head=NULL;
    tail=NULL;
    int m,n;
    int flag=2;


    int x ,y,x2,y2,re;
    char c;

    int t2;

    for(i=0;i<5;i++)
    {

        for(j=0;j<5;j++)
        {
            if(i>j)last[i][j]=0;
            else last[i][j]=1;
        }
    }
    last[2][2]=2;
    last[3][3]=0;
    last[4][4]=0;

    scanf("%d",&test);



    c=getchar();

    for(t2=0;t2<test;t2++)
    {


        for(i=0;i<1000000;i++)
        {
            global1[i].next=NULL;

        }
        head=(NODE*)malloc(sizeof(NODE));


        ans=-1;
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                c=getchar();
                if(c=='1')head->a[i][j]=1;
                if(c=='0')head->a[i][j]=0;
                if(c==' ')
                {
                    head->a[i][j]=2;
                    x=i;
                    y=j;
                }
            }
            c=getchar();
        }
        head->step=0;



        /*for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                printf("%d",arr[i][j]);

            }
            printf("\n");
        }*/


        tail=head;
        flag=2;
        for(m=0;m<5;m++)
        {
            for(n=0;n<5;n++)
            {
                if(last[m][n]!=head->a[m][n])
                {
                    flag=1;
                    break;
                }
                else
                    flag=0;
            }
            if(flag==1)
                break;
        }

    cur=(NODE*)malloc(sizeof(NODE));
    cur->step=0;
    if(flag!=0)
    {


        while(head!=NULL&&head->step<10)
        {
            for(m=0;m<5;m++)
            {
                for(n=0;n<5;n++)
                {
                    if(head->a[m][n]==2)
                    {
                        x=m;
                        y=n;
                        break;
                    }
                }
            }

            for(k=0;k<8;k++)
            {

                for(m=0;m<5;m++)
                {
                    for(n=0;n<5;n++)
                    {
                        cur->a[m][n]=head->a[m][n];
                    }
                }
                cur->step=head->step;

                x2=x+mov[k][0];
                y2=y+mov[k][1];
                if(x2>=0&&y2>=0&&x2<5&&y2<5)
                {


                    cur->a[x][y]=cur->a[x2][y2];
                    cur->a[x2][y2]=2;
                    cur->step=head->step+1;
                    flag=2;
                    for(m=0;m<5;m++)
                    {
                        for(n=0;n<5;n++)
                        {
                            if(last[m][n]!=cur->a[m][n])
                            {
                                flag=1;
                                break;
                            }
                            else
                            flag=0;
                        }
                        if(flag==1)
                        break;
                    }
                    if(flag==0)break;

                    re=repeat(global1,cur);

                    if(re==0)
                    {
                        newone=(NODE*)malloc(sizeof(NODE));
                        newone->step=cur->step;
                        for(i=0;i<5;i++)
                        {
                            for(j=0;j<5;j++)
                            newone->a[i][j]=cur->a[i][j];
                        }
                        newone->next=NULL;
                        tail->next=newone;
                        tail=tail->next;


                    }

                }


            }
            if(flag==0)break;
            tmp=head;
            head=head->next;
            free(tmp);





        }
    }



        /*for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                printf("%d",head2->a[i][j]);

            }
            printf("\n");
        }*/

        /*lastcmp();*/
        if(flag!=0)
            printf("Unsolvable in less than 11 move(s).\n");
        else
            printf("Solvable in %d move(s).\n",cur->step);




        while(head!=NULL)
        {

            tail=head;
            head=head->next;
            free(tail);

        }
    }

    return 0;
}

int repeat(NODE glob[1000000],NODE *t)
{

    int arr[25]={0};
    int i,j,k;
    k=0;
    int re;
    NODE *tmp=NULL;
    NODE *newone=NULL;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            arr[k++]=t->a[i][j];
    }

    k=arr[0];

    for(i=1;i<25;i++)
    {
        k=k*2;
        k=k+arr[i];
        k=k%1000000;
    }

    tmp=&glob[k];

    re=0;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
        re=0;
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(tmp->a[i][j]==t->a[i][j])
                {
                    re=1;
                }
                else
                {
                    re=0;
                    break;
                }
            }
            if(re==0)break;

        }
        if(re==1)break;


    }
    if(re==0)
    {


        newone=(NODE*)malloc(sizeof(NODE));
        newone->step=t->step;
        tmp=&glob[k];
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            newone->a[i][j]=t->a[i][j];
        }
        newone->next=tmp->next;
        tmp->next=newone;


    }
    return re;

}
