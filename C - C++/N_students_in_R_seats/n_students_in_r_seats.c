//Program to determine the number of ways that n students can occupy n seats in a classroom

#include <stdio.h>
#include <stdbool.h>

long long int factorial(int x);
long long int permutation(int n, int r);
bool isValid(int students, int seats);

int main(){
	int students;
	int seats;
	
	puts("Input number of students");
	scanf("%d", &students);
	
	puts("Input number of seats");
	scanf("%d", &seats);
	
	//If the numbers entered are valid the permutation function is called, otherwise an error is thrown
	if(isValid(students, seats)){
		long long int result = permutation(students, seats);
		printf("There are %lld ways for %d students to occupy %d seats", result, students, seats);
	}
	
	else
		perror("Entry is invalid");
}

//Function to calculate the number of ways for N students to occupy N seats by the permutation formulat nPr = n! / (n-r)!
long long int permutation(int n, int r){
	return factorial(n) / factorial(n-r);
}

//Recursive function which allows for the factorial in the permutation formula
long long int factorial(int x){
	//Base case
	if(x == 1)
		return 1;
	else
		return x*factorial(x-1);
}

//Function which ensures the value given for students is valid
bool isValid(int students, int seats){
	if(students < 1){
		puts("students must be a positive non zero value");
		return false;
	}
	else if(seats < 1){
		puts("seats must be a positive non zero value");
		return false;
	}
	else if(students < seats){
		puts("students must be greater than seats");
		return false;
	}
	else 
		return true;
}

