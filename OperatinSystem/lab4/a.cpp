//Solution by Zhusupov Nurlan
#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

typedef long long LL;
typedef map<string , int> MSI;
typedef vector<int> VI;

#define pb(x) push_back(x)
#define sqr(x) ((x)*(x))
#define F first
#define S second
#define SZ(t) ((int)t.size())
#define len(t) ((int)t.length())
#define base 10
#define fname "points."
#define sz 1000*1000
#define EPS (1e-8)
#define INF ((int)1e9 + 9)
#define write(xx) printf("%d\n" , xx);
#define readln(xx) getline(cin , xx)
#define read(xx) scanf("%d" , &xx)
#define for(xx1 , yy1 , zz1) for(int zz1 = xx1 ; zz1 <= yy1 ; zz1++)

const double PI  = acos(-1.0);

int t, ans, n, m, x[sz], y[sz], tin[sz], up[sz], d[sz];
vector <int> a[sz];
vector <int> b[sz];
bool was[sz], w[sz];

void dfs(int v, int P)
{
    int ch = 0;
    was[v] = true;
    tin[v] = t++;
    up[v] = tin[v];

    if (!a[v].empty())
    {
        for (0, a[v].size() - 1 , i)
        {           
            int to = a[v][i];
            if (to == P) continue;
            if (was[to])
                up[v] = min(up[v] , tin[to]);
            else
            if (!was[to])
            {
                dfs(to, v);
                ch++;
                up[v] = min(up[v], up[to]);
                if (up[to] >= tin[v] && P && !w[v])
                {               
                    d[++ans] = v;
                    w[v] = true;
                }
            }
            
        }
    }
    if (!P && !w[v] && ch > 1)
    {
        w[v] = true;
        d[++ans] = v;
    }
}

int main()
{
    cin >> n >> m;
    for (1 , m , i)
    {
        read(x[i]);read(y[i]);
        a[x[i]].pb(y[i]);
        a[y[i]].pb(x[i]);
        b[x[i]].pb(i);
        b[y[i]].pb(i);
    }
    for (1 , n , i)
        if (!was[i])
            dfs(i, 0);

    sort(d + 1, d + 1 + ans);
               
    write(ans);     
    for (1 , ans , i)
        write(d[i]);
    return 0;
}