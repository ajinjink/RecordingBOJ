#include <iostream>
using namespace std;

int n, m;
int arr[9] = {0};

void choice(int x, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = x; i <= n; i++) {
		arr[cnt] = i;
		choice(i + 1, cnt + 1);
	}
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> n >> m;

	choice(1, 0);


}