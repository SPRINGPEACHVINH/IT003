#include <bits/stdc++.h>
using namespace std;
bool checkLatex(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                return false;
            }
            st.pop();
        }
        else if (c == ']')
        {
            if (st.empty() || st.top() != '[')
            {
                return false;
            }
            st.pop();
        }
        else if (c == '}')
        {
            if (st.empty() || st.top() != '{')
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}
int main()
{
    string s;
    cin >> s;
    if (checkLatex(s))
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}