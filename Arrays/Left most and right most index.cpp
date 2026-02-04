// Problem: Left most and right most index
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/find-first-and-last-occurrence-of-x0849/1?page=1&category=Arrays&company=Google&difficulty=Easy&sortBy=submissions
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution
{
public:
    pair<long, long> indexes(vector<long long> v, long long x)
    {
        int n = v.size();
        int first = -1, last = -1, low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (v[mid] == x)
            {
                first = mid;
                high = mid - 1;
            }
            else if (v[mid] < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (v[mid] == x)
            {
                last = mid;
                low = mid + 1;
            }
            else if (v[mid] < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return {first, last};
    }
};