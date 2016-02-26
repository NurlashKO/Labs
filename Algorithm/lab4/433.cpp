#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long l, cnt, n, s[1000000], m, r, t, a[1000000], b[1000000];
double ans;

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
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[++cnt] = x;
        s[i + 1] = s[i] + x;
        up(cnt);
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = a[1];
        swap(a[1], a[cnt]);
        cnt--;
        down(1);
    }

    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1];

    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> t >> l >> r;
        if (t == 1)
            cout << s[r] - s[l - 1] << "\n";
        else
            cout << b[r] - b[l - 1] << "\n";
    }

}

