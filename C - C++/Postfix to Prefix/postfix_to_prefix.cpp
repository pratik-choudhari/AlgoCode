#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
#define flag '#'

using namespace std;

bool isOperator(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='$')
	return true;
	else
	return false;
}

int main()
{
	stack<char> stk;
	char postfix[30], prefix[30];
	int j=0,len;
	cout<<"Input a postfix expression: ";
	cin>>postfix;
	len = strlen(postfix);
	for(int i=len-1;i>=0;i--)
	{
		if(isOperator(postfix[i]))
		stk.push(postfix[i]);
		else
		{
			prefix[j++] = postfix[i];
			while(!stk.empty() && stk.top()==flag)
			{
				stk.pop();
				prefix[j++] = stk.top();
				stk.pop();
			}
			stk.push(flag);

		}
	}
	prefix[j] = 0;
	reverse(prefix, prefix + len);
	cout<<"The prefix expression is: "<<prefix;
	return 0;
}
