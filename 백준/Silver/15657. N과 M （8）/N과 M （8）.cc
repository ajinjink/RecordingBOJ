#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9] = {0};
int num[9] = {0};
int visited[9] = {0};

void choice(int index, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = index; i < n; i++) {
			arr[cnt] = num[i];
			choice(i, cnt + 1);
	}
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);

	choice(0, 0);


}