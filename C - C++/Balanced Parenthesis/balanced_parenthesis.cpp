#include<iostream>
#include<stack>
using namespace std;
bool isbalanced(string s1)
{
    stack<char>s;
    for(int i=0;i < s1.size();i++)
    {
        char ch=s1[i];
        switch(ch)
        {
        case '{':
        case'(':
        case'[': s.push(ch);
        break;
        case '}':
            if(!s.empty()&&s.top()=='{')
                {
                    s.pop();
                }
                else{
                    return false;
                }
                break;
        case ')':
            if(!s.empty()&&s.top()=='(')
                {
                    s.pop();
                }
                else{
                    return false;
                }
                break;
        case ']':
            if(!s.empty()&&s.top()=='[')
                {
                    s.pop();
                }
                else{
                    return false;
                }

        }

    }
    if(s.empty()==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
   string s1;
   cin>>s1;
   if(isbalanced(s1))
   {
       cout<<"Balanced";
   }
   else
   {
       cout<<"not balanced";
   }

}
