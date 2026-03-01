// Problem: Last Moment Before All Ants Fall Out
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/last-moment-before-all-ants-fall-out/1?page=1&category=Mathematical&company=Amazon&difficulty=Medium&sortBy=submissions
// time complexity: O(L + R) or O(N) [Calculating the maximum time for ants moving left and right to fall out]
// space complexity: O(1) [Using constant space to store the maximum time]

class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int ans = 0;
        for (int pos : left)
        {
            ans = max(pos, ans);
        }
        for (int pos : right)
        {
            ans = max(ans, n - pos);
        }
        return ans;
    }
};