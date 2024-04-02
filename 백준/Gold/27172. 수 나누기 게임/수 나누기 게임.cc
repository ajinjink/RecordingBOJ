#include <iostream>
using namespace std;

int num[100001];
bool exist[1000001] = {0};
int score[1000001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
        exist[num[i]] = true;
    }

    for (int i = 0; i < N; i++) {
        for (int j = num[i] * 2; j < 1000001; j += num[i]) {
            if (exist[j]) {
                score[num[i]]++;
                score[j]--;
            }
        }
    }

    for (int i = 0; i < N; i++) cout << score[num[i]] << ' ';

}