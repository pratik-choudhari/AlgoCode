#include<iostream>

using namespace std;

class Abundant_Number{
    private:
        int value=0,iterations=0,sum=0;
    
    public:
        void setValue(int val){
            this->value=val;
        }//setValue

        void check_Abundant_no(){
            //we are taking half values as divisors lies till 
            iterations=value/2;

            for(int i=1;i<=iterations;i++)
            {
                if(value%i==0)
                {
                
                    sum=sum+i;
                }//inner_if

            }//for
             if(sum>value)
            {
              
                cout<<value<<" is an Abundant Number !!\n";
                //return 1;
            }//if

            else
            {
                cout<<value<<" is Not an Abundant Number !!\n";
                //return 0;
            }//else  
        }//check_Abundant_no

};//class Abundant_Number

int main(){
    Abundant_Number Ab;
    int val=0;

    cout<<"\n Enter the Value to check for an Abundant Number:";
    cin>>val;
    if(val<=1){
        cout<<val<<" is Not an Abundant Number !!\n";
        return 0;
    }

    else{
        Ab.setValue(val);
        Ab.check_Abundant_no();
    }
    


    //cout<<Ab.getValue();

    return 0;

}//main