// Problem: Remove Duplicates Sorted Array
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1?page=1&category=Arrays&company=Google&difficulty=Basic,Easy&sortBy=submissions
// Time Complexity: O(n) [Array is scanned once, only comparison & assignment inside the loop]
// Space Complexity: O(1) [No extra memory required except for slow pointer (j) and loop variable; in-place solution]

class Solution
{
public:
    vector<int> removeDuplicates(vector<int> &arr)
    {
        int n = arr.size();
        int j = 0;
        if (n == 0)
            return {};
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != arr[j])
            {
                j++;
                arr[j] = arr[i];
            }
        }
        arr.resize(j + 1);
        return arr;
    }
};