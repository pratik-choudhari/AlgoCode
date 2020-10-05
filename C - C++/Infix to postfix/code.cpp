#include<iostream>
#include<stack>
using namespace std;

int precedence(char c)
{
    if(c=='^')
        return 3;
    else
        if(c=='*'||c=='%'||c=='/')
        return 2;
    else
        if(c=='+'||c=='-')
        return 1;
    else
        return -1;
}
void infixtopostfix(string exp)
{
    stack<char> s;
    int n=exp.length();
    string st;
    s.push('N');
    for(int i=0;i<n;i++)
    {
        if((exp[i]>='a'&&exp[i]<='z')||(exp[i]>='A'&&exp[i]<='Z'))
            st=st+exp[i];
        else
            if(exp[i]=='(')
               s.push(exp[i]);
        else
            if(exp[i]==')')
        {
            while(s.top()!='N' && s.top()!='(')
            {
                char c=s.top();
                s.pop();
                st=st+c;
            }
            if(s.top()=='(')
            {
                char c=s.top();
                s.pop();
            }
        }
        else
        {
            while(s.top()!='N'&&precedence(exp[i])<=precedence(s.top()))
            {
                char c=s.top();
                s.pop();
                st=st+c;
            }
            s.push(exp[i]);
        }
    }
    while(s.top()!='N')
    {
        char c=s.top();
        s.pop();
        st=st+c;
    }
    cout<<st<<endl;
}

int main()
{
    string expression;
    cout<<"Enter an infix expression"<<endl;
    cin>>expression;
    cout<<"Postfix expression is: ";
    infixtopostfix(expression);
    return 0;
}
