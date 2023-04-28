#include <iostream>
#include <vector>
using namespace std;

int N;

bool checkprime(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int num, int digit) {
    if (digit == N) {
        if (checkprime(num)) {
            cout << num << '\n';
            return;
        }
    }
    for (int i = 1; i <= 9; i++) {
        if (i % 2 != 0 && checkprime(num * 10 + i)) {
            dfs(num * 10 + i, digit + 1);
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);
}