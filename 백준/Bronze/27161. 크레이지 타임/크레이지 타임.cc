#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, X;
    string ctype;
    int time = 1;
    int direction = 1;

    cin >> N;
    for (int i = 0; i < N; i++) {
        string res;
        cin >> ctype >> X;

        if (ctype == "HOURGLASS") {
            if (X != time) {
                direction *= (-1);
            }
            res = "NO";

        }
        else {
            if (X == time) {
                res = "YES";
            }
            else {
                res = "NO";
            }
        }
        
        cout << time << ' ' << res << '\n';
        
        time += direction;
        if (time == 0) time = 12;
        if (time == 13) time = 1;

    }

}