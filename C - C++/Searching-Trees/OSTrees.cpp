#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 1000001;

void update(int i, int add, vector<int>& OSTree)
{
    while (i > 0 && i < OSTree.size())
    {
        OSTree[i] += add;
        i = i + (i & (-i));
    }
}

int sum(int i, vector<int>& OSTree)
{
    int ans = 0;
    while (i > 0)
    {
        ans += OSTree[i];
        i = i - (i & (-i));
    }

    return ans;
}

int findKthSmallest(int k, vector<int> &OSTree)
{
    int l = 0;
    int h = OSTree.size();
    while (l < h)
    {
        int mid = (l + h) / 2;
        if (k <= sum(mid, OSTree))
            h = mid;
        else
            l = mid+1;
    }

    return l;
}

void insert(int x, vector<int> &OSTree)
{
    update(x, 1, OSTree);
}

void delete_(int x, vector<int> &OSTree)
{
    update(x, -1, OSTree);
}

int findRank(int x, vector<int> &OSTree)
{
    return sum(x, OSTree);
}

int main()
{
    vector<int> OSTree(MAX_VAL);
    insert(10, OSTree);
    insert(55, OSTree);
    insert(23, OSTree);
    insert(42, OSTree);
    insert(20, OSTree);
    insert(91, OSTree);

    cout << "2nd Smallest element is "
    << findKthSmallest(2, OSTree) << endl;

    cout << "Rank of 55 is "
        << findRank(55, OSTree) << endl;

    delete_(42, OSTree);

    cout << "Rank of 20 is "
        << findRank(20, OSTree) << endl;

    return 0;
}

