// Problem: Minimum days to make M bouquets
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/minimum-days-to-make-m-bouquets/1?page=1&category=Arrays&company=Google&difficulty=Medium&sortBy=submissions
// time complexity: O(n log(maxDay - minDay)) [Using binary search to find the minimum day]
// space complexity: O(1) [Using constant space to store variables]

class Solution
{
public:
    bool possible(vector<int> &arr, int k, int m, int day)
    {
        int count = 0, noOfB = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= day)
            {
                count++;
            }
            else
            {
                noOfB += (count / k);
                count = 0;
            }
        }
        noOfB += (count / k);
        return noOfB >= m;
    }
    int minDaysBloom(vector<int> &arr, int k, int m)
    {
        int low = INT_MAX, high = INT_MIN;
        if ((long long)m * k > arr.size())
            return -1;
        for (int i = 0; i < arr.size(); i++)
        {
            low = min(low, arr[i]);
            high = max(high, arr[i]);
        }
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (possible(arr, k, m, mid))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};