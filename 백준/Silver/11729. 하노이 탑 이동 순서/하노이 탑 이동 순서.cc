
#include <iostream>
#include <cmath>
using namespace std;

void towersOfHanoi (int disknum, int start, int middle, int dest) {
	if (disknum == 1) {
        cout << start << ' ' << dest << '\n';
    }
    else {
		towersOfHanoi(disknum-1, start, dest, middle);
		cout << start << ' ' << dest << '\n';
		towersOfHanoi(disknum-1, middle, start, dest);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int disknum;
    cin >> disknum;
    cout << (1<<disknum) - 1 << '\n';
    towersOfHanoi(disknum, 1, 2, 3);
}