#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string temp1, temp2;

    map<string, string> m;

    for (int i = 0; i < N; i++) {
        cin >> temp1 >> temp2;
        m.insert(make_pair(temp1, temp2));
    }
    
    for (int i = 0; i < M; i++) {
        cin >> temp1;
        cout << m.find(temp1)->second << '\n';
    }
}