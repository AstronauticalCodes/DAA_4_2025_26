class Solution {
public:
    int coinChange(vector<int>& a, int k) {
        vector<int> f(k + 1, 1e9);
        f[0] = 0;
        
        for(int x : a) {
            for(int i = x; i <= k; i++) {
                if(f[i - x] + 1 < f[i]) {
                    f[i] = f[i - x] + 1;
                }
            }
        }
        
        int ans = f[k];
        if(ans == 1e9) {
            ans = -1;
        }
        return ans;
    }
};