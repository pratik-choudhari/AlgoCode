/*
Binary Indexed trees or Fenwick trees are used to answer:
1)range sum (logn)
2)point update queries (logn)
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> BIT, a;
int n;

void update(int x, int val) // update BIT after pos x in array is updated with val
{
    for(; x <= n; x += x&-x) // increment least significant bit and update BIT
    {
        BIT[x] += val;
    }
}

int query(int x) //get prefix sum till index x
{
     int sum = 0;
     for(; x > 0; x -= x&-x) // decrement least significant bit and add values of BIT
     {
        sum += BIT[x];
     }

     return sum;
}

int main()
{
    cin>>n; // size of array

    a.resize(n+3);
    BIT.resize(n+3);

    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        update(i,a[i]); // do update in BIT
    }

    int l,r;
    cin>>l>>r; // input range of query

    cout<<query(r)-query(l-1);

    return 0;
}