#include <stdio.h>
#include <math.h>

#define TARGET_NUMBER 500
#define PRIME_LIMIT 10000
#define MAX_ARRAY 10000
long int numberOfDivisors(long int input);
long int generateTriangle(long int index);
void generatePrimes(long int limit);

long int primeArray[MAX_ARRAY];
long int main(){
	long int doneFlag = 0;
	long int currentTriIndex = 0;
	long int currentTriNum = 1;
	generatePrimes(PRIME_LIMIT);
	while(doneFlag != 1){
		currentTriNum = generateTriangle(currentTriIndex);
		if(numberOfDivisors(currentTriNum) > TARGET_NUMBER){
			doneFlag = 1;
		} else {
			currentTriIndex++;
		}
	}
	printf("Answer: %d\n", currentTriNum);

	return 0;
}





void generatePrimes(long int limit){
	long int index;
	long int innerLoop;
	long int arrayCopy[MAX_ARRAY];
	long int limitRoot = (long int) sqrt(limit);

	for(index=0;index < MAX_ARRAY;index++){
		primeArray[index] = -1;
		if(index == 0 || index == 1){
			arrayCopy[index] = -1;
		} else {
			arrayCopy[index] = index;
		}
	}
	for(index=2;index < limitRoot;index++){
		if(arrayCopy[index] != -1){

			for(innerLoop = (index*index);innerLoop < PRIME_LIMIT;innerLoop += index){
				arrayCopy[innerLoop] = -1;
			}
		}
	}
	long int copy = 0;
	for(index = 0;index < MAX_ARRAY;index++){
		if(arrayCopy[index] != -1){
			primeArray[copy] = arrayCopy[index];
			copy++;
		}
	}
}


long int numberOfDivisors(long int input){
	//start dividing input by primes
	//if input is divisible by the prime
	//divide input by prime, try to do it again
	//once input is one, stop
	long int digitCount = 0;
	long int count = 1;
	long int index = 0;
	while(input >= 1){
		if(input % primeArray[index] == 0){
			digitCount++;
			input = (input / primeArray[index]);
		} else {
			index++;
			count = count * (digitCount + 1);
			digitCount = 0;
		}
	}

	return count;
}

long int generateTriangle(long int index){
	return (index * (index+1)) / 2;
}
