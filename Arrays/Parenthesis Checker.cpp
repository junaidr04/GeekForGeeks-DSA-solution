// Problem: Parenthesis Checker
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1?page=1&company=Google&sortBy=submissions
// Time Complexity: O(n) [loop over string once]
// Space Complexity: O(n) [stack stores at most n opening brackets]

class Solution
{
public:
    bool isBalanced(string &s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty()) // nothing to match
                    return false;
                char top = st.top();
                if (c == ')' && top == '(' || c == '}' && top == '{' || c == ']' && top == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};