#include<stdio.h>
#include<string.h>
int main(void)
{
    int num,i,flag;
    char str[2000];
    while(NULL!= fgets(str, 2000, stdin))
    {
        num=0;
        flag=0;

        for(i=0;i<strlen(str);i++)
        {


                if(str[i]==' ')
                {
                    if(flag>0)
                    {
                        num=num+1;
                        flag=0;
                    }

                }
                else if(str[i]=='\n')
                {
                    if(flag>0)
                    {
                        num=num+1;
                        flag=0;
                    }
                }
                else if((str[i]>='A'&&str[i]<='z')||(str[i]>='a'&&str[i]<='z'))
                flag++;
                else
                {
                    if(flag>0)
                    {
                        num=num+1;
                        flag=0;
                    }
                }



        }
         printf("%d\n",num);

    }



    return 0;
}

