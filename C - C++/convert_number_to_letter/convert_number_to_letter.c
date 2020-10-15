//Program which takes a number and converts it into its word form

#include <stdio.h>
#include <stdbool.h>

void fixstr(char str [9]);
bool isValid(char str[9]);
void printStr(char str[9]);
int numCount(char str[9]);
void printNumUnit(char c);
void printNumTen(char c);
void printNumTeens(char c);

int main(){
	
	char str[9];
	puts("Please enter a positive number that is less than 9,99,999.");
	
	fgets(str, 9, stdin);
	
	fixstr(str);
	
	//Checks if the given number is valid
	if(isValid(str) == false){
		perror("Value entered is not a valid number");
		return -1;
	}
	else{
		printStr(str);
		return 0;
	}
}

//Function which removes '\n' from the string which fgets() sometimes adds
void fixstr(char str[9]){
	for(int i=0; i<9 && str[i] != '\0'; i++){
		if(str[i] == '\n'){
			str[i] = '\0';
			break;
		}
	}
}

//Function which makes sure that the entered number is valid
bool isValid(char str[9]){
	int i=0;
	while(str[i] != '\0'){
		if(str[i] != ',' && !(str[i] >= '1' && str[i] <= '9')){
			printf("Entry %d in the string is not valid.\n", i+1);
			return false;
		}
		i++;
	}
	
	//Now we know the null terminator is at index i.
	i=0;
	
	while (str[i] != '\0'){
		if(str[i] == ',' && (i != 1 && i != 4)){
			printf("Invalid comma placement at index %d\n", i+1);
			return false;
		}
		i++;
	}
		
	return true;
}

//Function used to print the full string
void printStr(char str[9]){
	int n = numCount(str);
	
	for(int i=0; i<9 && str[i] != '\0'; i++){
		if(str[i] == ',')
			continue;
		//if n is equal to these values we know that the number in question has to be a unit number like one, two, three
		else if(n == 6 || n == 4 || n == 3 || n == 1){
			printNumUnit(str[i]);
		}
		//Otherwise it must be in a position to be a 'ten' number like twenty thirty fourty
		else if(str[i] != '1'){
			printNumTen(str[i]);
		}
		//If the ten number is one then the worded numbers change a lot so they go in a different function and i is incremented twice to account for the use of the next digit in this function
		else{
			printNumTeens(str[++i]);
			n--;
		}
			
		if(n == 6){
			printf("lakh ");
		}
		else if(n == 4){
			printf("thousand ");
		}
		else if(n == 3){
			printf("hundred and ");
		}
		n--;
	}
}

//Function which counts the number of numbers in string
int numCount(char str[9]){
	int count = 0;
	for(int i=0; i<9 && str[i] != '\0'; i++){
		if(str[i] >= '1' && str[i] <= '9')
			count++;
	}
	return count;
}

//Function to print each unit number out (eg. one, two, three)
void printNumUnit(char c){
	switch(c){
		case '1':
			printf("one ");
			break;
		case '2':
			printf("two ");
			break;
		case '3':
			printf("three ");
			break;
		case '4':
			printf("four ");
			break;
		case '5':
			printf("five ");
			break;
		case '6':
			printf("six ");
			break;
		case '7':
			printf("seven ");
			break;
		case '8':
			printf("eight ");
			break;
		case '9':
			printf("nine ");
			break;
		default:
			perror("Error");
			break;
	}	
}

//Function to print each tens number out (eg. twenty, thirty, fourty)
void printNumTen(char c){
	switch(c){
		case '2':
			printf("twenty ");
			break;
		case '3':
			printf("thirty ");
			break;
		case '4':
			printf("fourty ");
			break;
		case '5':
			printf("fifty ");
			break;
		case '6':
			printf("sixty ");
			break;
		case '7':
			printf("seventy ");
			break;
		case '8':
			printf("eighty ");
			break;
		case '9':
			printf("ninety ");
			break;
		default:
			perror("Error");
			break;
	}	
}

//Function to print each teens number out (eg. eleven, twelve, thirteen)
void printNumTeens(char c){
	switch(c){
		case '0':
			printf("ten");
			break;
		case '1':
			printf("eleven ");
			break;
		case '2':
			printf("twelve ");
			break;
		case '3':
			printf("thirteen ");
			break;
		case '4':
			printf("fourteen ");
			break;
		case '5':
			printf("fifteen ");
			break;
		case '6':
			printf("sixteen ");
			break;
		case '7':
			printf("seventeen ");
			break;
		case '8':
			printf("eighteen ");
			break;
		case '9':
			printf("nineteen ");
			break;
		default:
			perror("Error");
			break;
	}	
}








