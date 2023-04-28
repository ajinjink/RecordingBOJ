#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    str += '+';

    vector<int> vi;
    vector<char> vc;

    int res = 0, num =  0;

    num = str[0] - '0';

    for (int i = 1; i < str.length(); i++) {
        if (str[i] == '+') {
            vi.push_back(num);
            num = 0;
            vc.push_back('+');
        }
        else if (str[i] == '-') {
            vi.push_back(num);
            num = 0;
            vc.push_back('-');
        }
        else {
            num = num * 10 + str[i] - '0';
        }

    }



    res = vi[0];
    bool minusflag = false;
    for (int i = 0; i < vc.size() - 1; i++) {
        if (vc[i] == '+' && minusflag == false) {
            res += vi[i + 1];
        }
        if (vc[i] == '-') {
            minusflag = true;
            res -= vi[i + 1];
        }
        if (vc[i] == '+' && minusflag == true) {
            res -= vi[i + 1];
        }

    }

    cout << res;

}