// Problem: K-sized subarray maximum
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/k-sized-subarray-maximum/
// Time Complexity: O(n)
// Space Complexity: O(k)

class Solution
{
public:
    vector<int> maxOfSubarrays(vector<int> &arr, int k)
    {
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < arr.size(); i++)
        {
            while (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }
            while (!dq.empty() && arr[i] >= arr[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
            {
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
};