#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int M, num, ten = 0;
        cin >> M;

        cout << (M / 2) + 1 << '\n';
        
        priority_queue<int> maxheap; // 내림차순. 작은 수 저장 
        priority_queue<int, vector<int>, greater<int> > minheap; // 오름차순. 큰 수 저장
        // minheap 크기를 maxheap보다 1 크게 하면 minheap의 top이 중앙값

        for (int i = 1; i <= M; i++) {
            cin >> num;
            
            if (minheap.size() == maxheap.size()) {
                
                minheap.push(num);
            }
            else {
                maxheap.push(num);
            }

            if (!minheap.empty() && !maxheap.empty() && minheap.top() < maxheap.top()) {
                int a = minheap.top(), b = maxheap.top();
                minheap.pop();
                maxheap.pop();
                minheap.push(b);
                maxheap.push(a);
            }

            if (i % 2) {
                cout << minheap.top() << ' ';
                ten++;
                if (ten % 10 == 0) {
                    cout << '\n';
                }
            }

        }
        cout << '\n';
    }
}

