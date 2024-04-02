#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

typedef vector<vector<long long> > matrix;
// using matrix = vector<vector<long long> >;

matrix operator * (matrix &a, matrix &b) {
    matrix temp(2, vector<long long>(2));

    for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++){
			for (int k = 0; k < 2; k++)
				temp[i][j] += a[i][k] * b[k][j];

			temp[i][j] %= MOD;
		}
	return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;

    matrix ans = {{1, 0}, {0, 1}};
    matrix a = {{1, 1}, {1, 0}};

    while (n > 0) {
        if (n % 2 == 1) {
            ans  = ans * a;
        }
        a = a * a;
        n /= 2;
    }

    cout << ans[0][1];


}