#include <iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void bfs(int u)
{
    if(u == n)
    {
        for(int i = 0; i < n; i ++) puts(g[i]);
        puts("");
        return;
    }
    
    for(int i = 0; i < n; i++)
    {
        if(!col[i] && !dg[u + i] && !udg[N - u + i]){
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[N - u + i] = true;
            bfs(u+1);
            col[i] = dg[u + i] = udg[N - u + i] = false;
            g[u][i] = '.';
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g[i][j] = '.';
    bfs(0);
    return 0;
}