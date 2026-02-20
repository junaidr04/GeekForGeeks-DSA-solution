// Problem: Stickler Thief II
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/stickler-thief-ii/1?page=1&category=Arrays&company=Amazon&difficulty=Medium&sortBy=submissions
// time complexity: O(n) [Iterating through the array once to calculate the maximum loot]
// space complexity: O(1) [Using constant space to store variables]

class Solution
{
public:
    int solve(vector<int> &arr, int start, int end)
    {
        int prev1 = 0, prev2 = 0;
        for (int i = start; i <= end; i++)
        {
            int take = arr[i] + prev2;
            int skip = prev1;
            int curr = max(take, skip);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int maxValue(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return arr[0];
        int c1 = solve(arr, 0, n - 2), c2 = solve(arr, 1, n - 1);
        return max(c1, c2);
    }
};
