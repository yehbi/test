#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int w[27][27]={0};
int arr[27][27]={0};
char nn[27][27]={0};
int main()
{

    int n,m;
    char s1[27]={0};
    char s2[27]={0};

    int num;
    int first=1;
    int exit;
    int i,j,k,a,b;
    int flag[27]={0};
    int cas=0;
    while(scanf("%d %d",&n,&m)!=EOF)
    {


        if(n==0&&m==0)break;
        for(i=0;i<n;i++)
        {
             for(j=0;j<n;j++)
             {
                 if(i==j)
                 w[i][j]=0;
                 else
                    w[i][j]=50000;
             }
        }




        for(i=0;i<m;i++)
        {
            scanf("%s %s",s1,s2);
            if(first==1)
            {
                strcpy(nn[0],s1);
                strcpy(nn[1],s2);
                w[0][1]=1;
                num=2;
                first=0;
            }
            else
            {
                for(j=0;j<num;j++)
                {
                    if(strcmp(nn[j],s1)==0)
                    {
                        exit=1;

                        break;
                    }
                    else
                        exit=0;


                }
                if(exit==0)
                {
                    strcpy(nn[j],s1);

                    num++;
                }
                a=j;
                for(j=0;j<num;j++)
                {
                    if(strcmp(nn[j],s2)==0)
                    {
                        exit=1;

                        break;
                    }
                    else
                        exit=0;
                }
                if(exit==0)
                {
                    strcpy(nn[j],s2);

                    num++;
                }
                b=j;
                w[a][b]=1;

            }
            memset(s1,'\0',sizeof(s1));
            memset(s2,'\0',sizeof(s2));

        }
       /* for(i=0;i<n;i++)
        {
            printf("%d %s\n",i,nn[i]);
        }*/
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    w[i][j]=(w[i][j]<w[i][k]+w[k][j]) ?w[i][j]:w[i][k]+w[k][j];
                    if(w[i][j]<50000)arr[i][j]=1;
                    else arr[i][j]=0;
                }
            }
        }

        for(i=0;i<n;i++)flag[i]=1;
        cas++;
        if(cas>1)
            printf("\n");
        printf("Calling circles for data set %d:\n",cas);
        for(i=0;i<n;i++)
        {

            if(flag[i]==1)
            {

                flag[i]=0;
                printf("%s",nn[i]);
                for(j=i+1;j<n;j++)
                {
                    if(arr[i][j]==1&&arr[j][i]==1)
                    {
                        flag[j]=0;
                        printf(", %s",nn[j]);
                    }
                }
                printf("\n");
            }

        }
        memset(arr,0,sizeof(arr));
        memset(nn,0,sizeof(nn));
        first=1;

    }
    return 0;
}
