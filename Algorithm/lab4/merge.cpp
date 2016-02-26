#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, a[1000000], b[1000000];

void merge_sort(int *a, int n)
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
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    merge_sort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

