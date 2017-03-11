//Solution by Zhusupov Nurlan
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef map<string , int> MSI;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define endl '\n'
#define pb(x) push_back(x)
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define SZ(t) ((int) t.size())
#define len(t) ((int) t.length())
#define base LL(1e9 + 7)
#define fname ""
#define sz 1000 * 1000
#define EPS (1e-8)
#define INF ((int)1e9 + 9)
#define mp make_pair

map <string, int> was;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int pr[sz];

struct state {
  int a[9], p;

  bool win() {
    for (int i = 0; i < 8; i++)
      if (a[i] != i + 1) return false;
    return true;
  }

  state move(int dir) {
    state b;
    b.p = p;
    for (int i = 0; i < 9; i++) b.a[i] = a[i];
    int x = p / 3, y = p % 3;
    x += dx[dir];
    y += dy[dir];
    if (0 <= x && x < 3 && 0 <= y && y < 3) {
      b.p = p + dx[dir] * 3 + dy[dir];
      swap(b.a[p], b.a[b.p]);
    }
    return b;
  }

  string serialize() {
    string s;
    for (int i = 0; i < 9; i++)
      s += a[i] + '0';
    return s;
  }

  void show() {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++)
        cout << a[i * 3 + j] << " ";
      cout << "\n";
    }
    cout << "\n";
  }

} s, q[sz];

void back(int r) {
  if (r < 0) return;
  back(pr[r]);
  q[r].show();
  return ;
}

int main()
{
    freopen(fname"in", "r", stdin);
//    freopen(fname"out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      cin >> s.a[i * 3 + j];
      if (s.a[i * 3 + j] == 0)
        s.p = i * 3 + j;
    }

  int l = 0, r = 0;
  q[l] = s;
  pr[0] = -1;
  while (l <= r) {
    state cur = q[l++];

    for (int i = 0; i < 4; i++) {
      state to = cur.move(i);
      if (!was[to.serialize()]) {
        was[to.serialize()] = 1;
        q[++r] = to;
        pr[r] = l - 1;
        if (to.win()) {
          l = r + 1;
          break;
        }
      }
    }
  }
  back(r);
}
