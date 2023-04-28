#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    string temp;

    vector<string> v1;
    vector<string> v2;

    vector<string> res;
    vector<string>::iterator iter;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        v1.push_back(temp);
    }

    for (int i = 0; i < M; i++) {
        cin >> temp;
        v2.push_back(temp);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(res));

    cout << res.size() << '\n';

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << '\n';
    }


}