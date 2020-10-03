#include <bits/stdc++.h>
using namespace std;

// ! Merge Sort
void merge(vector<int>& arr, int p, int q, int r) {  
  int n1 = q - p + 1;
  int n2 = r - q;

  vector<int> L, M;

  for (int i = 0; i < n1; i++)
    L.push_back(arr[p + i]);
  for (int j = 0; j < n2; j++)
    M.push_back(arr[q + 1 + j]);

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int>& arr, int l, int r) {
  if (l < r) {
    int mid  = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
  }
}

// ! Radix Sort
void radixSort(vector<int> &A){		                 
	int k = A[0];			
	for(auto i = A.begin(); i!=A.end(); i++){	    
		if(*i > k)	k =*i;
	}
	int d =0;
	while(k >0){
		k = k/10;
		d++;                                        
	}
	vector<int> result;
	for(int j =0; j <d; j++)
	{
		vector<int> C(10, 0);						
		vector<int> B(A.size());					
		for(int i = 0 ;i < A.size(); i++){
			int t = (int(A[i]/pow(10,j))%10);
			++C[t];								    
		}										    
		for(int i=1; i< C.size(); i++){			    
			C[i]+= C[i-1]; 							
		}
		for(int i = B.size()-1;i >= 0; i--){
			int t = (int(A[i]/pow(10,j))%10);
			B[C[t]-1] = A[i];					  
			--C[t];								    
		}
		result = A = B;
	}
}

// ! Shell Sort
void shellSort(vector<int>& arr, int n){ 
    for (int gap = n/2; gap > 0; gap /= 2) {  
        for (int i = gap; i < n; i += 1){ 
            int temp = arr[i];
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
            arr[j] = temp; 
        } 
    }
} 

// ! Print Output
void Print(vector<int> &A){
	for(auto i =A.begin(); i!= A.end(); i++){
		cout << *i << " ";
	}
	cout << endl;
}


int main(){
    int t;
    cout << "Input Number of Test Cases : ";
    cin >> t;
    while(t--){
        vector<int> A;
        string sort;
        cout << "Input Sort Name : ";
        cin >> sort;
        long int N;
        cout << "Enter Size : ";
        cin >> N;

        srand(time(NULL));
        for(int i =0; i< N; i++){
            A.push_back(rand()%150);
        }

        cout << "Input Array : " << endl;;
        Print(A);

        switch (tolower(sort[0]))
        {
        case 'm':
            cout << "Sorting using Merge Sort" << endl;
            mergeSort(A, 0, A.size()-1);
            break;
        case 's':
            cout << "Sorting using Shell Sort" << endl;
            shellSort(A, A.size());
            break;
        case 'r':
            cout << "Sorting using Radix Sort" << endl;
            radixSort(A);
            break;
        }

        cout << "Output Sorted Array : " << endl;;
        Print(A);
    }
	
  return 0;

}