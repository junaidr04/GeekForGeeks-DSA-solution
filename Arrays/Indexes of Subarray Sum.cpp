///Problem: Indexes of Subarray Sum
//Platform: GeeksforGeeks
//Link: https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&company=Google&sortBy=submissions
//Time: O(n)  [Outer loop → e 0 to n-1 → O(n)..Inner while loop → s increases, but total s moves at most n times (because each element removed at most once)..Amortized analysis:Outer + inner loop combined → O(n)]
//Space: O(1)  [No extra array, no map, no recursion]


class Solution
{
public:
    vector<int> subarraySum(vector<int> &arr, int target)
    {
        int sum = 0, s = 0;
        for (int e = 0; e < arr.size(); e++)
        {
            sum += arr[e];
            while (sum > target && s <= e)
            {
                sum -= arr[s++];
            }
            if (sum == target)
            {
                return {s + 1, e + 1};
            }
        }
        return {-1};
    }
};

// Time comp should be O(n)... There is another process which time comp is O(n2).It will show TLE..