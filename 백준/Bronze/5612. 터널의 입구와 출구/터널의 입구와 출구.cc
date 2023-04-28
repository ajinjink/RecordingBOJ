// #include <iostream>
// using namespace std;
// int re(int a, int b){ //a는 행, b는 열
//     int result = 0;
//     if(a == 1){
//         return b;
//     }
//     else if(b == 1){
//         return 1;
//     }
//     else{
//         result = re(a - 1 , b) + re(a , b -1);
//     }
//     return result;
// }

// int main(void){
//     int k, n;
//     int t;
//     cin >> t;
//     for(int i = 0 ; i < t ; i++){
//         cin >> k >> n;
//         cout << re (k , n) << "\n";
//     }
// }






#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m, in, out;

    vector<int> v;

    cin >> n >> m;
    v.push_back(m);
    for (int i = 0; i < n; i++) {
        cin >> in >> out;
        m += in;
        m -= out;
        v.push_back(m);
    }
    sort(v.begin(), v.end());


    if (v[0] < 0) {
        cout << 0;
    }
    else {
        cout << v[n];
    }

}