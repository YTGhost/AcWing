#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 2; ; i++)
        if(n % i == 0)
        {
            cout << n / i << endl;
            break;
        }
    return 0;
}