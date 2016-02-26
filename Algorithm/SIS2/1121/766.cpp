#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int a[1000000], n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}
