#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SubsetLongest {
public:
    vector<int> longest(const vector<vector<int>> &dp, const vector<int> &arr, int target) {
        vector<int> ans;
        int currentSum = 0;
        const int INF = 99999;
        int i = 0;

        while (i < static_cast<int>(arr.size()) && currentSum <= target) {
            int take = -INF;

            if (currentSum + arr[i] <= target) {
                take = 1 + dp[i + 1][currentSum + arr[i]];
            }

            int skip = dp[i + 1][currentSum];

            if (take >= skip && take > -INF) {
                ans.push_back(arr[i]);
                currentSum += arr[i];
                i++;
            } else {
                i++;
            }
        }

        return ans;
    }

    int solve(int i, int sum, const vector<int> &arr, vector<vector<int>> &dp, int target) {
        if (i == static_cast<int>(arr.size())) {
            if (sum == target) {
                return 0;
            }
            return -99999;
        }

        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }

        int take = -99999;
        if (sum + arr[i] <= target) {
            take = 1 + solve(i + 1, sum + arr[i], arr, dp, target);
        }

        int skip = solve(i + 1, sum, arr, dp, target);

        dp[i][sum] = (take > skip) ? take : ((take == skip) ? take : skip);
        return dp[i][sum];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter size of array: ";
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array of integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target value: ";
    int target;
    cin >> target;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    SubsetLongest obj;
    cout << "Length of longest subset: " << obj.solve(0, 0, arr, dp, target) << "\n";

    vector<int> subset = obj.longest(dp, arr, target);
    cout << "Longest subset: ";
    for (size_t i = 0; i < subset.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << subset[i];
    }
    cout << "\n";

    return 0;
}