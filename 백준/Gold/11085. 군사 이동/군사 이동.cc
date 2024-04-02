#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int p, w, c, v;
vector<tuple<int, int, int>> e;
vector<int> parent;

int find(int a) {
  if (parent[a] == a)
    return a;
  else
    return parent[a] = find(parent[a]);
}

void unite(int a, int b) {
  a = find(a);
  b = find(b);

  if (a != b)
    parent[b] = a;
}

bool check(int a, int b) { return find(a) == find(b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> p >> w >> c >> v;

  parent.resize(p + 1);
  for (int i = 0; i <= p; i++)
    parent[i] = i;

  for (int i = 0; i < w; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    e.push_back(make_tuple(d, a, b));
  }
  sort(e.begin(), e.end(), greater<>());

  for (int i = 0; i < e.size(); i++) {
    unite(get<1>(e[i]), get<2>(e[i]));
    if (check(c, v)) {
      cout << get<0>(e[i]);
      break;
    }
  }
}