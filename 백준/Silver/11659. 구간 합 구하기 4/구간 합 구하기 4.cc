#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int num, time;
    cin >> num >> time;
    vector<long> v(num + 1);
    v[0] = 0;
    for (int i = 1; i < num+1; i++) {
        long temp;
        cin >> temp;
        v[i] = v[i-1] + temp;
    }
    for (int t = 0; t < time; t++) {
        int a, b;
        cin >> a >> b;
        cout << v[b] - v[a-1] << '\n';
    }
    return 0;
}