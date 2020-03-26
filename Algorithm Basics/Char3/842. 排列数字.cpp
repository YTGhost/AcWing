#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N];
bool st[N];

void bfs(int u)
{
    if(u == n)
    {
        for(int i = 0; i < n; i ++) printf("%d ", path[i]);
        puts("");
        return;
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(!st[i]){
            path[u] = i;
            st[i] = true;
            bfs(u+1);
            st[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    bfs(0);
    return 0;
}