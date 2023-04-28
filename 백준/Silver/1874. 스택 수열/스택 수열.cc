#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int N, index = 0, pnum = 1;
    cin >> N;
    
    int flag = 1;
    stack<int> s;
    vector<string> res;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    while (index < N) {
        if (pnum <= arr[index]) {
            s.push(pnum);
            res.push_back("+");
            pnum++;
        }
        else {
            if (s.top() == arr[index]) {
                res.push_back("-");
                s.pop();
                index++;
            }
            else {
                cout << "NO";
                flag = 0;
                break;
            }
        }
    }
    if (flag == 1) {
        vector<string>::iterator iter;
        for (iter = res.begin(); iter != res.end(); iter++) {
            cout << *iter << '\n';
        }
    }

}