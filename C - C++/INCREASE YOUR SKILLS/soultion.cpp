#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#define ll long long
#define modu 1000000007
using namespace std;

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        ll a, d, k, n, inc, sum = 0;
        cin >> a >> d >> k >> n >> inc;
        sum += a;
        for (int i = 2; i < n + 1; i++)
        {
            sum += d;
            if (i % k == 0)
            {
                d += inc;
            }
        }
        cout << sum << endl;
    }
    return 0;
}