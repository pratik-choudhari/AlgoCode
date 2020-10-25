#include <iostream> 
#include <float.h> 
#include <stdlib.h> 
#include <math.h> 
using namespace std; 

//To represent a Point in 2D plane 
struct Point 
{ 
	int x, y; 
}; 

// Needed to sort array of points according to X coordinate 
int compareX(const void* a, const void* b) 
{ 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->x - p2->x); 
} 

// Needed to sort array of points according to Y coordinate 
int compareY(const void* a, const void* b) 
{ 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->y - p2->y); 
} 

// A utility function to find the distance between two points 
float dist(Point p1, Point p2) 
{ 
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + 
				(p1.y - p2.y)*(p1.y - p2.y) 
			); 
} 

// Good to use when the n is smaller than 4 
float bruteForce(Point P[], int n) 
{ 
	float min = FLT_MAX; 
	for (int i = 0; i < n; ++i) 
		for (int j = i+1; j < n; ++j) 
			if (dist(P[i], P[j]) < min) 
				min = dist(P[i], P[j]); 
	return min; 
} 
 
float min(float x, float y) 
{ 
	return (x < y)? x : y; 
} 


// A utility function to find the distance between the closest points of strip of a given size.
float stripClosest(Point strip[], int size, float d) 
{ 
	float min = d; // Initialize the minimum distance as d 
 
	for (int i = 0; i < size; ++i) 
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
			if (dist(strip[i],strip[j]) < min) 
				min = dist(strip[i], strip[j]); 

	return min; 
} 

// A recursive function to find the smallest distance.
float closestUtil(Point Px[], Point Py[], int n) 
{ 
	// If there are 2 or 3 points, then use brute force 
	if (n <= 3) 
		return bruteForce(Px, n); 
    
	int mid = n/2; 
	Point midPoint = Px[mid]; 


	// Divide points in y sorted array around the vertical line. 
	Point Pyl[mid]; // y sorted points on left of vertical line 
	Point Pyr[n-mid]; // y sorted points on right of vertical line 
	int li = 0, ri = 0; // indexes of left and right subarrays 
	for (int i = 0; i < n; i++) 
	{ 
	if (Py[i].x <= midPoint.x && li<mid) 
		Pyl[li++] = Py[i]; 
	else
		Pyr[ri++] = Py[i]; 
	} 

	// calculate the smallest distance dl on left of middle point and dr on right side 
	float dl = closestUtil(Px, Pyl, mid); 
	float dr = closestUtil(Px + mid, Pyr, n-mid); 

	float d = min(dl, dr); 
 
	Point strip[n]; 
	int j = 0; 
	for (int i = 0; i < n; i++) 
		if (abs(Py[i].x - midPoint.x) < d) 
			strip[j] = Py[i], j++; 

	//Return the minimum of d and closest distance is strip[] 
	return stripClosest(strip, j, d); 
} 

float closest(Point P[], int n) 
{ 
	Point Px[n]; 
	Point Py[n]; 
	for (int i = 0; i < n; i++) 
	{ 
		Px[i] = P[i]; 
		Py[i] = P[i]; 
	} 

	qsort(Px, n, sizeof(Point), compareX); 
	qsort(Py, n, sizeof(Point), compareY); 

	return closestUtil(Px, Py, n); 
} 

int main() 
{ 
	Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}; 
	int n = sizeof(P) / sizeof(P[0]); 
	cout << "The smallest distance is " << closest(P, n); 
	return 0; 
} 
