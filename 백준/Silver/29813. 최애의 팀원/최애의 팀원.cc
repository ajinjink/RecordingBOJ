#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    queue<pair<string, int> > q;

    for (int i = 0; i < N; i++) {
        string name;
        int num;
        cin >> name >> num;
        q.push(make_pair(name, num));
    }

    while (q.size() > 1) {
        pair<string, int> now = q.front(); // 제일 앞 학생
        q.pop();

        for (int i = 0; i < now.second - 1; i++) {
            pair<string, int> temp = q.front();
            q.pop();
            q.push(temp);
        }

        q.pop(); // 제일 앞 학생의 팀원
    }

    cout << q.front().first; // 한 명 남은 김한양의 팀원


}