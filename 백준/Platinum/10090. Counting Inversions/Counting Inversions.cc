#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int n;
int arr[1000001];
int sorted[1000001];
ll res = 0;

void merge(int s, int e) {
    int mid = (s + e) / 2;
    int i = s, j = mid + 1;
    int index = s;
    int cnt = 0;

    // arr를 반 갈라서 sorted 배열에 하나씩 넣어줄 거야
    // 왼쪽 배열이랑 오른쪽 배열에 포인터 하나씩 두고 비교
    // 교차점 개수를 구할 건데
    // 애초에 반 갈라서 하나씩 끌고 오기 때문에, 왼쪽 배열에서 오른쪽 배열보다 더 큰 값이 나오면 그동안 {오른쪽 배열 값이 더 작았던 만큼} 다 교차하게 되어 있음
    // cnt는 지금 왼쪽에서 더 큰 값이 나오면 몇 개 교차하나
    while (i <= mid && j <= e) {
        if (arr[i] <= arr[j]) { // 왼쪽 배열이 더 작음
            sorted[index++] = arr[i++];
            res += cnt; // 오른쪽 절반에서 나온 선 다 교차하고 숫자 배치
        }
        else { // 오른쪽 배열이 더 작음
            sorted[index++] = arr[j++];
            cnt++; // 오른쪽 절반에서 나오고 있는 선 개수
        }
    }
    // 남은 부분. 투 포인터로 정렬하다가 마지막에 한 쪽은 큰 값이 주르륵 남아
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