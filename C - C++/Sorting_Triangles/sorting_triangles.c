//Program which, give the side lengths of triangles will calculate the areas of each, and output the triangles side lengths in order of ascending areas, using linked lists

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct triangle{
	double sideA;
	double sideB;
	double sideC;
	double area;
	struct triangle *nextTriangle;
};
typedef struct triangle Triangle;

double area(double sideA, double sideB, double sideC);

//Functions for implementing merge sort
void mergeSort(Triangle** firstTrianglePtr);
void FrontBackSplit(Triangle* firstTriangle, Triangle** a, Triangle** b);
Triangle* sortedMerge(Triangle* a, Triangle* b);

void printList(Triangle* firstTriangle);

int main(){
	
	int n;
	puts("Enter how many triangles you will enter");
	scanf("%d", &n);
	
	//Allocating space for the first triangle
	Triangle *firstTriangle = (Triangle*) malloc((sizeof(Triangle)));
	Triangle *currentTriangle = firstTriangle; 
	Triangle *previousTriangle;
	
	printf("Enter each side for each of your %d triangles.\n", n);
	
	//Loops and creates triangles to add to the list
	for(int i=0; i<n; i++){		
		printf("Triangle %d:\n", i+1);
		
		scanf("%lf", &(currentTriangle->sideA));
		scanf("%lf", &(currentTriangle->sideB));
		scanf("%lf", &(currentTriangle->sideC));
		
		currentTriangle->area = area(currentTriangle->sideA, currentTriangle->sideB, currentTriangle->sideC);
		
		currentTriangle->nextTriangle = (Triangle*) malloc((sizeof(Triangle)));
		previousTriangle = currentTriangle;
		currentTriangle = currentTriangle->nextTriangle;
	}
	
	//Freeing the last unused node in the list
	free(currentTriangle);
	
	//Ensuring the end of the list has a NULL value
	previousTriangle->nextTriangle = NULL;
	
	//Sorts the list in order of area
	mergeSort(&firstTriangle);
	
	//Prints the sorted list
	printList(firstTriangle);
	
	return 0;
}

//Calculates are of triangles based on Heron's formula; A = sqrt(p*(p−a)*(p−b)*(p−c)), where p = (a+b+c)/2
double area(double a, double b, double c){
	
	double p = (a + b + c) / 2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

//Function to sort the triangles using merge sort
void mergeSort(Triangle **firstTrianglePtr){
	Triangle* firstTriangle = *firstTrianglePtr;
	Triangle* a;
	Triangle* b;
	
	//base case
	if(firstTriangle == NULL || firstTriangle->nextTriangle == NULL)
		return;
	
	else{
		//Split list into list a and b
		FrontBackSplit(firstTriangle, &a, &b);
		
		//Sort list a and b using recursion
		mergeSort(&a);
		mergeSort(&b);
		
		//Merge the sorted lists a and b together
		*firstTrianglePtr = sortedMerge(a, b);
	}
}

//Merges two sorted lists together
Triangle* sortedMerge(Triangle* a, Triangle* b){
	
	Triangle* result;
	
	//base cases
	if(a == NULL)
		return b;
	else if(b == NULL)
		return a;
	
	//if a <= b then b is placed behind a on the list. Otherwise b is placed behind a on the list
	else{
		if(a->area <= b->area){
			result = a;
			result->nextTriangle = sortedMerge(a->nextTriangle, b);
		}
		else{
			result = b;
			result->nextTriangle = sortedMerge(a, b->nextTriangle);
		}
		
		return result;
	}	
}

//Splits the list into two lists a and b
void FrontBackSplit(Triangle* firstTriangle, Triangle** a, Triangle** b){
	Triangle* fast = firstTriangle->nextTriangle;
	Triangle* slow = firstTriangle;
	
	//Everytime slow moves forward one node, fast moves forward two
	while(fast != NULL){
		fast = fast->nextTriangle;
		
		if(fast != NULL){
			slow = slow->nextTriangle;
			fast = fast->nextTriangle;
		}
	}
	//a becomes list from firstTriangle to slow and b becomes list from slow to the end of the list.
	*a = firstTriangle;
	*b = slow->nextTriangle;
	//Separates the two new lists
	slow->nextTriangle = NULL;
}

//Prints the sides of each triangle in the list
void printList(Triangle* firstTriangle){
	Triangle* currentTriangle = firstTriangle;
	
	while(currentTriangle != NULL){
		printf("%lf %lf %lf %lf\n", currentTriangle->sideA, currentTriangle->sideB, currentTriangle->sideC, currentTriangle->area);
		currentTriangle = currentTriangle->nextTriangle;
	}
}






