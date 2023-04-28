#include <iostream>
#include <algorithm>
using namespace std;

class person {
    public:
        int age;
        string name;
        person() {}
};

bool compare(person a, person b) {
    return a.age < b.age;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    person* list = new person[N];

    for (int i = 0; i < N; i++) {
        cin >> list[i].age >> list[i].name;
    }

    stable_sort(list, list + N, compare);

    for (int i = 0; i < N; i++) {
        cout << list[i].age << ' ' << list[i].name << '\n';
    }

}