#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int cnt, n, a[1000000], b[1000000];

void up(int v)
{
    while (v > 1 && a[v] < a[v >> 1])
    {
        swap(a[v], a[v >> 1]);
        v >>= 1;
    }
}

void down(int v)
{
    while (v + v <= cnt)
    {
        if (v + v + 1 <= cnt && a[v + v + 1] <= a[v + v] && a[v + v + 1] <= a[v])
        {
            swap(a[v], a[v + v + 1]);
            v = v + v + 1;
        }
        else
        if (a[v + v] <= a[v])
        {
            swap(a[v + v], a[v]);
            v = v + v;
        }
        else
            break;
    }
}


int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[++cnt] = x;
        up(cnt);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[1] << " ";
        swap(a[1], a[cnt]);
        cnt--;
        down(1);
    }
}

