#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <sstream>
#include <limits.h>
#define endl '\n'
#define pii pair<int, int>
#define tiiii tuple<int, int, int, int>
using ll = long long;
using namespace std;

set<string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        s.insert(word);
    }


    for (int i = 0; i < M; i++) {
        string list;
        cin >> list;

        stringstream ss(list);
        string item;

        while (getline(ss, item, ',')) {
            s.erase(item);
        }

        cout << s.size() << endl;
    }   
}



