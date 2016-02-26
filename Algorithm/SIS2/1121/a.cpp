#include <iostream>
#include <cstdio>

using namespace std;

long long x, l, r;

int main()
{
    l = r = 1;
    cin >> x;
    while (x > 1)
    {
        if (l * l <= r * r * r)
        {
            if (l * l == r * r * r)
                r++;
            l++;
        }
        else
            r++;
        x--;
    }
    cout << min(l * l, r * r * r);
}
