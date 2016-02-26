#include <iostream>
#include <cstdio>

using namespace std;
const int sz = 5e5;

int heap[sz], n, x, cnt;

void up(int v)
{
    if (v > 1 && heap[v] < heap[v / 2])
    {
        swap(heap[v], heap[v / 2]);
        up(v >> 1);
    }
}

void down(int v)
{
    if (v + v + 1 <= cnt)
    {
        if (heap[v + v + 1] <= heap[v + v] && heap[v + v + 1] < heap[v])
        {
            swap(heap[v + v + 1], heap[v]);
            down(v + v + 1);
            return;
        }
    }
    if (v + v <= cnt)
    {
        if (heap[v + v] < heap[v])
        {
            swap(heap[v + v], heap[v]);
            down(v + v);
        }
    }
}

void add(int x)
{
    heap[++cnt] = x;
    up(cnt);
}

int top()
{
    return heap[1];
}

void erase()
{
    swap(heap[1], heap[cnt]);
    cnt--;
    down(1);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        add(x);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << top() << " ";
        erase();
    }
}
