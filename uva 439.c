#include<stdio.h>
#include<string.h>
int dis[10][10]={0};
int use[10][10]={0};
int bfs[10][10]={0};
int main(void)
{
    int move[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
    char c[6]={0};
    int i;
    int sx,sy,ex,ey,x,y;
    int tail,head;
    int end=0;


    while(gets(c)!=NULL)
    {
        memset(dis,0,sizeof(dis));
        memset(use,0,sizeof(use));
        memset(bfs,0,sizeof(bfs));


        tail=head=1;
        end=0;
        sx=c[1]-'0';
        sy=c[0]-'0'-48;
        ex=c[4]-'0';
        ey=c[3]-'0'-48;

        bfs[tail][0]=sx;
        bfs[tail][1]=sy;
        tail++;
        /*a=97*/
        use[sx][sy]=1;
        x=sx;
        y=sy;

        while((x!=ex||y!=ey))
        {


            for(i=0;i<8;i++)
            {

                x=sx+move[i][0];
                y=sy+move[i][1];
                if(x>=1&&x<=8&&y>=1&&y<=8&&use[x][y]==0)
                {

                    bfs[tail][0]=x;
                    bfs[tail][1]=y;
                    tail++;
                    use[x][y]=1;
                    dis[x][y]=dis[sx][sy]+1;

                }
                if(x==ex&&y==ey)
                end=1;
            }
            if(end==1)
            break;
            head++;
            sx=bfs[head][0];
            sy=bfs[head][1];
        }
        printf("To get from %c%c to %c%c takes %d knight moves.\n",c[0],c[1],c[3],c[4],dis[ex][ey]);
        memset(c,'0',sizeof(c));
    }

    return 0;
}
