// Problem: Peak element
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/peak-element/1?page=1&company=Google&sortBy=submissions
// Time Complexity: O(n) [Single linear pass, early exit possible]
// Space Complexity: O(1) [Only counters, no extra memory]

class Solution
{
public:
    int peakElement(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if ((i == 0 || arr[i] >= arr[i - 1]) && (i == n - 1 || arr[i] >= arr[i + 1]))
            {
                return i;
            }
        }
        return -1;
    }
};
