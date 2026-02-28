// Problem: Surpasser Count
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/surpasser-count-in-an-array/1?page=1&category=Mathematical&company=Amazon&difficulty=Medium&sortBy=submissions
// time complexity: O(nlogn) [Sorting the array and then iterating through it to count surpassers]
// space complexity: O(n) [Storing the sorted array and the surpasser counts]

class Solution
{
public:
    void merge(vector<pair<int, int>> &a, int l, int mid, int r, vector<int> &ans)
    {
        vector<pair<int, int>> temp;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r)
        {
            if (a[i].first < a[j].first)
            {
                ans[a[i].second] += (r - j + 1);
                temp.push_back(a[i++]);
            }
            else
            {
                temp.push_back(a[j++]);
            }
        }
        while (i <= mid)
        {
            temp.push_back(a[i++]);
        }
        while (j <= r)
        {
            temp.push_back(a[j++]);
        }
        for (int k = 0; k < temp.size(); k++)
        {
            a[l + k] = temp[k];
        }
    }
    void mergeSort(vector<pair<int, int>> &a, int l, int r, vector<int> &ans)
    {
        if (l >= r)
        {
            return;
        }
        int mid = (l + r) / 2;
        mergeSort(a, l, mid, ans);
        mergeSort(a, mid + 1, r, ans);
        merge(a, l, mid, r, ans);
    }
    vector<int> findSurpasser(vector<int> &arr)
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