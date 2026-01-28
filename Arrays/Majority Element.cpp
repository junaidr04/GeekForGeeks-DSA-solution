// Problem: Majority Element
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/majority-element-1587115620/1?page=1&company=Google&sortBy=submissions
// Time Complexity: O(n),
// Space Complexity: O(1),

class Solution
{
public:
    int majorityElement(vector<int> &arr)
    {
        int n = arr.size();
        int count = 0, candidate = 0;
        for (int num : arr)
        {
            if (count == 0)
            {
                candidate = num;
            }
            if (candidate == num)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        count = 0;
        for (int num : arr)
        {
            if (candidate == num)
            {
                count++;
            }
        }
        if (count > n / 2)
        {
            return candidate;
        }
        return -1;
    }
};
