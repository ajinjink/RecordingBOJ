#include <iostream>
#define M 1234567891
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L;
    long long sum = 0;
    string str;

    cin >> L;
    cin >> str;

    long long r = 1;

    for (int i = 0; i < L; i++) {
        sum = (sum + (str[i] - 96) * r) % M;
        r = (r * 31) % M;
    }

    printf("%lld", sum % M);
}