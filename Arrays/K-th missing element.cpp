// Problem: k-th missing element
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/k-th-missing-element/
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    int KthMissingElement(vector<int> &arr, int k)
    {
        int n = arr.size();
        int start = arr[0];
        int totalMissing = arr[n - 1] - start + 1 - n;
        if (k > totalMissing)
            return -1;
        for (int i = 0; i < n; i++)
        {
            int miss = arr[i] - (start + i);
            if (miss >= k)
            {
                return start + i + k - 1;
            }
        }
        return -1;
    }
};
