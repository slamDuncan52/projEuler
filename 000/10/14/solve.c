#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SEED 1000000

long next(long input);
long collatz(long seed);

long database[MAX_SEED];

int main(){
	long i;
	long currentSteps = 0;
	long highSeed = 0;
	long highSteps = 0;
	for(i = 0;i < MAX_SEED;i++){
		database[i] = -1;
	}
	database[0] = 0;
	for(i = 1; i < MAX_SEED;i++){
		currentSteps =  collatz(i);
		if(currentSteps > highSteps){
			highSteps = currentSteps;
			highSeed = i;
		}
	}
	printf("Start: %d , Steps: %d\n", highSeed, highSteps);
	return 0;
}


long collatz(long seed){
	long swapStep = 0;
	if(seed-1 < MAX_SEED && database[seed-1] != -1){
		return database[seed-1];
	} else {
		swapStep = collatz(next(seed)) + 1;
		if(seed <= MAX_SEED){
			database[seed-1] = swapStep;
		}
		return swapStep;
	}
}

long next(long input){
	if(input % 2 == 0){
		return input / 2;
	} else {
		return (3 * input) + 1;
	}
}
