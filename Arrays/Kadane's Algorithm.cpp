/// Problem: Kadane's Algorithm
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1?page=1&company=Google&sortBy=submissions
// Time Complexity: O(n), [since the array is traversed once.]
// Space Complexity: O(1), [as only constant extra variables are used.]

class Solution
{
public:
    int maxSubarraySum(vector<int> &arr)
    {
        int sum = arr[0], maxSum = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            sum = max(arr[i], sum + arr[i]);
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};