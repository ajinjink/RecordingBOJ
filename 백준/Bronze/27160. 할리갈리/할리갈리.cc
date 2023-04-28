#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, X;
    cin >> N;

    int arr[4] = {0};

    string card;
    
    for (int i = 0; i < N; i++) {
        cin >> card >> X;
        if (card == "STRAWBERRY") {
            arr[0] += X;
        }
        if (card == "BANANA") {
            arr[1] += X;
        }
        if (card == "LIME") {
            arr[2] += X;
        }
        if (card == "PLUM") {
            arr[3] += X;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (arr[i] == 5) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

}