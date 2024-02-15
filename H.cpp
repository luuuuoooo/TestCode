#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e3+100;
int Map[N][N];
int n,m,k,seaFlag,Flag=1;
struct Node{
    int x,y;
};
int dir[4][2]={
    -1,0,
    0,-1,
    1,0,
    0,1,
};

int main(){
    cin>>n>>m>>k;

    int x1,y1,x2,y2,sx,sy;
    for(int i=0;i<k;++i){
        cin>>x1>>y1>>x2>>y2;
        
        for(int x=min(x1,x2);x<=max(x1,x2);++x)
            for(int y=min(y1,y2);y<=max(y1,y2);++y)
                Map[x][y]=1;
    }
    cin>>sx>>sy;
    Map[sx][sy]=2;

    queue<Node>q;
    queue<Node>wall;
    q.push(Node{sx,sy});


    int x,y,tx,ty;
    while(Flag == 1){
        Flag = 0;
        while(!q.empty()){//ÂûÑÓ
            x = q.front().x;
            y = q.front().y;
            q.pop();


            for(int i=0;i<4;++i){
                tx = x+dir[i][0];
                ty = y+dir[i][1];
                if(x+dir[i][0]>=1 && x+dir[i][0]<=n && y+dir[i][1]>=1 && y+dir[i][1]<=m){
                    if(Map[tx][ty] == 0){
                        Map[tx][ty] = 2;
                        q.push(Node{tx,ty});
                    }
                    if(Map[tx][ty] == 1){
                        wall.push(Node{tx,ty});
                    }
                }else seaFlag=1;
            }
        }
        if(seaFlag != 1)
        while(!wall.empty()){
            x = wall.front().x;
            y = wall.front().y;
            wall.pop();
            for(int k=0;k<4;++k){
                tx = x+dir[k][0];
                ty = y+dir[k][1];
                if(tx>=1 && tx<=n && ty>=1 && ty<=m)
                if(Map[tx][ty] == 2){
                    Map[x][y]=2;
                    if(x+dir[(k+2)%4][0]>=1 && x+dir[(k+2)%4][0]<=n && y+dir[(k+2)%4][1]>=1 && y+dir[(k+2)%4][1]<=m)
                    if(Map[x+dir[(k+2)%4][0]][y+dir[(k+2)%4][1]]==0){
                        q.push(Node{x,y});
                        Flag = 1;
                    }
                    break;
                }
            }
        }
        

    }

    int cnt=0;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
    if(Map[i][j] == 0)++cnt;

    cout<<cnt;
    return 0;
}