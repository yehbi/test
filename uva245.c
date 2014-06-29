#include<stdio.h>
#include<string.h>
char word[10000][51]={0};
char num[10000]={0};
char ch[100]={0};
int main(void)
{
    int i,j,n,tn,tw,flagw;
    char c;


    i=0;
    n=0;
    tw=0;/*total word num*/
    flagw=0;
    while(c=getchar())
    {
        if(c=='0')
        break;
        if(c>='a'&&c<='z'||c>='A'&&c<='Z')
        {
            ch[i]=c;

            flagw=1;
            i++;
        }
        else if(c>='1'&&c<='9')
        {
            tn=0;
            n=0;
            while(c>='0'&&c<='9')
            {
                num[n]=c;
                n++;
                c=getchar();
            }
            for(j=0;j<=n-1;j++)
            tn=tn*10+(num[j]-'0');

            printf("%s%c",word[tn],c);
            strcpy(ch,word[tn]);

            for(j=tn-1;j>0;j--)
            strcpy(word[j+1],word[j]);

            strcpy(word[1],ch);
            memset(num,'0',sizeof(num));

        }
        else
        {
            if(flagw==1)
            {
                ch[i]='\0';

                for(j=tw;j>=1;j--)
                strcpy(word[j+1],word[j]);

                strcpy(word[1],ch);

                printf("%s",word[1]);
                tw++;
                i=0;
                memset(ch,'0',sizeof(ch));

                flagw=0;

            }

            printf("%c",c);

        }
    }
    return 0;
}
