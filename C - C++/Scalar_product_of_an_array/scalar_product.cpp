#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

class scalarProduct{
    private:
        vector<int> v1;

    public:
        void setarray(){
            int value;
            
            while(1){
                cout<<"\nEnter the element (or) Enter -1 to stop entering elements into array: ";
                cin>>value;

                if(value==-1)
                {
                    break;
                
                }
                v1.push_back(value);
                
            }//while

    
        }//setarray

        void printarray(){
            int size=v1.size();

            for(int i=0;i<size;i++){
                cout<<v1[i];
                cout<<" ";

            }
            cout<<"\n";
        }//printarray

        void sortarrayasc(){

            sort(v1.begin(), v1.end());
        }//sortarrayasc

        void sortarraydesc(){

            sort(v1.begin(), v1.end(), greater<int>());
        }//sortarraydesc

        int calculateScalarProduct(scalarProduct s1){
                    
            int size= s1.v1.size();


            int sum=0;
            for(int i=0;i<size;i++){
                
                sum=sum + ((s1.v1[i] * v1[i]));
            }

            return sum;


            
        }//calcualteScalarProduct

        bool checkSize(scalarProduct s1){
                if(v1.size()==s1.v1.size()){
                    return true;
                }
                else{
                    return false;
                }
        }//checksize

};


int main(){

   
        /*
     initailizing the vector array to calculate:
     */
    scalarProduct obj1, obj2;
    obj1.setarray();
    cout<<"\nInserted First array is:";
    obj1.printarray();

    obj2.setarray();
    cout<<"\nInserted Second array is:";
    obj2.printarray();

    /* Method to check size of both vectors should be same
    */
    bool flag=obj2.checkSize(obj1);
    if(flag==true){
        //To find the minimum scalar product of the array:
        //one array should be in ascending order and second array should be in descending order to get the minimim scalar product.
        obj1.sortarrayasc();
        obj2.sortarraydesc();
        cout<<"Minimum Scalar Product is: "<<obj2.calculateScalarProduct(obj1)<<"\n";

        //To find the maximum scalar product of the array:
        //both array should be in ascending order to get the Maximum scalar product.
        obj1.sortarrayasc();
        obj2.sortarrayasc();
        cout<<"Maximum Scalar Product is: "<<obj2.calculateScalarProduct(obj1)<<"\n";
    }//if
    else{
        cout<<"\nPlease insert equal size array's";
    }
    



    return 0;
}//main