#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STRING 1000
#define MAX_POWER 1000

int carryBit = 0;
int numString[MAX_STRING];

void increment(int index);
void cycle();

int main(){
	int i;
	int sum = 0;
	for(i = 0;i < MAX_STRING;i++){
		numString[i] = 0;
	};
	numString[MAX_STRING - 1] = 1;
	for(i = 0;i < MAX_POWER;i++){
		cycle();
	}
	for(i = 0;i < MAX_STRING;i++){
		sum += numString[i];
	}
	printf("%d\n",sum);
	return 0; 
}

void cycle(){
	int j;
	for(j = MAX_STRING-1; j >= 0;j--){
		increment(j);
	}

}

void increment(int index){

	numString[index] = (numString[index] * 2) + carryBit;
	if(numString[index] >= 20){
		carryBit = 2;
	} else if (numString[index] >= 10){
		carryBit = 1;
	} else {
		carryBit = 0;
	}
	numString[index] = numString[index] % 10;
}
