// Problem: Maximum Product Subarray
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1?page=1&category=Arrays&company=Google&sortBy=submissions
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    int maxProduct(vector<int> &arr)
    {
        int ans = arr[0];
        int maxP = arr[0], minP = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] < 0)
                swap(maxP, minP);
            maxP = max(arr[i], arr[i] * maxP);
            minP = min(arr[i], arr[i] * minP);
            ans = max(ans, maxP);
        }
        return ans;
    }
};