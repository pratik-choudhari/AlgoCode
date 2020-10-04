#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
typedef long long ll;
using namespace std;

int flag[509]={},parent[509]={},val[509]={};

//Function to find the Closest 9's and 0's multiple

void bfs(int n)
{
    int p,q,i;
    string ret="";
    queue < int > myq;
    int temp=9%n;
    flag[temp]=1;
    val[temp]=9;
    myq.push(temp);
    while(1)
    {
        temp=myq.front();
        myq.pop();
        p=temp;
        if(p==0)
        {
            p=0;
            ret+=(char)(val[p]+'0');
            p=parent[p];
            while(p!=0)
            {
                ret+=(char)(val[p]+'0');
                p=parent[p];
            }
            reverse(ret.begin(), ret.end());
            cout << ret << endl;
            return;
        }
        q=((p<<1)+(p<<3))%n;
        if(flag[q]==0)
            myq.push(q),flag[q]=1,parent[q]=p,val[q]=0;
        q+=9%n;
        if(q>=n)q-=n;
        if(flag[q]==0)
            myq.push(q),flag[q]=1,parent[q]=p,val[q]=9;
    }
}
//Main Function

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i;
        memset(flag,0,sizeof(flag));
        memset(parent,0,sizeof(parent));
        scanf("%d",&n);
        bfs(n);
    }
    return 0;
}
