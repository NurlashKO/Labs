#include <iostream>
#include <cstdio>

using namespace std;

#define sz 1000 * 1000

long long x, n, m, a[sz], l, r, mid;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];


    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        if (n == 1)
        {
            cout << a[1] << "\n";
            continue;
        }
        l = 1;
        r = n;
        while (r - l > 1)
        {
            mid = (l + r) >> 1;
            if (a[mid] > x)
                r = mid;
            else
                l = mid;
        }
        if (abs(x - a[l]) <= abs(a[r] - x))
            cout << a[l];
        else
            cout << a[r];
        cout << "\n";
    }
}
