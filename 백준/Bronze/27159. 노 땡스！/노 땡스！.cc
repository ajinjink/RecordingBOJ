#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    int start = 0, end = 0, temp;

    cin >> start;
    end = start;
    int res = start;

    for (int i = 0; i < N - 1; i++) {
        cin >> temp;
        if (temp != end + 1) {
            start = temp;
            res += start;
        }
        end = temp;
    }

    cout << res;
}