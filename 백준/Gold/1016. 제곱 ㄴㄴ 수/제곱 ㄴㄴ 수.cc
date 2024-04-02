#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long min, max;
    cin >> min >> max;

    vector<bool> Check(max - min + 1);

    for (long i = 2; i * i <= max; i++) {
        long pow = i * i; // 제곱수
        long start_index = min / pow;

        if (min % pow != 0) {
            start_index++; // min 보다 큰 제곱수부터 시작
        }
        for (long j = start_index; pow * j <= max; j++) { // 제곱수의 배수
            Check[(int)((j * pow) - min)] = true;
        }
    }

    int count = 0;
    for (int i = 0; i <= max - min; i++) {
        if (!Check[i]) { // 제곱이 아닌 수
            count++;
        }
    }

    cout << count;
}