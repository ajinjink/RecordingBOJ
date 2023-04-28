#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    int R, G, B;

    int h[1000][3];
    cin >> h[0][0] >> h[0][1] >> h[0][2];
    cin >> R >> G >> B;
    h[1][0] = min(h[0][1], h[0][2]) + R;
    h[1][1] = min(h[0][0], h[0][2]) + G;
    h[1][2] = min(h[0][0], h[0][1]) + B;
    
    for (int i = 2; i < N; i++) {
        cin >> R >> G >> B;
        h[i][0] = min(h[i-1][1], h[i-1][2]) + R;
        h[i][1] = min(h[i-1][0], h[i-1][2]) + G;
        h[i][2] = min(h[i-1][0], h[i-1][1]) + B;
    }

    cout << min(h[N-1][0],min(h[N-1][1], h[N-1][2]));
}
