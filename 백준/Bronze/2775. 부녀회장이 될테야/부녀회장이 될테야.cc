# include "iostream"
using namespace std;

int main(void){
    int T = 0;
    cin >> T;
    for(int i = 0; i < T; i ++){
        int k, n, ans[14] = {0};
        cin >> k >> n;
        for (int j = 1; j <= n; j++){
            ans[j - 1] = j;
        }
        for (int j = 0; j < k; j++){
            for (int ii = 1; ii < n; ii++){
                ans[ii] += ans[ii - 1];
            }
        }
        cout << ans[n - 1] << '\n';
    }
}