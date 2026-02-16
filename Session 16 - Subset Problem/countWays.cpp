#include <iostream>
#include <vector>

using namespace std;

class SubsetCountWays
{
public:
    int solve(int i, int sum, const vector<int> &arr, int target, vector<vector<int>> &dp)
    {
        if (i == static_cast<int>(arr.size()))
        {
            return (sum == target) ? 1 : 0;
        }

        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }

        int take = 0;
        if (sum + arr[i] <= target)
        {
            take = solve(i + 1, sum + arr[i], arr, target, dp);
        }

        int nonTake = solve(i + 1, sum, arr, target, dp);
        dp[i][sum] = take + nonTake;
        return dp[i][sum];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter size of array: ";
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array of integers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter target value: ";
    int target;
    cin >> target;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    SubsetCountWays obj;
    cout << "Number of subsets: " << obj.solve(0, 0, arr, target, dp) << "\n";

    return 0;
}