#include <iostream>
#include <vector>
using namespace std;

// Function for printing matrix in spiral
void print(vector<vector<int> > arr, int i, int j, int m, int n)
{
    // If i or j lies outside the matrix
    if (i >= m or j >= n)
        return;
 
    // Print First Row
    for (int p = i; p < n; p++)
        cout << arr[i][p] << " ";
 
    // Print Last Column
    for (int p = i + 1; p < m; p++)
        cout << arr[p][n - 1] << " ";
 
    // Print Last Row, if Last and
    // First Row are not same
    if ((m - 1) != i)
        for (int p = n - 2; p >= j; p--)
            cout << arr[m - 1][p] << " ";
 
    // Print First Column,  if Last and
    // First Column are not same
    if ((n - 1) != j)
        for (int p = m - 2; p > i; p--)
            cout << arr[p][j] << " ";
 
    print(arr, i + 1, j + 1, m - 1, n - 1);
}

int main()
{
 
    vector<vector<int> > a;
    int r,c;
    cout<<"Enter number of Rows:"<<"\t";
    cin>>r;
    cout<<"Enter Number of Columns"<<"\t";
    cin>>c;
    for(int i = 0;i<r;i++){
        vector<int> x;
        for(int j = 0;j<c;j++){
            int val;
            cin>>val;
            x.push_back(val);
        }
        a.push_back(x);
    }
    print(a, 0, 0, r, c);
    return 0;
}