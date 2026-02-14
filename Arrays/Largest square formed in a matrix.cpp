// Problem: Largest square formed in a matrix
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/largest-square-formed-in-a-matrix/1?page=1&category=Arrays&company=Google&difficulty=Medium&sortBy=submissions
// time complexity: 0(n*m) [Single pass through the matrix]
// space complexity: 0(n*m) [DP table of the same size as the input matrix]

class Solution
{
public:
    int maxSquare(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = mat[i][j];
                }
                else if (mat[i][j] == 1)
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
                else
                {
                    dp[i][j] = 0;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};