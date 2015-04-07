#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 1000

int numText(int input);

int main(){
	int i;
	int digitCount = 0;
	for(i = 1;i <= LIMIT;i++){
		digitCount += numText(i);
	}
	printf("Ans: %d\n",digitCount);
}

int numText(int input){
	int result= 0;
	if(input == 1000){
		result += 11;
		input -= 1000;
	}
	else if(input >= 900){
		result += 11;
		input -= 900;
		if(input > 0){
			result += 3;
		}
	}
	else if(input >= 800){
		result += 12;
		input -= 800;
		if(input > 0){
			result += 3;
		}
	}
	else if(input >= 700){
		result += 12;
		input -= 700;
		if(input > 0){
			result += 3;
		}
	}
	else if(input >= 600){
		result += 10;
		input -= 600;
		if(input > 0){
			result += 3;
		}	
	}
	else if(input >= 500){
		result += 11;
		input -= 500;
		if(input > 0){
			result += 3;
		}
	}
	else if(input >= 400){
		result += 11;
		input -= 400;
		if(input > 0){
			result += 3;
		}
	}
	else if(input >= 300){
		result += 12;
		input -= 300;
		if(input > 0){
			result += 3;
		}
	}
	else if(input >= 200){
		result += 10;
		input -= 200;
		if(input > 0){
			result += 3;
		}
	}
	else if(input >= 100){
		result += 10;
		input -= 100;
		if(input > 0){
			result += 3;
		}
	}

	if(input >= 90){
		result += 6;
		input -= 90;
	}
	else if(input >= 80){
		result += 6;
		input -= 80;
	}
	else if(input >= 70){
		result += 7;
		input -= 70;
	}
	else if(input >= 60){
		result += 5;
		input -= 60;
	}
	else if(input >= 50){
		result += 5;
		input -= 50;
	}
	else if(input >= 40){
		result += 5;
		input -= 40;
	}
	else if(input >= 30){
		result += 6;
		input -= 30;
	}
	else if(input >= 20){
		result += 6;
		input -= 20;
	}
	else if(input >= 10){
		if(input == 10){
			result += 3;
			input -= 10;
		}
		else if(input == 11){
			result += 6;
			input -= 11;
		}
		else if(input == 12){
			result += 6;
			input -= 12;
		}
		else if(input == 13){
			result += 8;
			input -= 13;
		}
		else if(input == 14){
			result += 8;
			input -= 14;
		}
		else if(input == 15){
			result += 7;
			input -= 15;
		}
		else if(input == 16){
			result += 7;
			input -= 16;
		}
		else if(input == 17){
			result += 9;
			input -= 17;
		}
		else if(input == 18){
			result += 8;
			input -= 18;
		}
		else if(input == 19){
			result += 8;
			input -= 19;
		}
	}

	if(input == 9){
		result += 4;
		input -= 9;
	}
	else if(input == 8){
		result += 5;
		input -= 8;
	}
	else if(input == 7){
		result += 5;
		input -= 7;
	}
	else if(input == 6){
		result += 3;
		input -= 6;
	}
	else if(input == 5){
		result += 4;
		input -= 5;
	}
	else if(input == 4){
		result += 4;
		input -= 4;
	}
	else if(input == 3){
		result += 5;
		input -= 3;
	}
	else if(input == 2){
		result += 3;
		input -= 2;
	}
	else if(input == 1){
		result += 3;
		input -= 1;
	}
	return result;
}
