#include<stdio.h>
#include<string.h>
int dis[40][40][40]={0};
int use[40][40][40]={0};
int bfs[30000][3]={0};
int main(void)
{
    int L,R,C;
    int head,tail,ex,ey,ez,sx,sy,sz;
    int i,j,k,x,y,z,end;
    char map[40][40][40]={0};
    int move[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
    while(scanf("%d %d %d",&L,&R,&C)!=EOF)
    {
        end=0;
        if(L==0&&R==0&&C==0)
        break;
        getchar();
        head=tail=0;
        for(i=0;i<L;i++)
        {
            for(j=0;j<R;j++)
            {
                for(k=0;k<C;k++)
                {
                    scanf("%c",&map[j][k][i]);
                    if(map[j][k][i]=='S')
                    {
                        sx=j;
                        sy=k;
                        sz=i;
                        bfs[tail][0]=j;
                        bfs[tail][1]=k;
                        bfs[tail][2]=i;
                        use[j][k][i]=1;
                        tail++;
                    }
                    else if(map[j][k][i]=='E')
                    {
                        ex=j;
                        ey=k;
                        ez=i;
                    }
                }
                getchar();
            }
            getchar();
        }
        while(head!=tail)
        {
            for(i=0;i<6;i++)
            {
                x=sx+move[i][0];
                y=sy+move[i][1];
                z=sz+move[i][2];
                if(x>=0&&x<R&&y>=0&&y<C&&z>=0&&z<L&&use[x][y][z]==0&&map[x][y][z]!='#')
                {

                    dis[x][y][z]=dis[sx][sy][sz]+1;
                    bfs[tail][0]=x;
                    bfs[tail][1]=y;
                    bfs[tail][2]=z;
                    tail++;
                    use[x][y][z]=1;
                }
                if(map[x][y][z]=='E')
                end=1;
            }
            if(end==1)
            break;
            head++;
            sx=bfs[head][0];
            sy=bfs[head][1];
            sz=bfs[head][2];

        }
        if(end==0)
        printf("Trapped!\n");
        else
        printf("Escaped in %d minute(s).\n",dis[ex][ey][ez]);
        memset(dis,0,sizeof(dis));
        memset(bfs,0,sizeof(bfs));
        memset(use,0,sizeof(use));
        memset(map,'0',sizeof(map));
    }

    return 0;
}
