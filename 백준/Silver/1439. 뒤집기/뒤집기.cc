#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string str;
	cin >> str;
	str = str + '3';

	int sub0 = 0, sub1 = 0;
	char prev = str[0];
	for (int i = 1; i < str.length(); i++) {
		if (str[i] != prev) {
			if (prev == '1') {
				sub1++;
				prev = '0';
			}
			else if (prev == '0') {
				sub0++;
				prev = '1';
			}
		}
	}
	cout << min(sub0, sub1);
}