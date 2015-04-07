#include <stdio.h>
#include <stdlib.h>

#define MAXFILE 200
#define MAXNUM 10
#define GRID 15

struct node {
	int x;
	int y;
	int optPrev;
	int nextL;
	int nextR;
};

void makeGraph(int input[][GRID]);
int dijkstra(struct node input[GRID][GRID]);
struct node makeNode(int x, int y, int nextL, int nextR);
int threeMax(int first, int second, int third);

struct node graph[GRID][GRID];

struct node makeNode(int x, int y, int nextL, int nextR){
	struct node temp;
	temp.x = x;
	temp.y = y;
	temp.optPrev = 0;
	if(nextL != -1){
		temp.nextL = nextL;
	}else{
		temp.nextL = 0;
	}
	if(nextR != -1){
		temp.nextR = nextR;
	}else{
		temp.nextR = 0;
	}
	return temp;
}

void makeGraph(int input[][GRID]){
	int i = 0,j=0;
	graph[0][0] = makeNode(0,0,input[0][0],input[0][1]);
	for(i=0;i < GRID;i++){
		for(j=0;j < i;j++){
			if(input[i][j] != -1){
				graph[i][j] = makeNode(i,j,input[i][j],input[i][j+1]);
			}
		}
	}
}

int main(){
	FILE *input_file;
	int inNums[GRID][GRID];
	int row=0,col=0,finalMax = 0;
	char inString[MAXFILE];
	input_file =fopen("input","r");

	for(row=0;row < GRID;row++){
		for(col=0;col < GRID;col++){
			inNums[row][col] = -1;
			graph[row][col] = makeNode(-1,-1,-1,-1);
		}
	}

	row=col=0;

	while (fgets(inString,4, input_file)!=NULL){
		inNums[row][col] = strtol(inString, NULL, 10);
		if(row == col){
			row++;
			col = 0;
		}
		else{
			col++;
		}
	}
	makeGraph(inNums);
	finalMax = dijkstra(graph);
	printf("Max: %d\n", finalMax);
}

int dijkstra(struct node input[GRID][GRID]){
	input[0][0].optPrev = 0;
	int i,j,result=0;

	for(i=0;i < GRID;i++){
		for(j=0;j < i;j++){
			input[i][j].optPrev = threeMax(input[i][j].optPrev, input[i-1][j].optPrev + input[i-1][j].nextL, input[i-1][j-1].optPrev + input[i-1][j-1].nextR);
		}
	}
	for(i = 0; i < GRID; i++){
		result = threeMax(input[GRID-1][i].optPrev + input[GRID-1][i].nextL, input[GRID-1][i].optPrev + input[GRID-1][i].nextR, result);
	}
	return result;
}

int threeMax(int first, int second, int third){
	if(first > second){
		if(first > third){
			return first;
		} else {
			return third;
		}
	} else if(second > third){
		return second;
	} else {
		return third; 
	}
}
