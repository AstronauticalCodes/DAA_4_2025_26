#include <vector>

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;

        int prev = 1;
        int curr = 2;
        int next = 0;

        for (int step = 3; step <= n; ++step)
        {
            next = prev + curr;
            prev = curr;
            curr = next;
        }

        return curr;
    }
};