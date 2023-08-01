/*
테크노 경영학을 수강.
4명이서 한 팀.
한 명은 팀플 시작하자 마자 잠수.
남은 3명이서 팀플 해야 함.
사업 아이디어를 생각해 내야 함.
선배가 작년에 썼던 자료를 받았다. 거기에는 주제로 선정되지 못한 아이디어 리스트가 있다.
거기서 아이디어 하나를 선정해서 올해 김한양 팀의 주제로 정하기로 했다.
어느 아이디어가 쓸만한지 판단해야 하는데, 아이디어가 너무 많다. 세명이서 모든 아이디어를 검토하는 데 드는 최소 시간을 구해라
첫 줄에 아이디어의 개수 N.
둘때 줄에 각 아이디어를 검토하는 데 드는 시간
*/


#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    priority_queue<int> wait; 
    priority_queue<int, vector<int>, greater<int> > pq; 

    for (int i = 0; i < N; i++) {
        int time;
        cin >> time;
        wait.push(time);
    }

    for (int i = 0; i < min(N, M); i++) { 
        pq.push(wait.top());
        wait.pop();
    }

    while (!wait.empty()) {
        int top = pq.top(); 
        pq.pop();

        pq.push(top + wait.top());
        wait.pop();
    }

    while (pq.size() > 1) {
        pq.pop();
    }

    cout << pq.top(); 
    
}