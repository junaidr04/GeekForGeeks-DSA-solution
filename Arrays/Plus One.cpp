// Problem: Plus One
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/plus-one/1?page=1&category=Arrays&company=Google&difficulty=Easy&sortBy=submissions
// Time Complexity: O(n)
// Space Complexity: O(1)

// User function Template for C++

class Solution
{
public:
    vector<int> increment(vector<int> arr, int N)
    {
        int carry = 1;
        for (int i = N - 1; i >= 0; i--)
        {
            int sum = arr[i] + carry;
            arr[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry)
            arr.insert(arr.begin(), 1);
        return arr;
    }
};