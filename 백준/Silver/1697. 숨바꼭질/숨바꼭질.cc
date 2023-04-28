#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<pair<int, int> > q;
int visited[100001] = {0};

void bfs() {

    while (!q.empty()) {
        int location = q.front().first;
        int dist = q.front().second;
        q.pop();

        visited[location] = 1;

        if (location == K) {
          
            cout << dist;
            break;
           
        }
        if (location < K) {
            if (location * 2 <= 100000 && !visited[location * 2]) {
                visited[location * 2] = 1;
                q.push(make_pair(2 * location, dist + 1));
            }
            if (location - 1 >= 0 && !visited[location - 1]) {
                visited[location - 1] = 1;
                q.push(make_pair(location - 1, dist + 1));
            }
            if (location + 1 <= 100000 && !visited[location + 1]) {
                visited[location + 1] = 1;
                q.push(make_pair(location + 1, dist + 1));
            }

        }
        if (location > K) {
            q.push(make_pair(location - 1, dist + 1));
        }
        
        
    }
    


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    q.push(make_pair(N, 0));

    bfs();

}