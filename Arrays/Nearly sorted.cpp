// Problem: Nearly Sorted
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/nearly-sorted/1?page=1&category=Arrays&company=Google&difficulty=Medium&sortBy=submissions
// time complexity: 0(n log k) [Using min heap of size k]
// space complexity: 0(k) [Min heap of size k]

class Solution
{
public:
    void nearlySorted(vector<int> &arr, int k)
    {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i <= k && i < n; i++)
        {
            pq.push(arr[i]);
        }
        int idx = 0;
        for (int i = k + 1; i < n; i++)
        {
            arr[idx++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        while (!pq.empty())
        {
            arr[idx++] = pq.top();
            pq.pop();
        }
    }
};