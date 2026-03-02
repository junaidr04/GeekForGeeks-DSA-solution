// Problem: Median of 2 Sorted Arrays of Different Sizes
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/median-of-2-sorted-arrays-of-different-sizes/1?page=1&category=Searching&company=Amazon&difficulty=Medium&sortBy=submissions
// time complexity: O(n + m) [Merging the two sorted arrays and finding the median]
// space complexity: O(n + m) [Storing the merged array of size n + m]

class Solution
{
public:
    double medianOf2(vector<int> &a, vector<int> &b)
    {
        vector<int> merge;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i] < b[j])
            {
                merge.push_back(a[i]);
                i++;
            }
            else
            {
                merge.push_back(b[j]);
                j++;
            }
        }
        while (i < a.size())
        {
            merge.push_back(a[i]);
            i++;
        }
        while (j < b.size())
        {
            merge.push_back(b[j]);
            j++;
        }
        int n = merge.size();
        if (n % 2 == 1)
        {
            return merge[n / 2];
        }
        else
        {
            return (merge[n / 2 - 1] + merge[n / 2]) / 2.0;
        }
    }
};

// time complexity: O(log(min(n,m))) [Using binary search to find the correct partition in the smaller array]
// space complexity: O(1) [Using constant space to store variables for binary search]

class Solution
{
public:
    double medianOf2(vector<int> &a, vector<int> &b)
    {
        if (a.size() > b.size())
            return medianOf2(b, a);
        int n = a.size(), m = b.size();
        int low = 0, high = n;
        while (low <= high)
        {
            int cut1 = (low + high) / 2;
            int cut2 = (n + m + 1) / 2 - cut1;
            int l1, l2, r1, r2;
            if (cut1 == 0)
            {
                l1 = INT_MIN;
            }
            else
            {
                l1 = a[cut1 - 1];
            }
            if (cut2 == 0)
            {
                l2 = INT_MIN;
            }
            else
            {
                l2 = b[cut2 - 1];
            }
            if (cut1 == n)
            {
                r1 = INT_MAX;
            }
            else
            {
                r1 = a[cut1];
            }
            if (cut2 == m)
            {
                r2 = INT_MAX;
            }
            else
            {
                r2 = b[cut2];
            }
            if (l1 <= r2 && l2 <= r1)
            {
                if ((n + m) % 2 == 0)
                {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else
                {
                    return max(l1, l2);
                }
            }
            else if (l1 > r2)
            {
                high = cut1 - 1;
            }
            else
            {
                low = cut1 + 1;
            }
        }
        return 0;
    }
};