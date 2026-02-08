// Problem: The Celebrity Problem
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/the-celebrity-problem/
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int cand = 0;
        for (int i = 1; i < n; i++)
        {
            if (mat[cand][i] == 1)
            {
                cand = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i == cand)
                continue;
            if (mat[cand][i] == 1 || mat[i][cand] == 0)
            {
                return -1;
            }
        }
        return cand;
    }
};