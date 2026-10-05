#include <iostream>
#include <stack>
using namespace std;
int priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}
int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    stack<char> s;
    cout << "Postfix expression: ";
    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];
        if (isalnum(ch))
        {
            cout << ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() &&
                   priority(s.top()) >= priority(ch))
            {
                cout << s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}
