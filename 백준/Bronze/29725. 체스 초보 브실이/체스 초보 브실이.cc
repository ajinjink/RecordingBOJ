#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int upper[27] = {0};
	int lower[27] = {0};
	
	for (int i = 0; i < 8; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++) {
			if ('a' <= str[j] && str[j] <= 'z') lower[str[j] - 'a']++;
			else if ('A' <= str[j] && str[j] <= 'Z') upper[str[j] - 'A']++;
		}
	}

	int white = 0, black = 0;
	int index[] = {'k' - 'a', 'p' - 'a', 'n' - 'a', 'b' - 'a', 'r' - 'a', 'q' - 'a'};
	int points[6] = {0, 1, 3, 3, 5, 9};
	for (int i = 0; i < 6; i++) {
		white += upper[index[i]] * points[i];
		black += lower[index[i]] * points[i];
	}

	cout << white - black;
}