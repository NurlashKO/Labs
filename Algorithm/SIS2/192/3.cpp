#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, cnt = 0, x = 1;
    cin >> n;
    for (int i = 1; ; i++)
    {
        if (x >= n)
        {
            cout << cnt;
            return 0;
        }
        cnt++;
        x *= 2;
    }
}
