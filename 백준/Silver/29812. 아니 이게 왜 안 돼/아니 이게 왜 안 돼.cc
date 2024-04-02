#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

	string S;
	int N, D, M, cnt[27] = {0};
	
    cin >> N;
    cin >> S;
    cin >> D >> M;

    int res = 0, len = 0;
    for (char c : S) {
        if (c == 'H' || c == 'Y' || c == 'U') {
            res += min(D * len, M + D);
            cnt[c - 'A']++;
            len = 0;
        }
        else {
            len++;
        }
    }
    res += min(D * len, M + D);

    if (res == 0) {
        cout << "Nalmeok\n";
    }
    else {
        cout << res << '\n';
    }

    int num = min({cnt['H' - 'A'], cnt['Y' - 'A'], cnt['U' - 'A']});
    if (num == 0) {
        cout << "I love HanYang University";
    }
    else {
        cout << num;
    }
    return 0;
}