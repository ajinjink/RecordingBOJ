// #include <iostream>
// #include <vector>
// using namespace std;



// int main() {
//     int N, x, y;
//     cin >> N;

//     vector<pair<int, int> > v;

//     for (int i = 0; i < N; i++) {
//         cin >> x >> y;
//         v.push_back(make_pair(x, y));
//     }



    

// }








#include <iostream>
#include <algorithm>
using namespace std;

class point {
    public:
        int x;
        int y;
        point() {}
};

bool compare(point a, point b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    point* list = new point[N];

    for (int i = 0; i < N; i++) {
        cin >> list[i].x >> list[i].y;
    }

    stable_sort(list, list + N, compare);

    for (int i = 0; i < N; i++) {
        cout << list[i].x << ' ' << list[i].y << '\n';
    }

}