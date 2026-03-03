// Problem: Count Smaller elements
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/count-smaller-elements/1?page=1&category=Searching&company=Amazon&difficulty=Medium&sortBy=submissions
// time complexity: O(n log n) [Using a balanced binary search tree or a modified merge sort to count smaller elements]
// space complexity: O(n) [Using additional space to store the count of smaller elements for each element in the input array]

// User function Template for C++

class Solution
{
public:
    void merge(vector<pair<int, int>> &a, int l, int mid, int r,
               vector<int> &ans)
    {
        vector<pair<int, int>> temp;
        int i = l;
        int j = mid + 1;
        int rightSmaller = 0;
        while (i <= mid && j <= r)
        {
            if (a[j].first < a[i].first)
            {
                rightSmaller++;
                temp.push_back(a[j]);
                j++;
            }
            else
            {
                ans[a[i].second] += rightSmaller;
                temp.push_back(a[i]);
                i++;
            }
        }
        while (i <= mid)
        {
            ans[a[i].second] += rightSmaller;
            temp.push_back(a[i]);
            i++;
        }
        while (j <= r)
        {
            temp.push_back(a[j]);
            j++;
        }
        for (int k = 0; k < temp.size(); k++)
        {
            a[l + k] = temp[k];
        }
    }
    void mergeSort(vector<pair<int, int>> &a, int l, int r,
                   vector<int> &ans)
    {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        mergeSort(a, l, mid, ans);
        mergeSort(a, mid + 1, r, ans);
        merge(a, l, mid, r, ans);
    }
    vector<int> constructLowerArray(vector<int> &arr)
    {
        int n = arr.size();
        vector<pair<int, int>> a;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            a.push_back({arr[i], i});
        }
        mergeSort(a, 0, n - 1, ans);
        return ans;
    }
};