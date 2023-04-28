#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[31] = {0};
    int stu;

    for (int i = 0; i < 28; i++) {
        cin >> stu;
        arr[stu] = 1;
    }

    for (int i = 1; i <= 30; i++) {
        if (arr[i] == 0) {
            cout << i << '\n';
        }
    }
}