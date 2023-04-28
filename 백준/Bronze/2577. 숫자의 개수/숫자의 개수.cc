#include <iostream>
using namespace std;

int main() 
{
    string res;
    int A, B, C;
    int ans[10] = {0};
    cin >> A >> B >> C;
    int temp = A * B * C;
    while (temp != 0) {
        int tmp = temp % 10;
        ans[tmp]++;
        temp /= 10;
    }
    for (int i = 0; i < 10; i++) {
        cout << ans[i] << '\n';
    }



}