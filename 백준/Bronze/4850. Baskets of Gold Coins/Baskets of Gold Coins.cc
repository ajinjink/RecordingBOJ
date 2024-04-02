#include <iostream>
using namespace std;

int main(){
	long long n, w, d, r;

    while(cin >> n >> w >> d >> r){
        long long org = n * (n - 1) / 2 * w;
        long long res = (org - r) / d;

        if(!res) cout << n << '\n';
        else cout << res << '\n';
    }
}