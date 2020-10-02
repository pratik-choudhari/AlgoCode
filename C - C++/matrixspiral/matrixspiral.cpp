#include <bits/stdc++.h>
using namespace std;

int main() {
	int t ; 
	cin >>t ; 
	while (t--){ 
	 int n , m ; 
	 cin >>m >> n ;
	 vector<vector <int>>mat (m , vector<int>(n));
	 for ( int i = 0 ; i < m ; i++){ 
	     for ( int j = 0 ; j < n ; j++){ 
	           cin >> mat[i][j];
	            }
	     }
	     
	     int ru = 0 , rd= m-1 ,cl= 0, cr = n-1 ; 
	     while ( ru <= rd && cl <= cr){ 
	     
	         for ( int i = cl; i <= cr ; i++){ 
	         
	             cout << mat[ru][i]<<" ";
	         }
	         ru++;
	         for ( int i = ru ; i <= rd ; i++){ 
	         
	             cout << mat[i][cr]<<" ";
	         }
	         cr--;
	         if (ru <= rd){
	         for ( int i = cr ; i >= cl ; i--){ 
	         
	             cout <<mat[rd][i]<<" ";
	         }
	         rd--; 
	             
	            }
	            if ( cl <= cr){ 
	         for ( int i = rd ; i >= ru ; i--){ 
	         
	             cout << mat[i][cl]<<" ";
	         }
	         cl++;
	            
	            }
	     }
	     
	     cout <<endl;    
	}
	return 0;
}