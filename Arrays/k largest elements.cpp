// Problem: K Largest Elements
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/k-largest-elements-in-an-array/
// time complexity: O(n log k) [Using a min-heap of size k]
// space complexity: O(k) [Min-heap to store the k largest elements]

class Solution
{
public:
    vector<int> kLargest(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int val : arr)
        {
            minHeap.push(val);
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
        vector<int> ans;
        while (!minHeap.empty())
        {
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};