#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double num[20];
    int total = 0;
    double grade[20];

    for (int i = 0; i < 20; i++) {
        string name, g;
        cin >> name >> num[i] >> g;

        if (g == "P") {
            num[i] = 0;
            continue;
        }

        if (g == "A+") grade[i] = 4.5;
        else if (g == "A0") grade[i] = 4;
        else if (g == "B+") grade[i] = 3.5;
        else if (g == "B0") grade[i] = 3;
        else if (g == "C+") grade[i] = 2.5;
        else if (g == "C0") grade[i] = 2;
        else if (g == "D+") grade[i] = 1.5;
        else if (g == "D0") grade[i] = 1;
        else if (g == "F") grade[i] = 0;
        total += num[i];
    }

    double res = 0;
    for (int i = 0; i < 20; i++) res += num[i] * grade[i];
    cout << res / total;

}
