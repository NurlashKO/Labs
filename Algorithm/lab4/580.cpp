#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define F first
#define S second

int n, d;
pair <int, int> a[1010101], b[1010101];

void merge_sort(pair<int,int> *a, int n)
{
    if (n < 2)
        return ;
    merge_sort(a, n / 2);
    merge_sort(a + n / 2, (n + 1) / 2);

    merge(a, a + n / 2, a + n / 2, a + n, b);
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

int main()
{
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> a[i].F >> a[i].S;
    merge_sort(a, n);

    int l = 0;
    long long cur = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (l < n && a[l].F - a[i].F < d)
        {
            cur += a[l].S;
            l++;
        }
        ans = max(ans, cur);
        cur -= a[i].S;
    }

    cout << ans;
}

