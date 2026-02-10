// Problem: Next Permutation
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/next-permutation/
// time complexity: O(n) [Single pass to find the next permutation]
// space complexity: O(1) [In-place modification of the array]

class Solution
{
public:
    void nextPermutation(vector<int> &arr)
    {
        int n = arr.size();
        int i = n - 2;
        while (i >= 0 && arr[i] >= arr[i + 1])
        {
            i--;
        }
        if (i >= 0)
        {
            int j = n - 1;
            while (arr[j] <= arr[i])
            {
                j--;
            }
            swap(arr[i], arr[j]);
        }
        reverse(arr.begin() + i + 1, arr.end());
    }
};