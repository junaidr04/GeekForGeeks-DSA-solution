// Problem: Stock Buy and Sell – Max one Transaction Allowed
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/buy-stock-2/1?page=1&category=Arrays&company=Google&difficulty=Easy&sortBy=submissions
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int p : prices)
        {
            minPrice = min(minPrice, p);
            int profit = p - minPrice;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};
