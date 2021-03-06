#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int f[N], a[N];

int main()
{
    int k;
    cin >> k;

    while(k--)
    {
        int n, ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        
        for(int i = 1; i <= n; i++)
        {
            f[i] = 1;
            for(int j = 1; j < i; j++)
                if(a[i] < a[j]) f[i] = max(f[i], f[j] + 1);
            ans = max(ans, f[i]);
        }
        
        for(int i = n; i >= 1; i--)
        {
            f[i] = 1;
            for(int j = n; j > i; j--)
                if(a[i] < a[j]) f[i] = max(f[i], f[j] + 1);
            ans = max(ans, f[i]);
        }
        
        cout << ans << endl;
    }
    return 0;
}