#include<bits/stdc++.h>
using namespace std;

 void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

        for(int i=0;i<n;i++){
        	for(int j=0;j<=(n-i-1);j++){
            	

               int temp= matrix[i][j];
                matrix[i][j]=matrix[n-j-1][n-i-1];
                matrix[n-j-1][n-i-1]=temp;

        	}
    	}
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                int temp= matrix[i][n-j-1];
                matrix[i][n-j-1]=matrix[i][j];
                matrix[i][j]=temp;
            }
        }
    }

int main(){
	int n;
	cout<<" please enter the dimensions of the matrix "<<endl;
	vector<vector<int>> matrix;
	cin>>n;

	cout<<"Please enter the elements of the matrix "<<endl;
	for(int i=0;i<n;i++){
		vector<int> temp;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			temp.push_back(a);
		}
		matrix.push_back(temp);
	}
	rotate(matrix);

	for(int i=0;i<n;i++){
		vector<int> temp=matrix[i];
		for(int j=0;j<n;j++){
			cout<<temp[j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}