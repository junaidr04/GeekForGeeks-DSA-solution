// Problem: Overlapping Intervals
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1?page=4&company=Google&sortBy=submissions
// Time Complexity: O(n log n)  [TC = O(n log n + n) = O(n log n)]
// Space Complexity: O(n)

class Solution
{
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
    {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        ans.push_back(arr[0]);
        for (int i = 0; i < arr.size(); i++)
        {
            vector<int> &last = ans.back();
            if (arr[i][0] <= last[1])
            {
                last[1] = max(last[1], arr[i][1]);
            }
            else
            {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};