// Problem: Trapping Rain Water
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1?page=1&category=Arrays&company=Google&sortBy=submissions
// Time Complexity: O(n) [Single traversal with two pointers]
// Space Complexity: O(1) [No extra data structure]

class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        int left = 0, right = arr.size() - 1, leftMax = 0, rightMax = 0, ans = 0;
        while (left < right)
        {
            if (arr[left] < arr[right])
            {
                if (leftMax < arr[left])
                {
                    leftMax = arr[left];
                }
                else
                {
                    ans += leftMax - arr[left];
                }
                left++;
            }
            else
            {
                if (rightMax < arr[right])
                {
                    rightMax = arr[right];
                }
                else
                {
                    ans += rightMax - arr[right];
                }
                right--;
            }
        }
        return ans;
    }
};