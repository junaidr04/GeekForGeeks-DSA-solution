// Problem: Find triplets with zero sum
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero/
// time complexity: O(n^2) [Sorting + Two-pointer approach]
// space complexity: O(1) [In-place sorting, no extra data structures]

class Solution
{
public:
    bool findTriplets(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum == 0)
                {
                    return true;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return false;
    }
};