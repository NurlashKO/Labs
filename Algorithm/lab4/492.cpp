#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int l, cnt, n, a[1000000], b[1000000];
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


void quick_sort(int *a, int n)
{
    if (n < 2)
        return ;
    int l = 0, r = n - 1, p = rand() % n, x = a[p];

    while (l <= r)
    {
        while (a[l] < x) l++;
        while (x < a[r]) r--;
        if (l <= r)
            swap(a[l++], a[r--]);
    }
    quick_sort(a, r + 1);
    quick_sort(a + l, n - l);
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[++cnt] = x;
        up(cnt);
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = a[1];
        swap(a[1], a[cnt]);
        cnt--;
        down(1);
    }
    quick_sort(b + 1, n);

    ans = max(b[1], l - b[n]);
    for (int i = 2; i <= n; i++)
        ans = max(ans, (b[i] - b[i - 1]) / 2.0);

    printf("%.2f", ans);
}

