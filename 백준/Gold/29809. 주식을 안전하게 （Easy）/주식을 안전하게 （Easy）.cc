#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1000000007
using ll = long long;
using namespace std;

ll M[11] = {0};
ll D[1000001] = {0};

ll pow_func(long long b, long long ex) {
	if (!ex) return 1;

    ll n = pow_func(b, ex / 2);
    n = n * n % MOD;
    if (ex % 2) n = n * b % MOD; 
    return n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int p, c, k;
	cin >> p >> c >> k;

	if (p == 1) {
		cout << -1 << '\n';
		return 0;
	}

	for (int i = 0; i < p; i++) {
		cin >> M[i];
		if (i) D[i] = M[i] - M[i - 1];
	}

	int tempc = c;
	for (int i = 1; i < p; i++) {
        D[p] += D[p-i] * tempc;
		tempc *= c;
	}
	D[p] = llabs(D[p]) % MOD;
	
	ll cnt = 0;
    while (k > p) k -= p, cnt += p;

    cout << llabs(D[k]) * pow_func(c, cnt) % MOD;
	
}