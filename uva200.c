#include<stdio.h>
#include<string.h>
int main(void)
{
    char arr[5000][21]={0};
    char tmp[21]={0};
    int i=0,len,n,j;
    int out[26]={0};
    while(scanf("%s",tmp)!=EOF)
    {
        
        if(tmp[0]=='#')
        {
            for(j=0;j<21;j++)
            {
                for(n=0;n<i;n++)
                {
                    if(arr[n][j]>='A'&&arr[n][j]<='Z')
                    out[arr[n][j]-'A']++;
                    if(out[arr[n][j]-'A']==1)
                    printf("%c",arr[n][j]);
                }
            }
            printf("\n");
            
        }
        len=strlen(tmp)-1;
        for(j=0;j<=len;j++)
        arr[i][j]=tmp[j];
       
        i++;
       
    
    }
    return 0;
    
}
