#include<bits/stdc++.h>
using namespace std;
int isOperand(char x)
{
    if(x == '+' || x=='-'|| x=='*' || x=='/' || x==')' || x=='(')
        return 0;
    return 1;
}

int Pre(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 3;
    return 0;
}

int evaluate(string exp)
{
    stack<int> s1; 
    stack<char> s2; 
    int i,x,y,z;
    i=0;
    while(exp[i]!='\0')
    {
    	   	if (isdigit(exp[i])) {
        int value = 0;
        while (isdigit(exp[i]))
            value = value * 10 + exp[i++] - '0';
        s1.push(value);
    } 

       
        else if(!isOperand(exp[i]) && s2.empty())
            s2.push(exp[i++]);
        else if(!isOperand(exp[i]) && !s2.empty())
        {
            if(Pre(exp[i])>Pre(s2.top()) && exp[i]!=')')
                s2.push(exp[i++]);
            else if(exp[i]==')' && s2.top() == '(')
            {
                s2.pop();
                i++;
            }
            else if(exp[i]=='(')
                s2.push(exp[i++]);
            else
            {
         
                x = s1.top();
                s1.pop();
                y = s2.top();
                s2.pop();
                z = s1.top();
                s1.pop();
                if(y == '+')
                    s1.push(z+x);
                else if(y == '-')
                    s1.push(z-x);
                else if(y == '*')
                    s1.push(x*z);
                else if(y == '/')
                    s1.push(z/x);
            } 
        }
    }
    while(!s2.empty())
    {
        x = s1.top();
        s1.pop();
        y = s2.top();
        s2.pop();
        z = s1.top();
        s1.pop();
        if(y == '+')
            s1.push(x+z);
        else if(y == '-')
            s1.push(z-x);
        else if(y == '*')
            s1.push(x*z);
        else if(y == '/')
            s1.push(z/x);
    }
    return s1.top();
}

int main()
{
    string s;
    getline(cin,s);
    cout<<evaluate(s)<<endl;
    return 0;
}
