#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;

    if (num >= 620) cout << "Red";
    else if (num >= 590) cout << "Orange";
    else if (num >= 570) cout << "Yellow";
    else if (num >= 495) cout << "Green";
    else if (num >= 450) cout << "Blue";
    else if (num >= 425) cout << "Indigo";
    else  cout << "Violet";
    
}