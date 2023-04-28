#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, count = 0;
    cin >> N;

    int start = 1;
    int end = 1;
    int sum = 1;

    while (end != N) {
        if (sum == N) {
            count++;
            end++;
            sum += end;
        }
        else if (sum < N) {
            end++;
            sum += end;
        }
        else if (sum > N) {
            sum -= start;
            start++;
        }
        
    }
    cout << count + 1;

}