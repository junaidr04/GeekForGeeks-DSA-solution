// Problem: Majority Element - More Than n/3
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/majority-element-n3/
// time complexity: O(n)
// space complexity: O(1)

class Solution
{
public:
    vector<int> findMajority(vector<int> &arr)
    {
        int n = arr.size();
        int count1 = 0, count2 = 0, candidate1 = 0, candidate2 = 1;
        for (int num : arr)
        {
            if (num == candidate1)
            {
                count1++;
            }
            else if (num == candidate2)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0)
            {
                candidate2 = num;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for (int num : arr)
        {
            if (num == candidate1)
            {
                count1++;
            }
            else if (num == candidate2)
            {
                count2++;
            }
        }
        vector<int> ans;
        if (count1 > n / 3)
        {
            ans.push_back(candidate1);
        }
        if (count2 > n / 3)
        {
            ans.push_back(candidate2);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
