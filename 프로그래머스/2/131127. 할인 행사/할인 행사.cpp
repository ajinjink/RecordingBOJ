#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool check(vector<int> number) {
    for (int n : number) {
        if (n > 0) return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> index;
    for (int i = 0; i < want.size(); i++) index[want[i]] = i;
    
    int l = 0, r = 9;
    for (int i = 0; i < 10; i++) {
        if (index.find(discount[i]) != index.end()) {
            number[index[discount[i]]]--;
        }
    }
    if (check(number)) answer++;
    
    while (r < discount.size() - 1) {           
        if (index.find(discount[l]) != index.end()) number[index[discount[l]]]++;
        l++; r++;
        if (index.find(discount[r]) != index.end()) number[index[discount[r]]]--;
        if (check(number)) answer++;
    }
    
    return answer;
}