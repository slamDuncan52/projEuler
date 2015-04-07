#include <stdio.h>
#include <stdlib.h>

#define MAXFILE 1000
#define GRID 20

int checkHoriz(int[GRID][GRID]);
int checkVert(int[GRID][GRID]);
int checkDiag1(int[GRID][GRID]);
int checkDiag2(int[GRID][GRID]);
//I IS VERTICAL
//J IS HORIZONTAL
int main(){
	FILE *ptr_file;
	char inFile[MAXFILE];
	int inNums[GRID][GRID];
	int i,j,maxVert,maxHoriz,maxDiag1,maxDiag2,finalMax = 0;
	ptr_file =fopen("input","r");

	while (fgets(inFile,4, ptr_file)!=NULL){
		inNums[i][j] = strtol(inFile, NULL, 10);
		if(j == GRID-1){
			i++;
			j = 0;
		}
		else{
			j++;
		}
	}
	finalMax = maxVert = checkVert(inNums);
	maxHoriz = checkHoriz(inNums);
	maxDiag1 = checkDiag1(inNums);
	maxDiag2 = checkDiag2(inNums);

	if(maxHoriz > finalMax){
		finalMax = maxHoriz;
	}
	if(maxDiag1 > finalMax){
		finalMax = maxDiag1;
	}
	if(maxDiag2 > finalMax){
		finalMax = maxDiag2;
	}
	printf("Max: %d\n",finalMax);
	fclose(ptr_file);
	return 0;
}

int checkHoriz(int input[GRID][GRID]){
	int i,j,max,current = 0;
	for(i=0;i < GRID;i++){
		for(j=0;j < GRID-3;j++){
			current = input[i][j] * input[i][j+1] * input[i][j+2] * input[i][j+3]; 
			if(current > max){
				max = current;
			}	
		}
	}
	return max;
}

int checkVert(int input[GRID][GRID]){
	int i,j,max,current = 0;
	for(i=0;i < GRID-3;i++){
		for(j=0;j < GRID;j++){
			current = input[i][j] * input[i+1][j] * input[i+2][j] * input[i+3][j];
			if(current > max){
				max = current;
			}	
		}
	}
	return max;
}

int checkDiag1(int input[GRID][GRID]){
	int i,j,max,current = 0;
	for(i=0;i < GRID-3;i++){
		for(j=0;j < GRID-3;j++){
			current = input[i][j] * input[i+1][j+1] * input[i+2][j+2] * input[i+3][j+3]; 
			if(current > max){
				max = current;
			}	
		}
	}
	return max;
}

int checkDiag2(int input[GRID][GRID]){
	int i,j,max,current = 0;
	for(i=3;i < GRID;i++){
		for(j=0;j < GRID-3;j++){
			current = input[i][j] * input[i-1][j+1] * input[i-2][j+2] * input[i-3][j+3]; 
			if(current > max){
				max = current;
			}	
		}
	}
	return max;
}



