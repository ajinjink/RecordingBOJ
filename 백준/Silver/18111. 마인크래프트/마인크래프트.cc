#include <iostream>
#include <algorithm>
using namespace std;

bool compare (int x, int y){
    return x > y;
}

int main(){


    int N, M, B, ans = 2147483000, ans_height = 256;
    cin >> N >> M >> B;
    int temp = N * M;
    int* arr = new int[temp];
    for (int i = 0; i < temp; i++){
        cin >> arr[i];
    }
    sort(arr, arr + temp, compare);
    for (int i = arr[temp - 1]; i <= arr[0]; i++){
        int  ans_temp = 0, inven = B;
        for(int j = 0; j < temp; j++){
            int t = arr[j] - i;
            if (t > 0) {
                ans_temp += 2 * t;
                inven += t;
            }
            else {
                inven += t;
                ans_temp -= t;
            }
            if (inven < 0) {
                ans_temp = 2147483000;
                break;
            }
        }
       // cout << ans_temp << "\n";
        if (ans > min(ans, ans_temp)){
            ans_height = i;
            ans = min(ans, ans_temp);
        }
        else if (ans == ans_temp && ans_height != i){
            ans_height = i;
        }
    }
    cout << ans << " " << ans_height << "\n";
}