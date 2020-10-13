#include <iostream>
using namespace std;

int countSingleDigits(unsigned long long int x){
    unsigned long long int counter[10]= {0};
    unsigned long long int num =x, c=0;
    
    while(num!=0){
        counter[num%10]++;
        num/=10;
    }
    for(int i=0; i<10; i++){
        if(counter[i] == 1)
            c++;
    }
    return c;
}


int main()
{
    unsigned long long int x = 111555667234;
   cout<<countSingleDigits(x);
   
   return 0;
}