#include<iostream>
using namespace std;

void automorphic(){
	int num,flag=0;
	cout<<"\nEnter a positive number to check: ";
	//user input
	cin>>num;
	int sq= num*num;
	int store=num;
	//check for automorphic number
	while(num>0)
	{
		if(num%10!=sq%10)
		{    
                    flag=1;
                    break;
                }
		num=num/10;
		sq=sq/10;
	}
	if(flag==1)
		cout<<store<<" is not an Automorphic number.";
	else
		cout<<store<<" is an Automorphic number.";
	
}
//main program
int main()
{
	int ch, a=1;
	do{
		cout<<"\n1. Automorphic Number";
	    cout<<"\n2. Exit";
	    cout<<"\nEnter a Choice :";
	    cin>>ch;
	    switch(ch){
		    case 1: cout<<"Automorphic Number";
		            automorphic();
		            break;
		    case 2: cout<<"Exit";
		            exit(0);
		            break;
		    default: cout<<"Enter a Valid Choice!!";
		             break;
	    }
	}while(a==1);
	
	return 0;
}

/* Output: 
1. Automorphic Number
2. Exit
Enter a Choice :1
Automorphic Number
Enter a positive number to check: 34
34 is not an Automorphic number.
1. Automorphic Number
2. Exit
Enter a Choice :1
Automorphic Number
Enter a positive number to check: 25
25 is an Automorphic number.
1. Automorphic Number
2. Exit
Enter a Choice :5
Enter a Valid Choice!!
1. Automorphic Number
2. Exit
Enter a Choice :2
Exit */
