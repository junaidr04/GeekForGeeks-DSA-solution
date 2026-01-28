// Problem: Equilibrium Point
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1?page=1&company=Google&sortBy=submissions
// Time Complexity: O(n) [Single pass for total + single pass for equilibrium]
// Space Complexity: O(1) [Only few variables, no extra array]

class Solution
{
public:
    int findEquilibrium(vector<int> &arr)
    {
        int n = arr.size();
        int total = 0, leftSum = 0;
        for (int i = 0; i < n; i++)
        {
            total += arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            int rightSum = total - leftSum - arr[i];
            if (rightSum == leftSum)
            {
                return i;
            }
            leftSum += arr[i];
        }
        return -1;
    }
};