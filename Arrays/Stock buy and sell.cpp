// Problem: Stock buy and sell
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/stock-buy-and-sell/
// time complexity: O(n)
// space complexity: O(1)

class Solution
{
public:
    int stockBuySell(vector<int> &arr)
    {
        int profit = 0;
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                profit += arr[i] - arr[i - 1];
            }
        }
        return profit;
    }
};