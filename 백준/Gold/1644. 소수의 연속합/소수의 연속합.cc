#include <iostream>
#include <vector>
using namespace std;

int N;
int cnt = 0;
vector<int> parr;

void makeprime(){
    int* arr = new int[N + 1];

    for (int i = 0; i <= N; i++) {
        arr[i] = 1;
    }

    for (int i = 2; i < N + 1; i++) {
        if (arr[i] == 0) {
            continue;
        }
        else {
            parr.push_back(i);
        }
        for (int j = i * 2; j < N + 1; j+= i) {
            arr[j] = 0;
        }
    }

    delete[] arr;
}

void checksum() {
    int begin = 0;
    int end = 0;
    int sum = parr[0];
    while (end < parr.size()) {
        if (sum == N) {
            cnt++;
            sum -= parr[begin];
            begin++;
            end++;
            sum+= parr[end];
        }
        else if (sum < N) {
            end++;
            sum += parr[end];
        }
        else if (sum > N) {
            sum -= parr[begin];
            begin++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    if (N == 1) {
        cout << 0;
        return 0;
    }

    makeprime();
    checksum();

    cout << cnt;
}