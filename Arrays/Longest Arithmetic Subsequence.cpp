// Problem: Longest Arithmetic Subsequence
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/longest-arithmetic-subsequence/1?page=1&category=Arrays&company=Google&difficulty=Medium&sortBy=submissions
// time complexity: 0(n^2) [Iterating through the array twice]
// space complexity: 0(n^2) [Using a 2D vector to store the lengths of arithmetic subsequences]

class Solution
{
public:
    int lengthOfLongestAP(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 2)
            return n;
        int ans = 2;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        for (int i = n - 2; i >= 1; i--)
        {
            int j = i - 1, k = i + 1;
            while (j >= 0 && k < n)
            {
                if (arr[j] + arr[k] < 2 * arr[i])
                {
                    k++;
                }
                else if (arr[j] + arr[k] > 2 * arr[i])
                {
                    j--;
                }
                else
                {
                    dp[j][i] = dp[i][k] + 1;
                    ans = max(ans, dp[j][i]);
                    j--;
                    k++;
                }
            }
            while (j >= 0)
            {
                dp[j][i] = 2;
                j--;
            }
        }
        return ans;
    }
};
