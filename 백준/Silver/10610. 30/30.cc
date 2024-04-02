#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string str;
	cin >> str;

	vector<int> num;
	
	bool zero = false;
	int sum = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0') zero = true;
		sum += str[i] - '0';
		num.push_back(str[i] - '0');
	}

	if (sum % 3 || !zero) {
		cout << -1;
		return 0;
	}

	sort(num.begin(), num.end(), greater<> ());
	for (int i : num) cout << i;


}