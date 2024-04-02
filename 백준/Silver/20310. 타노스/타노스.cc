#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <limits.h>
#define endl '\n'
#define pii pair<int, int>
#define tiiii tuple<int, int, int, int>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int zero = 0, one = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '0') zero++;
        else one++;
    }

    zero /= 2;
    one /= 2;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '0' && zero > 0) {
            cout << 0;
            zero--;
        }
        
        if (str[i] == '1' && one > 0) {
            one--;
            continue;
        }
        else if (str[i] == '1' && one == 0) cout << 1;
    }

}
