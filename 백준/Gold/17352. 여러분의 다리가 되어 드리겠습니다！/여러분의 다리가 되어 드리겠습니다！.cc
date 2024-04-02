#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> v;
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

  cin >> N;

  parent.resize(N + 1);
  for (int i = 0; i <= N; i++)
    parent[i] = i;

  for (int i = 0; i < N - 2; i++) {
    int a, b;
    cin >> a >> b;
    unite(a, b);
  }

  int prev = parent[1];
  for (int i = 2; i <= N; i++) {
    if (parent[i] != prev) {
      if (!check(prev, parent[i])) {
        cout << prev << ' ' << parent[i];
        break;
      }
      prev = parent[i];
    } else
      prev = parent[i];
  }

}
