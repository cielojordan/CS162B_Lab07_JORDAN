|**********************************************************************;
* Project           : Lab 7a
*
* Program name      : Pthread
*
* Author            : Cielo Jordan
*
* Date created      : 12 April 2016
*
* Purpose           : Outputs a dynamically allocated pthread array 
|**********************************************************************;

1. void *run( void *ptr );
	1.A Description: This function prints out the change from the old to the new element after analysis of their parity (even or odd).
	1.B The parameter is void* arg: arguments passed through pthread_create (see Main Function)
	1.C Variables
		1.C.i. int oldElement: the current element passed from the main function
		1.C.ii. int newElement: the changed element depending on parity
		1.C.iii. int currIndex (global): the current index of the element in thread created; incremented everytime a new element is updated
	1.D Conditional statements
		1.D.i. If the current index is EVEN: cube the element
		1.D.ii. If the current index is ODD: negate the element
	1.E Output
		1.E.i. Print out the result of the parity analysis and its effect on the element in array: "Old element Array[index] has been replace by new element Array[index]"
2. Main Function
	2.A Variables
		2.A.i. int numArgs: the number of arguments (not including the program name)
		2.A.ii. pthread_t* threadID: array of thread IDs
		2.A.iii. int* arr: array of integers
		2.A.iv. int created: Determines sucess of thread creation
    
    
    
    |**********************************************************************;
* Project           : Lab 7b
*
* Program name      : Pthread Sin(X)
*
* Author            : Cielo Jordan
*
* Date created      : 24 April 2016
*
* Purpose           : Outputs a dynamically allocated pthread array 
|**********************************************************************;
1. Global Variables
	1.A long double *sum: dynamic array containing all elements in the infinite series; dynamically initialized in the main function and computed in the sumFunction
	1.B long double totalSum: total sum value of all elements in the infinite series; to be computed in the sinFunction
	1.C int currIndex: indicates the current index value of the element in series; incremented by 1 every time total sum has been updated
	1.D int term: indicates the current term value of the infinite series; incremented by 2 (odd number) every time total sum has been updated
	1.E int N: indicates the number of threads to be spawned
2. long double factorial( int limit)
	2.A Description: This function calculates the factorial value of an integer
	2.B The parameter is int limit which will be the basis of the factorial calculation
	2.C Variables
		2.C.i. long double f: factorial of positive integer limit
		2.C.ii. int i: int counter for loop
	2.D For loop: this loop allows the factorial value to be computed as the product of all integers less than or equal to the given integer limit
3. void *sinFunction( void *arg );
	3.A Description: This function calculates the sin of a given integer x
	3.B The parameter is void* arg: arguments passed through pthread_create (see Main Function)
	3.C Variables: 
		3.C.i. long double x: arg value passed during thread creation
		3.C.ii. long double power: x raised to the current term value
		3.C.iii. long double fact: factorial of the current term value
	3.D Conditional statements
		3.D.i. If the current index is EVEN: add to the total sum value
		3.D.ii. If the current index is ODD: subtract from the total sum value
4. Main Function
	4.A Variables
		4.A.i. int N: the number of threads to be spawned (derived from argv[] from user input)
		4.A.ii. pthread_t* threadID: array of thread IDs
		4.A.iii. long double X: converted value of second argument (from user input) to long double; value to be passed to thread
	4.B For loop: this loop allows for the treads to be parallelly created and executed
	4.E Output
		4.E.i. Print out the result of the parity analysis and its effect on the element in array: "sin(X) = [total sum value]"




