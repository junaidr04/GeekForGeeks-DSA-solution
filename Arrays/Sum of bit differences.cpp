// Problem: Sum of bit differences
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/sum-of-bit-differences-among-all-pairs/1?page=1&category=Arrays&company=Google&difficulty=Medium&sortBy=submissions
// time complexity: 0(n) [Iterating through the array once]
// space complexity: 0(1) [Constant extra space]

class Solution
{
public:
    int sumBitDifferences(vector<int> &arr)
    {
        int ans = 0, n = arr.size();
        for (int i = 0; i < 32; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] & (1 << i))
                {
                    count++;
                }
            }
            ans += (count * (n - count) * 2);
        }
        return ans;
    }
};