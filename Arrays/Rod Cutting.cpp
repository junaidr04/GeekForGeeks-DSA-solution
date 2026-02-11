// Problem: Rod Cutting
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/rod-cutting-dp-13/
// time complexity: O(n²) [Nested loops for all lengths and cuts]
// space complexity: O(n) [DP array to store maximum values for each length]


class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
            }
        }
        return dp[n];
    }
};