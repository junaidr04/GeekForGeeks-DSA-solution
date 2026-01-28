// Problem: Kth Smallest
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1?page=1&company=Google&sortBy=submissions
// Time Complexity: O(n log k)  [n elements, push/pop in heap size k]
// Space Complexity: O(k) [heap maintains k elements]

class Solution
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        priority_queue<int> q;
        for (int s : arr)
        {
            q.push(s);
            if (q.size() > k)
            {
                q.pop();
            }
        }
        return q.top();
    }
};