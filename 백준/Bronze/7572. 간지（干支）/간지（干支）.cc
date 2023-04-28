#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ten[10] = {1,2,3,4,5,6,7,8,9,10};
    char twelve[12] = {'A','B','C','D','E','F','G','H','I','J','K','L'};

    int N;
    cin >> N;
    int year = (N + 56) % 60;
    int tennum = year % 10;
    char twelvechar = twelve[year%12];

    cout << twelvechar << tennum;
}







