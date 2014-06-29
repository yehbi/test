#include<stdio.h>
#include<string.h>
int check[30000]={0};
int arr[30000]={0};
int main(void)
{
    int x,y;
    int num;
    num=0;
    int i;
    int lo ;/*long*/
    while(scanf("%d %d",&x,&y)!=EOF)
    {
        num=0;
        printf("%d/%d = %d.",x,y,x/y);
        x=x%y;
        x=x*10;

        while(check[x]==0)
        {
            arr[num]=x;
            num++;
            check[x]=1;
            x=x%y;
            x=x*10;
        }
         for(i=0;arr[i]!=x;i++)
        {
            printf("%d",arr[i]/y);
            check[arr[i]]=0;
        }
        printf("(");
        lo=i;
        for( ;i<num;i++)
        {
            if(i==50)
                break;

            else
            {
                printf("%d",arr[i]/y);
                check[arr[i]]=0;
            }


        }
        if(i<num)
        printf("...");
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n",num-lo);
        printf("\n");
        memset(check,0,sizeof(check));


    }
    return 0;
}
