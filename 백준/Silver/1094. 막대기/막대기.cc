#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int X;
    cin >> X;

    int length = 64;
    vector<int> v;
    v.push_back(length);
    
    while (length > X) {
        
        int num = v.back();
        v.pop_back();
        v.push_back(num/2);
        v.push_back(num/2);
        
        if (length - v.back() >= X) {
            length -= v.back();
            v.pop_back();
        }
    }

    cout << v.size();
}