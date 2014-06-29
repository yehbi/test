#include<stdio.h>
#include<ctype.h>
int str[10000]={0};
char ch[10000][100]={0};
int main (void)
{
    int num,i,j,k,len,flag;
    int order;

    char c;

    freopen("e.txt","r",stdin);
    freopen("ans.txt","w",stdout);
    while(scanf("%d",&num)!=EOF)
    {
        flag=0;

        for(i=1;i<=num;i++)
        {
            j=0;
            while(scanf("%d%c",&order,&c)!=EOF&&c!='\n')
            {

                    str[j]=order;
                    j++;

            }
            str[j]=order;/*last one*/
            len=j+1;
            for(k=0;k<=len-1;k++)/*scanf*/
            {

                for(j=0;j<=100;j++)
                {
                    scanf("%c",&ch[str[k]][j]);
                    if(ch[str[k]][j]==' '||ch[str[k]][j]=='\n')
                    {
                        break;
                    }

                }

            }

            if(flag==1)
            printf("\n");
            flag=1;
            for(k=1;k<=len;k++)
            {
                for(j=0;j<=100;j++)
                {
                    if(ch[k][j]==' '||ch[(k)][j]=='\n')
                    break;
                    else
                    printf("%c",ch[k][j]);

                }
                printf("\n");
            }
            for(k=0;k<=len;k++)/*clear*/
            {
                for(j=0;j<=100;j++)
                {

                    ch[k][j]=' ';

                }
                str[k]=0;
            }


        }

    }

    return 0;
}
