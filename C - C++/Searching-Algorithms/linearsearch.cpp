
// Hacktoberfest2020 Contribution by Dhrubajyoti Chakraborty
// Linear Search implementation

#include <iostream>
using namespace std;
class LinearSearch
{
    public:
        void LinSearch(int arr[], int value, int i, int n)
        {   int found = 0;
            for (i = 0; i < n ; i++)
            {
                if (value == arr[i] )
                {
                    found = 1;
                    break;
                }
            }
            if (found == 1)
            {
                cout<<"Element is present at index position   "<<i+1;
            }
            else
            {
                cout<<"not present in the array.";
            }
        }
};
int  main()
{  int num;
    int i,  keynum, found = 0;
    cout<<"Enter the no of elements   ";
    cin>>num;
    int array[num];
    cout<<"Enter the elements \n";
    for (i = 0; i < num; i++)
    {
        cin>> array[i];
    }
    cout<<"Enter the element to be searched   ";
    cin>>keynum;
   
    LinearSearch l1;
    l1.LinSearch(array,keynum,i,num);
    return 0;
}