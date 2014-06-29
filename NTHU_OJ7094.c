#include<stdio.h>
#include<string.h>
void rev(char a[100], int ra[100]);
void nature(int a[100],int b[100],int len,int sign);/*two num>0 and two num<0*/
int compare(int ra[100], int rb[100],int len);
void minus(int a[100],int b[100],int len);/*num<0 num>0*/
int ina[100]={0};
int inb[100]={0};
int main(void)
{
    int len,i,sign,lena,lenb;
    char a[100]={0};
    char b[100]={0};
    while(scanf("%s %s",a,b)!=EOF)
    {
        len=0;
        lena=strlen(a)-1;
        lenb=strlen(b)-1;
        if(a[0]=='-'&&b[0]=='-')
        {
            for(i=0;i<=lena;i++)
            a[i]=a[i+1];
            a[i]='0';
            lena=lena-1;
            rev(a, ina);
            for(i=0;i<=lenb;i++)
            b[i]=b[i+1];
            b[i]='0';
            lenb=lenb-1;
            rev(b, inb);
            sign=0;
            len=(lena>=lenb)?lena:lenb;
            nature(ina,inb,len,0);

        }
        else if(a[0]=='-'&&b[0]!='-')
        {
            for(i=0;i<=lena;i++)
            a[i]=a[i+1];
            a[i]='0';
            lena=lena-1;
            rev(a, ina);
            rev(b, inb);
            
            len=(lena>=lenb)?lena:lenb;
            sign=compare(ina,inb,len);
            if(sign==2)
            printf("0\n");
            else if(sign==1)/*ina big*/
            {
                printf("-");
                minus(ina,inb,len);
            }
            else
                minus(inb,ina,len);
            

        }
        else if(b[0]=='-'&&a[0]!='-')
        {
            for(i=0;i<=lenb;i++)
            b[i]=b[i+1];
            b[i]='0';
            lenb=lenb-1;
            rev(a, ina);
            rev(b, inb);
            
            len=(lena>=lenb)?lena:lenb;
            sign=compare(ina,inb,len);
            if(sign==2)
            printf("0\n");
            else if(sign==1)/*ina big*/
            minus(ina,inb,len);
            else
            {
                printf("-");
                minus(inb,ina,len);

            }

        }

        else/*two num>0*/
        {
           rev(a,ina);
           sign=1;
           rev(b,inb);
           len=(lena>=lenb)?lena:lenb;
           nature(ina,inb,len,1);

        }

        for(i=0;i<=len;i++)/*clear*/
        {
            ina[i]=0;
            inb[i]=0;
            a[i]='0';
            b[i]='0';
        }
    }

    return 0;
}
void rev(char a[100],int ra[100])
{
    int len,i;
    len=strlen(a)-1;
    char temp[100]={0};
    for(i=0;i<=len;i++)
    {
        temp[i]=a[i];
    }
    for(i=0;i<=len;i++)
    {
        a[i]=temp[len-i];
    }
    for(i=0;i<=len;i++)
    {
        if(a[i]!='\0')
        ra[i]=a[i]-'0';
    }
}
void nature(int a[100],int b[100],int len,int sign)
{
    int c[100]={0};
    int i;
    int flag=1;/*if ans=0*/
    for(i=0;i<=len;i++)
    {
        c[i]=a[i]+b[i];

    }
    for(i=0;i<=len;i++)
    {
        c[i+1]=c[i+1]+c[i]/10;
        c[i]=c[i]%10;
    }
    for(i=len+1;i>=0;i--)
    {
        if(c[i]==0)
        flag=0;
        else
        {
            flag=1;
            break; 
        }
    }
    if(flag==0)
    printf("0");
    else
    {
        if(sign==0)
        printf("-");
        if(c[len+1]==0)
        {
            for(i=len;i>=0;i--)
            {
                if(c[i]==0)
                len=len-1;
                else
                break;
            }
        }
        else
        printf("%d",c[len+1]);
         
        for(i=len;i>=0;i--)
        {
            printf("%d",c[i]);
        }

    }
    printf("\n");

}
int compare(int ra[100], int rb[100],int len)
{
    int i,sign;
    for(i=len;i>=0;i--)
    {
        if(ra[i]>rb[i])
        {
            sign=1;
            break;
        }

        else if(ra[i]<rb[i])
        {
            sign=0;
            break;
        }
        else
        sign=2;
    }

    return sign;
}
void minus(int a[100],int b[100],int len)
{
        int i;
        int c[100]={0};
        for(i=0;i<=len;i++)
        {
            c[i]=a[i]-b[i];
        }
        for(i=0;i<=len;i++)
        {
            if(c[i]<0)
            {
                c[i+1]=c[i+1]-1;
                c[i]=c[i]+10;
            }

        }
        for(i=len;i>=0;i--)
        {
            if(c[i]==0)
            len=len-1;
            else
            break;
        }
        for(i=len;i>=0;i--)
        {
            printf("%d",c[i]);
        }
        printf("\n");

}
