// Problem: Two Sum - Pair with Given Sum
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/key-pair5616/1?page=1&category=Arrays&company=Google&sortBy=submissions
// Time Complexity: O(n) [Array is scanned once, + hash lookup & insert constant time]
// Space Complexity: O(1) [Worst case of all element unique → n elements hash set]

class Solution
{
public:
    bool twoSum(vector<int> &arr, int target)
    {
        unordered_set<int> freq;
        for (int a : arr)
        {
            int need = target - a;
            if (freq.count(need))
            {
                return true;
            }
            freq.insert(a);
        }
        return false;
    }
};