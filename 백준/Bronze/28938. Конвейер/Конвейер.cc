#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    int sum = 0;
    while (N--) {
        int a;
        cin >> a;
        sum += a;
    }

    if (sum > 0) cout << "Right";
    else if (sum < 0) cout << "Left";
    else cout << "Stay";
}