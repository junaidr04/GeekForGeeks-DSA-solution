// Problem: Interval List Intersections
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/interval-list-intersections/1?page=1&category=Arrays&company=Amazon&difficulty=Medium&sortBy=submissions
// time complexity: O(n + m) [Iterating through both lists of intervals once]
// space complexity: O(1) [Using constant space to store variables]

class Solution
{
public:
    vector<vector<int>> findIntersection(vector<vector<int>> a, vector<vector<int>> b)
    {
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while (i < a.size() && j < b.size())
        {
            int srt = max(a[i][0], b[j][0]);
            int end = min(a[i][1], b[j][1]);
            if (srt <= end)
            {
                ans.push_back({srt, end});
            }
            if (a[i][1] < b[j][1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};