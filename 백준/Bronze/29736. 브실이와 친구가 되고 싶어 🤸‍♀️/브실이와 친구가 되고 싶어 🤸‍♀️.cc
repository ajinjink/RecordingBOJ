#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, K, X;
	cin >> A >> B >> K >> X;

	if (min(K + X, B) - max(A, K - X) + 1 <= 0) cout << "IMPOSSIBLE\n";
	else cout << min(K + X, B) - max(A, K - X) + 1;
}