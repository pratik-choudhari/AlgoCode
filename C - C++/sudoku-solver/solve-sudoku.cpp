// Given a partially filled matrix of 9*9 in the form of values.
// The solution is to assign digits (from 1 to 9) to the cells having 0 as its value, so that every row, column, and subgrid of size 3×3 contains exactly one instance of the digits from 1 to 9.	
// Using recursion, backtracking, and simple control statements.

#include<iostream>
using namespace std;
void display(int board[9][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<board[i][j]<<"  ";
		}
		cout<<endl;
	}	
}
bool isValid(int board[9][9], int x, int y, int value){
	for(int j=0;j<9;j++){
		if(board[x][j]==value){
			return false;
		}
	}
	for(int j=0;j<9;j++){
		if(board[j][y]==value){
			return false;
		}
	}
	int smi = x/3*3;
	int smj = y/3*3;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[smi+i][smj+j]==value){
				return false;
			}
		}
	}
	return true;
}
void solveSudoku(int board[9][9], int i, int j){
    // display(board);
	if(i==9){
		display(board);
		return ;
	}
	
	int ni=0, nj=0;
	
	if(j==8){
		ni=i+1;
		nj=0;
	}else{
		ni=i;
		nj=j+1;
	}
	
	if(board[i][j]!=0){
		solveSudoku(board, ni, nj);
	}else{
		for(int pos=1;pos<=9;pos++){
			if(isValid(board, i, j, pos)==true){
				board[i][j]=pos;
				solveSudoku(board, ni,nj);
				board[i][j]=0;
			}
		}
	}
}

int main(){
	int board[9][9], x;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>x;
			board[i][j]=x;
		}
	}
	solveSudoku(board, 0, 0);
	return 0;
}
