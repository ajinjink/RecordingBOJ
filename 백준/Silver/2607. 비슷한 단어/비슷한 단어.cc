#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <limits.h>
#define endl '\n'
#define tiii tuple<int, int, int>
using ll = long long;
using namespace std;

int alpha[27] = {0};
int temp[27] {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string word;
    cin >> word;
    for (int i = 0; i < word.length(); i++) alpha[word[i] - 'A']++;

    int res = 0;
    for (int i = 0; i < N - 1; i++) {
        cin >> word;

        fill(&temp[0], &temp[27], 0);
        for (int j = 0; j < word.length(); j++) temp[word[j] - 'A']++;

        int plus = 0, minus = 0;
        for (int j = 0; j < 27; j++) {
            if (alpha[j] < temp[j]) plus += temp[j] - alpha[j];
            else if (alpha[j] > temp[j]) minus += alpha[j] - temp[j];
        }

        if (plus <= 1 && minus <= 1) res++;
    }

    cout << res;

}
