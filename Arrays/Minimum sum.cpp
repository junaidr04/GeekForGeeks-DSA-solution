// Problem: Minimum sum
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/minimum-sum4058/1?page=1&category=Arrays&company=Google&difficulty=Medium&sortBy=submissions
// time complexity: 0(n) [Single pass through the array]
// space complexity: 0(n)

class Solution
{
public:
    string minSum(vector<int> &arr)
    {
        int freq[10] = {0};
        for (int d : arr)
        {
            freq[d]++;
        }
        string num1 = "", num2 = "";
        bool turn = true;
        for (int i = 0; i <= 9; i++)
        {
            while (freq[i] > 0)
            {
                if (turn)
                {
                    num1 += (i + '0');
                }
                else
                {
                    num2 += (i + '0');
                }
                turn = !turn;
                freq[i]--;
            }
        }
        string ans = "";
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry)
        {
            int d1, d2;
            if (i >= 0)
            {
                d1 = num1[i] - '0';
            }
            else
            {
                d1 = 0;
            }
            if (j >= 0)
            {
                d2 = num2[j] - '0';
            }
            else
            {
                d2 = 0;
            }
            int sum = d1 + d2 + carry;
            carry = sum / 10;
            ans += (sum % 10) + '0';
            i--, j--;
        }
        reverse(ans.begin(), ans.end());
        int pos = 0;
        while (pos < ans.size() - 1 && ans[pos] == '0')
        {
            pos++;
        }
        return ans.substr(pos);
    }
};