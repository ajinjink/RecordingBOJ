#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9] = {0};
int num[9] = {0};
int visited[9] = {0};

void choice(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			arr[cnt] = num[i];
			visited[i] = 1;
			choice(cnt + 1);
			visited[i] = 0;
		}
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

	choice(0);


}