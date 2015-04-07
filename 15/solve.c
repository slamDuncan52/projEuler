#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double factorial(int seed);

int main(int argc, char *argv[]){
	int size = atoi(argv[1]);
	double result = factorial(2 * size) / pow(factorial(size),2);
	printf("There are %.0f paths\n", result);
	return 0;
}

double factorial(int seed){
	if(seed == 0){
		return 1;
	} else{
		return seed * factorial(seed-1);
	}
}
