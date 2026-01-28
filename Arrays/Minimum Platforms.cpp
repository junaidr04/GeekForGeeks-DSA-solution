// Problem: Minimum Platforms
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1?page=1&company=Google&sortBy=submissions
// Time Complexity: O(n log n)  [Sorting n elements → O(n log n) per array ,TC = O(n log n + n) = O(n log n)]
// Space Complexity: O(1) [constant extra space]

class Solution
{
public:
    int minPlatform(vector<int> &arr, vector<int> &dep)
    {
        int n = arr.size();
        int maxPlatform = 0, platform = 0;
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int i = 0, j = 0;
        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                platform++;
                maxPlatform = max(platform, maxPlatform);
                i++;
            }
            else
            {
                platform--;
                j++;
            }
        }
        return maxPlatform;
    }
};
