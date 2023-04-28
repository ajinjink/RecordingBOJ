#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool comp (int a, int b){
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, M, temp;
    cin >> T;

    for (int i = 0; i < T; i++) {
        queue<pair<int, int> > q; // index, importance
        cin >> N >> M;

        int count = 0;
        int imp[100];
        int index = 0;

        for (int j = 0; j < N; j++) {
            cin >> temp; // imortance
            q.push(make_pair(j, temp));
            imp[j] = temp;
        }

        sort(imp, imp + N, comp); // descending order
        

        while(!q.empty()) {

            if (q.front().second == imp[index]) {
                ++index;
                ++count;
                if (q.front().first == M) {
                    cout << count << '\n';
                    break;
                }
            }
            else {
                q.push(make_pair(q.front().first, q.front().second));
            }
            q.pop();
        }
    }
}