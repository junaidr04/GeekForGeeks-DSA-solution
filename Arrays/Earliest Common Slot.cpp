// Problem: Earliest Common Slot
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/find-the-earliest-common-time-slot-for-two-people-to-have-a-meeting/1?page=1&category=Mathematical&company=Amazon&difficulty=Medium&sortBy=submissions
// time complexity: O(n log n + m log m) [Sorting + two-pointer traversal]
// space complexity: O(1) [Only constant extra space for result vector]

class Solution
{
public:
    vector<int> commonSlot(vector<vector<int>> &a, vector<vector<int>> &b, int d)
    {
        int i = 0, j = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        while (i < a.size() && j < b.size())
        {
            int srt = max(a[i][0], b[j][0]);
            int end = min(a[i][1], b[j][1]);
            if (end - srt >= d)
            {
                return {srt, srt + d};
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
        return {};
    }
};