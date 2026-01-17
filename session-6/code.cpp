#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
        int n = deadline.size();
        
        vector<pair<int, int>> jobs(n);
        for(int i = 0; i < n; ++i) {
            jobs[i] = {deadline[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        for(const auto& job : jobs) {
            int deadline = job.first;
            int profit = job.second;

            pq.push(profit);

            if(pq.size() > deadline) {
                pq.pop();
            }
        }

        int count = pq.size();
        int totalProfit = 0;
        
        while(!pq.empty()) {
            totalProfit += pq.top();
            pq.pop();
        }

        return {count, totalProfit};
    }
};