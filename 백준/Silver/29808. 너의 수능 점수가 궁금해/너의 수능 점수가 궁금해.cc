#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	if (N % 4763) {
		cout << 0 << '\n';
		return 0;
	}

	N /= 4763;

	vector<pair<int, int>> res;

	for (int i = 0; i <= 200; i++){
        for (int j = 0; j <= 200; j++){
            if (i*508+j*212 == N or i*508+j*305 == N or i*108+j*212 == N or i*108+j*305 == N)
                res.push_back({i, j});
        }
    }	

	sort(res.begin(), res.end());

	cout << res.size() << '\n';
	for (int i = 0; i < res.size(); i++) cout << res[i].first << ' ' << res[i].second << '\n';
}

