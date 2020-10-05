
// Hacktoberfest2020 Contribution by Dhrubajyoti Chakraborty
// Binary Search implementation

#include <iostream>
using namespace std;
class BinarySearch
{
public:
  
    void BinSearch(int array[], int keynum, int num)
    {
        int low = 1;
        int high = num;
        int mid;
    do
    {
        mid = (low + high) / 2;
        if (keynum < array[mid])
        {
            high = mid - 1;
        }
   	else if (keynum > array[mid])
        {
            low = mid + 1;
        }
	}
	while (keynum != array[mid] && low <= high);
        if (keynum == array[mid])
        {
            cout<<"SUCCESSFUL \n";
        }
        else
        {
            cout<<"FAILED \n";
        }
    }
};
int main()
{
    int array[10];
    int i, j, num, temp, keynum;
    int low, mid, high;
    cout<<"Enter the value of num \n";
    cin>>num;
    cout<<"Enter the elements one by one \n";
    for (i = 0; i < num; i++)
    {
        cin>>array[i];
    }
    
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < (num - i - 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    cout<<"Enter the element to be searched \n";
    cin>>keynum;
    // searching begins
    BinarySearch b1;
    b1.BinSearch(array, keynum, num);
    return 0;
}