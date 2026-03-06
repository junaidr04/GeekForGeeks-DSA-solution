// Problem: Count Reverse Pairs
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/count-reverse-pairs/
// time complexity: O(n log n) [Using merge sort to count reverse pairs, where n is the number of elements in the array]
// space complexity: O(n) [Using a temporary array for merging during the merge sort process]

class Solution
{
public:
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        int count = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (j <= high && arr[i] > 2LL * arr[j])
            {
                j++;
            }
            count += (j - (mid + 1));
        }
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left++]);
            }
            else
            {
                temp.push_back(arr[right++]);
            }
        }
        while (left <= mid)
        {
            temp.push_back(arr[left++]);
        }
        while (right <= high)
        {
            temp.push_back(arr[right++]);
        }
        for (int k = low; k <= high; k++)
        {
            arr[k] = temp[k - low];
        }
        return count;
    }
    int mergeSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return 0;
        int mid = (low + high) / 2;
        int count = 0;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
        return count;
    }
    int countRevPairs(vector<int> &arr)
    {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};