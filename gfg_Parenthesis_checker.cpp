#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<int> stack;
    
        for (int i=0; i<x.length(); i++)
        {
            if(x[i] == '(' || x[i] == '[' || x[i] == '{')
            {
                stack.push(x[i]);
            }
            else if (x[i] == ')')
            {
                if(stack.empty() || stack.top() != '(')
                {
                    return false;
                }
                else
                {
                    stack.pop();
                }
                
            }
            else if (x[i] == ']')
            {
                if(stack.top() != '[' || stack.empty())
                {
                    return false;
                }
                else
                {
                    stack.pop();
                }
            }
            else if (x[i] == '}')
            {
                if(stack.top() != '{' || stack.empty())
                {
                    return false;
                }
                else
                {
                    stack.pop();
                }
            }
        }
        
        if(!stack.empty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

int main()
{
    int t;
    string a;
    cin >> t;
    while(t--)
    {
        cin >> a;
        Solution obj;
        if(obj.ispar(a))
            cout << "b" << endl;
        else 
            cout << "ub" << endl;
    }
}