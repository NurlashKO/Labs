#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, a[1000000], b[1000000];

void quick_sort(int *a, int n)
{
    if (n < 2)
        return ;
    int l = 0, r = n - 1, x = a[rand() % n];

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
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quick_sort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

