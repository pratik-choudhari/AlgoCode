#include <stdio.h>

int main() {
	long long int num_people; //numbe of people
	printf("Please Enter the number of People: ");
	scanf("%lld",&num_people);
	long long int max_hand = num_people * (num_people-1)/2;//nC2 part
	printf("Maximum Possible Handshakes are: %lld",max_hand); //output
	/*
	*Here you can see I have taken maximum of int i can
	*take, I did not take double or float because cannot 
	*be counted in decimals.
	*/
	return 0;
}
