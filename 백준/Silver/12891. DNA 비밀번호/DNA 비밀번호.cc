#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S, P;
    string pwd;
    int limit[4] = {0};
    int cnt[4] = {0};
    int count = 0;

    cin >> S >> P;
    cin >> pwd;
    cin >> limit[0] >> limit[1] >> limit[2] >> limit[3];

    for (int i = 0; i < P; i++) {
            
        if (pwd[i] == 'A') {
            cnt[0]++;
        }
        if (pwd[i] == 'C') {
            cnt[1]++;
        }
        if (pwd[i] == 'G') {
            cnt[2]++;
        }
        if (pwd[i] == 'T') {
            cnt[3]++;
        }
    }
    bool flag = true;
    for (int i = 0; i < 4; i++) {
        if (limit[i] > cnt[i]) {
            flag = false;
        }
    }
    if (flag == true) {
        count++;
    }


    int begin = 1;
    int end = P;

    while (end < pwd.length()) {
        if (pwd[begin - 1] == 'A') {
            cnt[0]--;
        }
        if (pwd[begin - 1] == 'C') {
            cnt[1]--;
        }
        if (pwd[begin - 1] == 'G') {
            cnt[2]--;
        }
        if (pwd[begin - 1] == 'T') {
            cnt[3]--;
        }

        if (pwd[end] == 'A') {
            cnt[0]++;
        }
        if (pwd[end] == 'C') {
            cnt[1]++;
        }
        if (pwd[end] == 'G') {
            cnt[2]++;
        }
        if (pwd[end] == 'T') {
            cnt[3]++;
        }
        
        flag = true;
        for (int i = 0; i < 4; i++) {
            if (limit[i] > cnt[i]) {
                flag = false;
            }
        }
        if (flag == true) {
            count++;
        }
        begin++;
        end++;
    }

    cout << count;
}