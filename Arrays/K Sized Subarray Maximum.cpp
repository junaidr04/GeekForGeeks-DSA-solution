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
            //Remove indices outside window
            while (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }
            //remove smaller elemnts
            while (!dq.empty() && arr[i] >= arr[dq.back()])
            {
                dq.pop_back();
            }
            //add current index
            dq.push_back(i);
            //add max to result when window is full
            if (i >= k - 1)
            {
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }

};
