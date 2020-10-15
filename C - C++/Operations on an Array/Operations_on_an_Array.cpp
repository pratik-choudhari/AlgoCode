#include <bits/stdc++.h>
using namespace std;

int main() {
	int N ;
	cout<<"Enter value of N: ";
	cin>>N;
	int array[N];
	
	cout<<"Enter N values: ";
	for(int i = 0;i<N;i++){
	    cin>>array[i];
	}
	
	int smallest = INT_MAX;
	int largest = INT_MIN;
	int sum = 0;
	int even = 0;
	int odd = 0;
	int distinct = 0;
	int repeating = 0;
	
	for(int i = 0; i < N;i++){
	    //sum
	    sum+=array[i];
	    
	    //smallest
	    if(array[i] < smallest)
	        smallest = array[i];
	        
	    //largest 
	    if(array[i] > largest)
	        largest = array[i];
	        
	    //Even-Odd
	    if(array[i]%2==0)
	        even++;
	    else
	        odd++;
	        
	}
	
	unordered_map<int,int> map;
	
	for(int i = 0; i < N; i++){
	    if(map.find(array[i])!=map.end())
	        map[array[i]]++;
	    else
	        map.insert({array[i],1});
	}
	
	//OUTPUT
	cout<<endl;
	cout<<"Smallest Number: "<<smallest<<endl;
	cout<<"Largest Number: "<<largest<<endl;
	cout<<"Sum of Array elements = "<<sum<<endl;
	cout<<"Frequency of elements = ";
	for(auto i : map){
	    cout<<i.first<<"-"<<i.second<<" ";
	    
	    //Distinct-Repeating
	    if(i.second == 1)
	        distinct++;
	    else
	        repeating++;
	}
	cout<<endl;
	cout<<"Count of distinct elements = "<<distinct<<endl;
	cout<<"Count of repeating elements = "<<repeating<<endl;
	cout<<"Count of Even elements = "<<even<<endl;
	cout<<"Count of Odd elements = "<<odd<<endl;
	return 0;
}