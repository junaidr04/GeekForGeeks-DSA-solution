// Problem: Unique Number III
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/unique-number-iii/1?page=1&category=Arrays&company=Google&difficulty=Medium&sortBy=submissions
// time complexity: 0(n) [Iterating through the array once]
// space complexity: 0(1) [Constant extra space]

class Solution
{
public:
    int getSingle(vector<int> &arr)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int sum = 0;
            for (int j = 0; j < arr.size(); j++)
            {
                if (arr[j] & (1 << i))
                {
                    sum++;
                }
            }
            if (sum % 3 != 0)
            {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};