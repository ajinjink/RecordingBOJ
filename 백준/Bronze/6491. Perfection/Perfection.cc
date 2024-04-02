#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		long long N;
		cin >> N;
		if (N == 0) break;
		
		long long sum = 0;

		for (long long i = 1; i < N; i++) {
			if (N % i == 0) sum += i;
		}

		cout << N << " ";

		if (sum > N) cout << "ABUNDANT\n";
		else if (sum == N) cout << "PERFECT\n";
		else cout << "DEFICIENT\n";
	}

	return 0;
}