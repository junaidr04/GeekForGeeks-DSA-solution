// Problem: Container With Most Water
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/container-with-most-water/1?page=1&category=Arrays&company=Google&difficulty=Medium&sortBy=submissions
// time complexity: 0(n) [Two pointers approach]
// space complexity: 0(1) [Constant extra space]

class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        int l = 0, r = arr.size() - 1, ans = 0;
        while (l < r)
        {
            int width = r - l;
            int height = min(arr[l], arr[r]);
            int water = width * height;
            ans = max(ans, water);
            if (arr[l] < arr[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};