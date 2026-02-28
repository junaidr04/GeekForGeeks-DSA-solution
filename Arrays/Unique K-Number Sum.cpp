// Problem: Unique K-Number Sum
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/unique-k-number-sum/1?page=1&category=Mathematical&company=Amazon&difficulty=Medium&sortBy=submissions
// time complexity: O(k * 2^9) [Generating all possible combinations of k numbers from 1 to 9 and calculating their sums]
// space complexity: O(k) [Storing the unique k-number sums in a set]

class Solution
{
public:
    void solve(int start, int n, int k, vector<int> &curr, vector<vector<int>> &ans)
    {
        if (n == 0 && curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }
        if (n < 0 || curr.size() >= k)
        {
            return;
        }
        for (int i = start; i <= 9; i++)
        {
            curr.push_back(i);
            solve(i + 1, n - i, k, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1, n, k, curr, ans);
        return ans;
    }
};