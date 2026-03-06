// Problem: Travelling Salesman Problem
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/
// time complexity: O(n^2 * 2^n) [Using dynamic programming with bit masking to solve the problem, where n is the number of cities]
// space complexity: O(n * 2^n) [Using a 2D array to store the minimum cost for each subset of cities and the last visited city]

class Solution
{
public:
    int n;
    int dp[1 << 15][15];
    int solve(int mask, int pos, vector<vector<int>> &cost)
    {
        if (mask == (1 << n) - 1)
        {
            return cost[pos][0];
        }
        if (dp[mask][pos] != -1)
        {
            return dp[mask][pos];
        }
        int ans = INT_MAX;
        for (int city = 0; city < n; city++)
        {
            if ((mask & (1 << city)) == 0)
            {
                int newAns = cost[pos][city] + solve(mask | (1 << city), city, cost);
                ans = min(ans, newAns);
            }
        }
        return dp[mask][pos] = ans;
    }
    int tsp(vector<vector<int>> &cost)
    {
        n = cost.size();
        memset(dp, -1, sizeof(dp));
        return solve(1, 0, cost);
    }
};