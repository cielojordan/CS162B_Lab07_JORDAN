/**********************************************************************
* Project           : Lab 7b
*
* Program name      : PThread
*
* Author            : Cielo Jordan
*
* Date created      : 12 April 2016
*
* Purpose           : Outputs a dynamically allocated pthread array 
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

long double* sum;
long double totalSum = 0;
int currIndex = 0;
int term = 1;
int N = 0;

long double factorial( long double limit ) {
	long double f = 1;
	for( int i=1; i<=limit; i++ ) {
		f *= i;
	}
	return f;
}

void *sinFunction( void *arg ) {
	long double x = *( (long double*) arg );
	if (x < 0) {
       		printf("Error! Factorial of a negative number doesn't exist.");
	}
	// Compute for the numerator and denominator of each addend
	long double power = pow(x, term);
	long double fact = factorial(term);

	sum[currIndex] = ( power / fact );
	if( currIndex%2 == 0) {
		totalSum += sum[currIndex];
	} else {
		totalSum -= sum[currIndex];
  	}
	currIndex++;
	term += 2;
}

int main ( int argc, char*argv[] ) {
	N = atoi(argv[1]); // number of threads

	// Print error if the number of threads is insufficient
	if( N <= 0 ) {
		perror( "Insufficient number of threads.\n" );
		exit( 1 );
	}

	// Dynamically create a pthread_t array, with size equal to number of elements
	pthread_t* threadID;
	threadID = malloc( sizeof( *threadID ) * N );

	// Dynamically initialize array of sums for sin function
	sum = malloc( sizeof( *sum ) * N );

	// Convert argv to long double
	long double X = strtold(argv[2], NULL);
	
	// Run the threads in parallel
	for ( int i=0; i<N; i++ ) {
		// Print error is thread creation fails.
		if (pthread_create( &threadID[i], NULL, sinFunction, (void*) &(X) ) != 0) {
			perror( "Thread creation error.\n" );
		}
		if ( (pthread_join( threadID[i], NULL ) != 0 ) ) {
			perror( "Thread creation error.\n" );
		}
	}
	printf("sin(%Lf) = %Lf.\n", X, totalSum); // Print output

	// Free the memory by adding dynamically allocated elements to free list
	free(threadID);
	free(sum);
	return 0;
}
