// Problem: K closest point to origin
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/find-k-closest-points-to-the-origin/1?page=1&category=Mathematical&company=Amazon&difficulty=Medium&sortBy=submissions
// time complexity: O(n log k) [Using a max heap of size k to store the closest points]
// space complexity: O(k) [Storing k closest points in the heap]

// points : 2-d vector containing the (x, y) points
// K : number of closest points that we need to find
// return 2d vector containing the k points in increasing order of distance from origin

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        priority_queue<pair<int, pair<int, int>>> pq;
        for (auto &p : points)
        {
            int x = p[0], y = p[1];
            int dist = x * x + y * y;
            pq.push({dist, {x, y}});
            if (pq.size() > K)
            {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty())
        {
            auto point = pq.top().second;
            pq.pop();
            ans.push_back({point.first, point.second});
        }
        sort(ans.begin(), ans.end(), [](vector<int> &a, vector<int> &b)
             {
            int d1=a[0]*a[0] + a[1]*a[1];
            int d2=b[0]*b[0] + b[1]*b[1];
            if(d1 != d2)
            {
                return d1<d2;
            }
            if(a[0] != b[0])
            {
                return a[0]<b[0];
            }
            return a[1]<b[1]; });
        return ans;
    }
};