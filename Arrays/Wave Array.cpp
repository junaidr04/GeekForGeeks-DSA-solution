// Problem: Wave Array
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/wave-array/
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    void sortInWave(vector<int> &arr)
    {
        for (int i = 0; i < arr.size() - 1; i += 2)
        {
            if (arr[i] < arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
};