// Problem: Jump Game
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/jump-game/1?page=1&category=Arrays&company=Google&difficulty=Medium&sortBy=submissions
// time complexity: 0(n) [Iterating through the array once]
// space complexity: 0(1) [Constant extra space]

class Solution
{
public:
    bool canReach(vector<int> &arr)
    {
        int maxJump = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i > maxJump)
                return false;
            maxJump = max(maxJump, i + arr[i]);
        }
        return true;
    }
};