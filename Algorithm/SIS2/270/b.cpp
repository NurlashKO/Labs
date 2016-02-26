#include <iostream>
#include <cstdio>

using namespace std;

int a[1000000], n, cnt, x;

int main()
{
    cin >> n;
    for (int i = 1; i<= n; i++)
        cin >> a[i];
    cin >> x;

    for (int i = 1; i <= n; i++)
        cnt += a[i] == x;
    cout << cnt;
}
