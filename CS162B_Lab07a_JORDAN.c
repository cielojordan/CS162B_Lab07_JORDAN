/**********************************************************************
* Project           : Lab 7a
*
* Program name      : PThread Sin
*
* Author            : Cielo Jordan
*
* Date created      : 24 April 2016
*
* Purpose           : Outputs the sum of sin of real numbers
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* run( void *ptr );
int* arr;

int main( int argc, char*argv[] ) {
	int numArgs = argc-1;

	// Print error if there are no arguments
	if (numArgs == 0) {
		perror("Invalid array size.\n");
		exit(1);
	}

	// Dynamically create a pthread_t array, with size equal to number of elements
	pthread_t* threadID;
	threadID = malloc( sizeof(*threadID) * (numArgs) );

	// Dynamically initialize array of integers to be passed
	arr = malloc( sizeof(*arr) * (numArgs) );

	for (int i=0; i<numArgs; i++) {
		arr[i] = atoi(argv[i+1]);
		if ( pthread_create( &threadID[i], NULL, run, (void*) &(i) ) ) {
			perror("Thread creation error.\n");
		}
		if ( pthread_join( threadID[i], NULL) ) {
			perror("Thread creation error.\n");
		}
	}

	// Free the memory by adding dynamically allocated elements to free list
	free(threadID);
	free(arr);
	return 0;
}
 
void* run( void* arg ) {
	int oldPointer = *((int*) arg);
	int oldElement = arr[oldPointer];
	int newElement;
	
	if( oldPointer%2 == 0 ) {
		newElement = oldElement *  oldElement *  oldElement; // If the current index is even: cube the element
	} else {
		newElement = oldElement * (-1); // Else if odd: negate the element
	}
	printf("%d was replaced by %d\n", oldElement, newElement ); // Print the result of the change
}
