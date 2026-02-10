// Problem: Stickler Thief
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/stickler-thief/
// time complexity: O(n) [Single pass through the array]
// space complexity: O(1) [Constant space usage]

class Solution
{
public:
    int findMaxSum(vector<int> &arr)
    {
        int prev1 = 0; // dp[i-1]
        int prev2 = 0; // dp[i-2]
        for (int money : arr)
        {
            int take = money + prev2;
            int skip = prev1;
            int curr = max(take, skip);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
