// C++ recursive function to  
// solve tower of hanoi puzzle  
#include <bits/stdc++.h> 
using namespace std; 
  
static long int counter = 0;
  
void towerOfHanoi(int n, char from_rod, 
                    char to_rod, char aux_rod)  
{  
    counter++;
    if (n == 1)  
    {  
        cout << "Move disk 1 from " << from_rod <<  
                            " to " << to_rod<<endl;  
        return;  
    }  
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);  
    cout << "Move disk " << n << " from " << from_rod << 
                                " to " << to_rod << endl;  
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);  
}  
  
// Driver code 
int main()  
{  
    int n; // Number of disks
    cin>>n;
    char A,B,C;
    cin>>A>>B>>C;
    towerOfHanoi(n, A, C, B); // name of labels are assigned to A, B and C 
    cout<<"It took "<<counter<<" moves in total"<<endl;
    return 0;  
}
