#include <iostream>

using namespace std;

const int N = 15;

int f[2*N][N][N], w[N][N];

int main()
{
    int n;
    cin >> n;
    
    int a, b, c;
    while(cin >> a >> b >> c, a || b || c) w[a][b] = c;
    
    for(int k = 2; k <= 2*n; k++)
        for(int i1 = 1; i1 <= n; i1++)
            for(int i2 = 1; i2 <= n; i2++)
            {
                int j1 = k - i1, j2 = k - i2;
                if(j1 > 0 && j1 <= n && j2 > 0 && j2 <= n)
                {
                    int t = w[i1][j1];
                    if(i1 != i2) t += w[i2][j2];
                    int &x = f[k][i1][i2];
                    x = max(x, f[k-1][i1-1][i2-1] + t);
                    x = max(x, f[k-1][i1-1][i2] + t);
                    x = max(x, f[k-1][i1][i2-1] + t);
                    x = max(x, f[k-1][i1][i2] + t);
                }
            }
    cout << f[2*n][n][n] << endl;
    return 0;
}