#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmpstring(string a, string b) {
    reverse(b.begin(), b.end());
    if (a == b) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string temp;
    vector<string> v;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (cmpstring(v[i], v[j])) {
                cout << v[i].length() << ' ' << v[i][v[i].length() / 2];
                return 0;
            }
        }
    }


}
