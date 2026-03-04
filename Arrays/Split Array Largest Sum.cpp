// Problem: Split Array Largest Sum
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/split-array-largest-sum/1?page=1&category=Searching&company=Amazon&difficulty=Medium&sortBy=submissions
// time complexity: O(n log(sum of array elements)) [Using binary search to find the minimum largest sum and checking feasibility in O(n) time]
// space complexity: O(1) [Using constant extra space for variables]

class Solution
{
public:
    bool possible(int mid, vector<int> &arr, int k)
    {
        int count = 1, sum = 0;
        for (int x : arr)
        {
            sum += x;
            if (sum > mid)
            {
                count++;
                sum = x;
            }
        }
        return count <= k;
    }
    int splitArray(vector<int> &arr, int k)
    {
        int start = *max_element(arr.begin(), arr.end());
        int end = accumulate(arr.begin(), arr.end(), 0);
        int ans = end;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (possible(mid, arr, k))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};