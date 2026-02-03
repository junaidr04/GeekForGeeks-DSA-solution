// Problem: Smallest subarray with sum greater than x
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1?page=1&category=Arrays&company=Google&difficulty=Easy&sortBy=submissions
// Time Complexity: O(n) [each element added & removed at most once]
// Space Complexity: O(1)

class Solution
{
public:
    int smallestSubWithSum(int x, vector<int> &arr)
    {
        if (arr.empty())
            return 0;
        int n = arr.size();
        int minLen = INT_MAX, sum = 0, s = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            while (sum > x)
            {
                minLen = min(minLen, i - s + 1);
                sum -= arr[s];
                s++;
            }
        }
        if (minLen == INT_MAX)
        {
            return 0;
        }
        else
        {
            return minLen;
        }
    }
};