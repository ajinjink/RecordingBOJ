#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
using namespace std;

int solution(vector<vector<int>> jobs) { // 요청시간, 소요시간
    sort(jobs.begin(), jobs.end());
    priority_queue<pii, vector<pii>, greater<pii>> pq; // 소요시간, 요청시간
    
    int i = 0;
    int curtime = 0;
    vector<int> time;
    while (1) {
        if (i >= jobs.size() && pq.empty()) break;
        while (i < jobs.size() && jobs[i][0] <= curtime) {
            pq.push({jobs[i][1], jobs[i][0]});
            i++;
        }
        if (!pq.empty()) {
            pii job = pq.top();
            pq.pop();
            curtime += job.first;
            time.push_back(curtime - job.second);
        }
        else curtime = jobs[i][0];
    }
    
    int sum = 0;
    for (int i = 0; i < time.size(); i++) sum += time[i];
    return sum / time.size();
}