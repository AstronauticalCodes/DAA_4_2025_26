class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;
        
        for (int x : arr) totalSum += x;
        
        vector<bool> dp(totalSum + 1, false);
        dp[0] = true;
        
        // Fill DP
        for (int i = 0; i < n; i++) {
            for (int j = totalSum; j >= arr[i]; j--) {
                dp[j] = dp[j] || dp[j - arr[i]];
            }
        }
        
        int mini = INT_MAX;
        
        // Check only till totalSum/2
        for (int s1 = 0; s1 <= totalSum / 2; s1++) {
            if (dp[s1]) {
                int s2 = totalSum - s1;
                mini = min(mini, abs(s2 - s1));
            }
        }
        
        return mini;
    }
};