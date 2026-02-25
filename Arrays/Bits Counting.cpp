// Problem: Bits Counting
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/count-set-bits-in-an-integer/1?page=1&category=Mathematical&company=Amazon&difficulty=Medium&sortBy=submissions
// time complexity: O(n) [Iterating through all bits of the integer]
// space complexity: O(n) [Using a vector to store the count of set bits for each integer up to n]

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (int i = 0; i <= n; i++)
        {
            int x = i;
            int count = 0;
            while (x > 0)
            {
                if (x % 2 == 1)
                {
                    count++;
                }
                x = x / 2;
            }
            ans.push_back(count);
        }
        return ans;
    }
};