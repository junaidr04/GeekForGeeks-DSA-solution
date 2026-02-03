// Problem: Longest Common Prefix of Strings
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1?page=1&category=Arrays&company=Google&difficulty=Easy&sortBy=submissions
// Time Complexity: O(N × M²)
// Space Complexity: O(M)
// N = number of strings, M = length of the longest string

// User function template for C++
class Solution
{
public:
    string longestCommonPrefix(vector<string> arr)
    {
        if (arr.empty())
            return "";
        string pref = arr[0];
        int prefLen = pref.size();
        for (int i = 1; i < arr.size(); i++)
        {
            string s = arr[i];
            while (prefLen > s.size() || pref != s.substr(0, prefLen))
            {
                prefLen--;
                if (prefLen == 0)
                {
                    return "";
                }
                pref = pref.substr(0, prefLen);
            }
        }
        return pref;
    }
};