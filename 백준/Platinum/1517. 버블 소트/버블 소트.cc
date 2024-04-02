#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int n;
int arr[500001];
int sorted[500001];
ll res = 0;

void merge(int s, int e) {
    int mid = (s + e) / 2;
    int i = s, j = mid + 1;
    int index = s;
    int cnt = 0;

    while (i <= mid && j <= e) {
        if (arr[i] <= arr[j]) { // 왼쪽 배열 정렬
            sorted[index++] = arr[i++];
            res += cnt;
        }
        else { // 오른쪽 배열 정렬
            sorted[index++] = arr[j++];
            cnt++; // 이전 값은 이미 정렬되어 있음
        }
    }
    // 남은 부분
    if (i > mid) { // 오른쪽
        int k = j;
        while (k <= e) {
            sorted[index++] = arr[k++];
            cnt++;
        }
    }
    else { // 왼쪽
        int k = i;
        while (k <= mid) {
            sorted[index++] = arr[k++];
            res += cnt;
        }
    }

    for (int l = s; l <= e; l++) arr[l] = sorted[l]; // 정렬된 배열로 업뎃
}

void mergesort(int s, int e) {
    if (s < e) {
        int mid = (s + e) / 2;
        mergesort(s, mid);
        mergesort(mid + 1, e);
        merge(s, e);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];

    mergesort(0, n - 1);

    cout << res;
}

// 머지 소트의 스왑 개수 = 머지 과정에서 교차점 개수