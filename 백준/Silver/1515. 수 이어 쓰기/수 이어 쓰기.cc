#include <bits/stdc++.h>
#define endl '\n'
#define tiii tuple<int, int, int>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num;
    cin >> num;

    int res = 1;
    int index = 0;
    while (index < num.length()) {
        string temp = to_string(res);
        for (int j = 0; j < temp.length(); j++) {
            if (temp[j] == num[index]) index++;
        }
        res++;
    }

    cout << res - 1;
}
