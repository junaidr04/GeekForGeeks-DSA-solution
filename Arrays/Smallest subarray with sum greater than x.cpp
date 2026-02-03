// Problem: Smallest subarray with sum greater than x
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1?page=1&category=Arrays&company=Google&difficulty=Easy&sortBy=submissions
// Time Complexity: O(n) [each element added & removed at most once]
// Space Complexity: O(1)

class Solution {
public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        if(arr.empty()) 
        return 0;
        int n = arr.size();
        int sum = 0, s = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) 
        {
            sum += arr[i];
            while(sum > x) 
            {
                int len = i-s+1;
                if(ans == 0 || len < ans)
                    ans = len; 
                sum -= arr[s];
                s++;
            }
        }
        return ans; 
    }
};
