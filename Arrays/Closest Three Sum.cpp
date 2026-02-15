// Problem: Closest Three Sum
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/closest-three-sum/1?page=1&category=Arrays&company=Google&difficulty=Medium&sortBy=submissions
// time complexity: 0(n^2) [Sorting + Two pointers approach]
// space complexity: 0(1) [Constant extra space]

class Solution
{
public:
    int threeSumClosest(vector<int> arr, int target)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int bestSum = arr[0] + arr[1] + arr[2];
        for (int i = 0; i < n - 2; i++)
        {
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = arr[i] + arr[left] + arr[right];
                if (abs(target - sum) < abs(target - bestSum))
                {
                    bestSum = sum;
                }
                else if (abs(target - sum) == abs(target - bestSum))
                {
                    bestSum = max(bestSum, sum);
                }
                if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return bestSum;
    }
};
