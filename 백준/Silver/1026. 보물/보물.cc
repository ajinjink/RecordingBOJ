#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> A;
	vector<pair<int, int>> B;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A.push_back({a, 0});
	}
	sort(A.begin(), A.end()); // 오름차순
	for (int i = 0; i < N; i++) {
		int b;
		cin >> b;
		B.push_back({b, i});
	}
	sort(B.begin(), B.end(), greater<> ()); // 내림차순

	for (int i = 0; i < N; i++) {
		A[i].second = B[i].second;
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		res += A[i].first * B[i].first;
	}

	cout << res;
	
}