#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
typedef struct node NODE;
struct node
{
    int val;
    NODE *next;
};
int main()
{
    NODE *head,*tail,*next,*temp;
    head=tail=next=temp=NULL;
    int test;
    int t,i;
    int n,k,tempk;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d %d",&n,&k);
       

        temp=(NODE*)malloc(sizeof(NODE));
        temp->val=1;
        head=tail=temp;
        tail->next=NULL;
        for(i=2;i<=n;i++)
        {
            temp=(NODE*)malloc(sizeof(NODE));
            temp->val=i;
            tail->next=temp;
            tail=tail->next;


        }
        tail->next=head;
        head=tail;
      
       /* for(i=1;i<=n;i++)
        {
            printf("%d ",head->val);
            head=head->next;
        }*/
        while(n>1)
        {
           
            tempk=k%n;
            if(tempk==0)tempk=n;
          /*  printf(" tempk=%d: %d\n",tempk,head->val);*/
     
            for(i=1;i<tempk;i++)
            {
                head=head->next;
                    /*printf(" %d\n",head->val);*/
            }
            temp=head->next;
               printf(" dump==%d: \n",temp->val);
                
            head->next=head->next->next;
           
            free(temp);
            
            
            n--;
            
        }
        printf("Case %d: %d\n",t,head->val);

    }
    
    return 0;
}
