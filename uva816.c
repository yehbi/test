#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node NODE;
struct node
{
    int dir[5];
};
int use[10][10][5]={0};
NODE a[10][10][5];
int dis[10][10]={0};
int bfs[500][3]={0};
int stac[500][3]={0};
int pa[10][10][5][3]={0};

int move[5][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1}};
int main()
{
    char name[22]={0};
    char str[6]={0};
    char startdir[2];
    int tmp=0,tmp2=0;
    int sx,sy,ex,ey,x,y,i,j,in,out,x2,y2;
    int head,tail;
    int end;
    int time=0;
    while(scanf("%s",name)!=EOF)
    {
        end=0;
        if(strcmp(name,"END")==0)break;
        scanf("%d %d %s %d %d",&sx,&sy,startdir,&ex,&ey);
        head=tail=0;

        scanf("%d",&x);
        while(x!=0)
        {
            scanf("%d",&y);
            while(scanf("%s",str)!=EOF)
            {
                if(str[0]=='*'){break;}
                if(str[0]=='W')
                {
                    i=1;
                    while(str[i]!='\0')
                    {
                        if(str[i]=='F')
                        a[x][y][4].dir[3]=1;
                        else if(str[i]=='L')
                        a[x][y][4].dir[2]=1;
                        else if(str[i]=='R')
                        a[x][y][4].dir[1]=1;

                        a[x][y][4].dir[4]=0;
                        i++;
                    }

                }
                else if(str[0]=='N')
                {
                    i=1;
                    while(str[i]!='\0')
                    {
                        if(str[i]=='F')
                        a[x][y][2].dir[1]=1;
                        else if(str[i]=='L')
                        a[x][y][2].dir[3]=1;
                        else if(str[i]=='R')
                        a[x][y][2].dir[4]=1;

                        a[x][y][2].dir[2]=0;
                        i++;
                    }
                }
                else if(str[0]=='E')
                {
                    i=1;
                    while(str[i]!='\0')
                    {
                        if(str[i]=='F')
                        a[x][y][3].dir[4]=1;
                        else if(str[i]=='L')
                        a[x][y][3].dir[1]=1;
                        else if(str[i]=='R')
                        a[x][y][3].dir[2]=1;

                        a[x][y][3].dir[3]=0;
                        i++;
                    }
                }
                else if(str[0]=='S')
                {
                    i=1;
                    while(str[i]!='\0')
                    {
                        if(str[i]=='F')
                        a[x][y][1].dir[2]=1;
                        else if(str[i]=='L')
                        a[x][y][1].dir[4]=1;
                        else if(str[i]=='R')
                        a[x][y][1].dir[3]=1;

                        a[x][y][1].dir[1]=0;
                        i++;
                    }
                }
                memset(str,'\0',sizeof(str));
            }
            scanf("%d",&x);
        }
        if(startdir[0]=='S')
        {x=sx+1; y=sy; in=1;}
        else if(startdir[0]=='N')
        {x=sx-1; y=sy; in=2;}
        else if(startdir[0]=='E')
        {y=sy+1; x=sx; in=3;}
        else if(startdir[0]=='W')
        {y=sy-1; x=sx; in=4;}
        pa[x][y][in][0]=sx;
        pa[x][y][in][1]=sy;
        pa[x][y][in][2]=in;
        out=in;
        bfs[tail][0]=sx;
        bfs[tail][1]=sy;
        use[x][y][in]=1;

        head++;
        tail++;
        bfs[tail][0]=x;
        bfs[tail][1]=y;
        bfs[tail][2]=in;
        tail++;

        if(x==ex&&y==ey)end=1;
        /*LocalAndThenGlobal*/
        while((x!=ex||y!=ey)&&head!=tail&&x<=9&&y<=9&&x>=1&&y>=1)
        {



            if(in==1)
            {
                for(i=1;i<=4;i++)
                {
                    if(a[x][y][in].dir[i]==1)
                    {
                        x2=x+move[i][0];
                        y2=y+move[i][1];
                        if(i==2)out=1;
                        else if(i==3)out=4;
                        else if(i==4)out=3;
                        if(x2>=1&&y2>=1&&x2<=9&&y2<=9&&use[x2][y2][out]==0)
                        {


                            use[x2][y2][out]=1;
                            dis[x2][y2]=dis[x][y]+1;
                            bfs[tail][0]=x2;
                            bfs[tail][1]=y2;
                            bfs[tail][2]=out;
                            tail++;
                            pa[x2][y2][out][0]=x;
                            pa[x2][y2][out][1]=y;
                            pa[x2][y2][out][2]=in;

                            if(x2==ex&&y2==ey)
                            {

                                 end=1;
                                 break;
                            }
                        }



                    }

                }
            }
            else if(in==2)
            {

                for(i=1;i<=4;i++)
                {

                    if(a[x][y][in].dir[i]==1)
                    {

                        x2=x+move[i][0];
                        y2=y+move[i][1];
                        if(i==1)out=2;
                        else if(i==3)out=4;
                        else if(i==4)out=3;
                        if(x2>=1&&y2>=1&&x2<=9&&y2<=9&&use[x2][y2][out]==0)
                        {


                            use[x2][y2][out]=1;
                            dis[x2][y2]=dis[x][y]+1;
                            bfs[tail][0]=x2;
                            bfs[tail][1]=y2;
                            bfs[tail][2]=out;
                            tail++;
                            pa[x2][y2][out][0]=x;
                            pa[x2][y2][out][1]=y;
                            pa[x2][y2][out][2]=in;

                            if(x2==ex&&y2==ey)
                            {
                                end=1;
                                break;
                            }

                        }


                    }


                }

            }
            else if(in==3)
            {
                for(i=1;i<=4;i++)
                {
                    if(a[x][y][in].dir[i]==1)
                    {
                        x2=x+move[i][0];
                        y2=y+move[i][1];
                        if(i==1)out=2;
                        else if(i==2)out=1;
                        else if(i==4)out=3;
                        if(x2>=1&&y2>=1&&x2<=9&&y2<=9&&use[x2][y2][out]==0)
                        {


                            use[x2][y2][out]=1;
                            dis[x2][y2]=dis[x][y]+1;
                            bfs[tail][0]=x2;
                            bfs[tail][1]=y2;
                            bfs[tail][2]=out;
                            tail++;
                            pa[x2][y2][out][0]=x;
                            pa[x2][y2][out][1]=y;
                            pa[x2][y2][out][2]=in;
                            if(x2==ex&&y2==ey)
                            {
                                end=1;
                                break;
                            }

                        }


                    }

                }
            }
            else if(in==4)
            {

                for(i=1;i<=4;i++)
                {
                    if(a[x][y][in].dir[i]==1)
                    {
                        x2=x+move[i][0];
                        y2=y+move[i][1];
                        if(i==1)out=2;
                        else if(i==2)out=1;
                        else if(i==3)out=4;
                        if(x2>=1&&y2>=1&&x2<=9&&y2<=9&&use[x2][y2][out]==0)
                        {


                            use[x2][y2][out]=1;
                            dis[x2][y2]=dis[x][y]+1;
                            bfs[tail][0]=x2;
                            bfs[tail][1]=y2;
                            bfs[tail][2]=out;
                            tail++;
                            pa[x2][y2][out][0]=x;
                            pa[x2][y2][out][1]=y;
                            pa[x2][y2][out][2]=in;

                            if(x2==ex&&y2==ey)
                            {
                                end=1;
                                break;
                            }


                        }


                    }

                }
            }
            if(end==1)
            break;
            head++;
            x=bfs[head][0];
            y=bfs[head][1];
            in=bfs[head][2];



        }

        if(end==1)
        {
            x=ex;
            y=ey;
            tmp=out;
            stac[0][0]=ex;
            stac[0][1]=ey;
            stac[0][2]=out;
            i=1;


            while(pa[x][y][tmp][0]!=0&&pa[x][y][tmp][1]!=0)
            {


                stac[i][0]=pa[x][y][tmp][0];
                stac[i][1]=pa[x][y][tmp][1];
                stac[i][2]=pa[x][y][tmp][2];
                /*printf("%d %d !%d %d\n",x,y,pa[x][y][tmp][0],pa[x][y][tmp][1]);*/
                i++;

                x2=pa[x][y][tmp][0];
                y2=pa[x][y][tmp][1];
                tmp2=pa[x][y][tmp][2];
                x=x2;
                y=y2;
                tmp=tmp2;


            }
            printf("%s\n",name);
            printf("  (%d,%d)",stac[i-1][0],stac[i-1][1]);
            time=1;
            for(j=i-2;j>=0;j--)
            {
                if(time%10==0)
                printf("\n  (%d,%d)",stac[j][0],stac[j][1]);
                else
                printf(" (%d,%d)",stac[j][0],stac[j][1]);
                time++;
            }
            printf("\n");
        }
        else
        {
            printf("%s\n",name);
            printf("  No Solution Possible\n");
        }




    memset(pa,0,sizeof(pa));
    memset(stac,0,sizeof(stac));
    memset(bfs,0,sizeof(bfs));
    memset(a,0,sizeof(a));
    memset(use,0,sizeof(use));
    memset(dis,0,sizeof(dis));
    memset(startdir,0,sizeof(startdir));
    memset(name,0,sizeof(name));






    }
    return 0;
}

