#include <stdio.h>
#include <stdlib.h>

#define MAXFILE 200
#define GRID_L 100
#define GRID_W 50

//I IS VERTICAL
//J IS HORIZONTAL

int main(){
	FILE *ptr_file;
	int inFile;
	int inNums[GRID_L][GRID_W];
	int i,j;
	int carryBit = 0;
	int answerDigits = 0;
	ptr_file =fopen("input","r");

	while ((inFile = fgetc(ptr_file)) != EOF){
		if(inFile >= '0' && inFile <= '9'){
			inNums[i][j] = inFile - '0';
			if(j == GRID_W-1){
				i++;
				j = 0;
			}
			else{
				j++;
			}
		}
	}
	fclose(ptr_file);

	for(i=GRID_W-1;i >= 0;i--){
		for(j=GRID_L-1;j >= 0;j--){
			carryBit += inNums[j][i];
		}
		if(i <= 9){
			answerDigits += (-i+10) * (carryBit % 10);
		}
		carryBit = carryBit / 10;
	}
	printf("First 10 Digits:%d\n", answerDigits); 
	return 0;
}
