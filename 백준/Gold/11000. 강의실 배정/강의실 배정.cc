#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > classes;
    priority_queue<int, vector<int>, greater<int> > endT;

    while (N--) {
        int a, b;
        cin >> a >> b;
        classes.push(make_pair(a, b));
    }

    while (!classes.empty()) {
        int start = classes.top().first;
        int finish = classes.top().second;
        classes.pop();

        if (endT.empty()) {
            endT.push(finish);
            continue;
        }

        int minT = endT.top();

        if (start >= minT) {
            endT.pop();
            endT.push(finish);
        }
        else {
            endT.push(finish);
        }
    }

    cout << endT.size();

}