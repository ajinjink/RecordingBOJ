#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string name;
    int age, weight;

    cin >> name >> age >> weight;
    do {
        int flag = 0;
        if (age > 17) {
            flag = 1;
        }
        if (weight >= 80) {
            flag = 1;
        }
        if (flag) {
            cout << name << " Senior" << '\n';
        }
        else {
            cout << name << " Junior" << '\n';
        }
        cin >> name >> age >> weight;
    } while (!(name == "#" && age == 0 && weight == 0));
}