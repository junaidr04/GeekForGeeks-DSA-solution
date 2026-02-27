// Problem: Missing Intervals
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/find-missing-intervals-in-a-given-range/1?page=1&category=Mathematical&company=Amazon&difficulty=Medium&sortBy=submissions
// time complexity: O(n) [Iterating through the sorted intervals once to find the missing intervals]
// space complexity: O(n) [Storing the missing intervals in a vector]

class Solution
{
public:
    vector<pair<int, int>> missingIntervals(vector<int> &arr, int l, int r)
    {
        vector<pair<int, int>> ans;
        int prev = l - 1;
        for (int x : arr)
        {
            if (x - prev > 1)
            {
                ans.push_back({prev + 1, x - 1});
            }
            prev = x;
        }
        if (r - prev >= 1)
        {
            ans.push_back({prev + 1, r});
        }
        if (ans.empty())
        {
            return {{-1, -1}};
        }
        return ans;
    }
};
