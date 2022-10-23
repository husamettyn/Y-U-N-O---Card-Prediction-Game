#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int main(){
	int table[8][8] = {0}, numbers[32];
	int difficulty, x1, x2 , Y1, y2;
	int i=0, j=0, found=0, length;
	int win=0, player=1, tour = 1, point1 = 0, point2 = 0;
	int memory[3][16] = {0}, memoryMax;
	char name[20], gameTable[9][9] = {{' ', '1', '2', '3', '4', '5', '6', '7', '8'},{'1', '*', '*', '*', '*', '*', '*', '*', '*'},{'2', '*', '*', '*', '*', '*', '*', '*', '*'},{'3', '*', '*', '*', '*', '*', '*', '*', '*'},{'4', '*', '*', '*', '*', '*', '*', '*', '*'},{'5', '*', '*', '*', '*', '*', '*', '*', '*'},{'6', '*', '*', '*', '*', '*', '*', '*', '*'},{'7', '*', '*', '*', '*', '*', '*', '*', '*'},{'8', '*', '*', '*', '*', '*', '*', '*', '*'}};
	srand(time(NULL));
	/*  
	* MEMORY ARRAY placement
	* x-> memory[0][i]
	* y-> memory[1][i]
	* Value-> memory[2][i]
	*/
//----------------------------------------User Choosing a Difficulty--------------------------------------------------------------------------------------------
	printf("******************************** Y U N O ************************************\n                        Welcome To  Y U N O  The Game\n\n Please Enter Your Name: ");
	scanf("%s", &name);
	printf("\n      Please Choose a Difficulty...\n      - Easy    =  1 *\n      - Medium  =  2 **\n      - Hard    =  3 ***\n->");
	scanf("%d", &difficulty);
	if(difficulty == 1){
	difficulty = 4, memoryMax = 2;}
	else if(difficulty == 2){
	difficulty = 6, memoryMax = 6;}
	else if(difficulty == 3){
	difficulty = 8, memoryMax = 16;}
	length = (difficulty*difficulty/2);
//---------------------------------------Putting Numbers Into Main Table--------------------------------------------------
	for(i=0; i<length; i++){
		numbers[i] = i+1;
	}
	i = 0;
	while(i < length){
		x1 = rand() % difficulty;
		Y1 = rand() % difficulty;
		x2 = rand() % difficulty;
		y2 = rand() % difficulty;
		while((x1 == x2 && Y1 == y2) || (table[x1][Y1] != 0 || table[x2][y2] != 0)){
			x1 = rand() % difficulty;
			Y1 = rand() % difficulty;		
			x2 = rand() % difficulty;
			y2 = rand() % difficulty;	
		}
		table[x1][Y1] = numbers[i];
		table[x2][y2] = numbers[i];
		i++;
	}
	system("cls");
/*	for(i=0; i<difficulty; i++){
			for(j=0; j<difficulty; j++){
				if(table[i][j] < 10){
					printf(" %d    ", table[i][j]);
				}
				else{
					printf("%d    ", table[i][j]);
				}
				
			}
			printf("\n");
		} 
		getch();*/
//-------------------------------------------------GAME PART---------------------------------------------------------------
	while(win==0){
		system("cls");
	//--------------------------------------------------**USER**-----------------------------------------------------------		
		if(player==1){
			system("COLOR 0B");
			printf("Order: %s\nTour = %d\nPoint = %d\n\n", name, tour, point1);
			for(i=0; i<difficulty+1; i++){
				printf("\t");
				for(j=0; j<difficulty+1; j++){
					printf("%c   ", gameTable[i][j]);
				}
				printf("\n\n");
			}
			// FIRST COORDINATE INPUT
			printf("Enter Row Number of First Card: ");
			scanf("%d", &x1);
			printf("Enter Column Number of First Card: ");
			scanf("%d", &Y1);
			system("cls");
			x1 = x1%10;
			Y1 = Y1%10;
			// This is for if user tries to open an "already opened card" :)
			while(gameTable[x1][Y1] == '-'){
				for(i=0; i<difficulty+1; i++){
					printf("\t");
					for(j=0; j<difficulty+1; j++){
						printf("%c   ", gameTable[i][j]);
					}
					printf("\n\n");
				}
				printf("You Can't Select Point Earned Cards\n\nEnter Row Number of First Card: ");
				scanf("%d", &x1);
				printf("Enter Column Number of First Card: ");
				scanf("%d", &Y1);
				x1 = x1%10;
				Y1 = Y1%10;
				system("cls");
			}
			//Showing current table to the user
			printf("Order: %s\nTour = %d\nPoint = %d\n\n", name, tour, point1);
			for(i=0; i<difficulty+1; i++){
				printf("\t");
				for(j=0; j<difficulty+1; j++){
					if(i == x1 && j == Y1){
					printf("%d   ", table[i-1][j-1]);
					}
					else{printf("%c   ", gameTable[i][j]);}
				}
				printf("\n\n");
			}
			// SECOND COORDINATE INPUT
			// same as first input
			printf("Enter Row Number of Second Card: ");
			scanf("%d", &x2);
			printf("Enter Column Number of Second Card: ");
			scanf("%d", &y2);
			system("cls");
			x2 = x2%10;
			y2 = y2%10;
			while(gameTable[x2][y2] == '-' || (x1==x2 && Y1==y2)){
				for(i=0; i<difficulty+1; i++){
					printf("\t");
					for(j=0; j<difficulty+1; j++){
						if(i == x1 && j == Y1){
						printf("%d   ", table[i-1][j-1]);
						}
						else{printf("%c   ", gameTable[i][j]);}
					}
					printf("\n\n");
				}
				printf("You Can't Select Cards of the Same Position or Point Earned\n\nEnter Row Number of Second Card: ");
				scanf("%d", &x2);
				printf("Enter Column Number of Second Card: ");
				scanf("%d", &y2);
				x2 = x2%10;
				y2 = y2%10;
				system("cls");
			}
			//Showing Current Table To The User
			printf("Order: %s\nTour = %d\nPoint = %d\n\n", name, tour, point1);
			for(i=0; i<difficulty+1; i++){
				printf("\t");
				for(j=0; j<difficulty+1; j++){
					if((i == x2 && j == y2) || (i == x1 && j == Y1)){
						printf("%d   ", table[i-1][j-1]);
					}
					else{printf("%c   ", gameTable[i][j]);}
				}
				printf("\n\n");
			}
			//Control Part
			if(table[x1-1][Y1-1] == table[x2-1][y2-1]){
				point1 = point1 + 1;
				printf("Correct Match !!\n%s's Point: %d\nPress Any Key for Continue..",name ,point1);
				gameTable[x1][Y1] = '-';
				gameTable[x2][y2] = '-';
				table[x1-1][Y1-1] = -table[x1-1][Y1-1];
				table[x2-1][y2-1] = -table[x2-1][y2-1];
				if(point2 + point1 == length){
					win = 1;
				}
			}
			else{
				printf("False Match !!\n%s's Point: %d\nPress Any Key for Continue..",name ,point1);
				//-----------------Saving numbers into the memory
				j=0, found=0, player=2;
				while(found == 0 && memory[2][j] != 0 && j<memoryMax){
					if(x1 == memory[0][j] && Y1 == memory[1][j]){
						found = found + 2;
					}
					j++; // this is for not use a different variable, we can understand if it is odd or even number
				}
				j=0;
				while(memory[2][j] != 0 && j<memoryMax){
					if(x2 == memory[0][j] && y2 == memory[1][j]){
						found = found+1;
					}
					j++;
				}
				if(found == 0){
					for(i=memoryMax-1; i>1; i--){
							memory[0][i] = memory[0][i-2];
							memory[1][i] = memory[1][i-2];
							memory[2][i] = memory[2][i-2];
						}
					memory[2][0] = table[x1-1][Y1-1], memory[0][0] = x1, memory[1][0] = Y1;	
					memory[2][1] = table[x2-1][y2-1], memory[0][1] = x2, memory[1][1] = y2;
				}
				else if(found == 2){
					for(i=memoryMax-1; i>0; i--){
							memory[0][i] = memory[0][i-1];
							memory[1][i] = memory[1][i-1];
							memory[2][i] = memory[2][i-1];
						}
					memory[2][0] = table[x2-1][y2-1], memory[0][0] = x2, memory[1][0] = y2;
				}
				else if(found == 1){
					for(i=memoryMax-1; i>0; i--){
							memory[0][i] = memory[0][i-1];
							memory[1][i] = memory[1][i-1];
							memory[2][i] = memory[2][i-1];
						}
					memory[2][0] = table[x1-1][Y1-1], memory[0][0] = x1, memory[1][0] = Y1;	
				}
			}
			getch();
		}
//----------------------------------------------**COMPUTER**-------------------------------------------------------------
		else if(player==2){
			system("COLOR 0A");
			printf("Order: Computer\nPoint: %d\nTour: %d\n", point2, tour);
//-------------------------------------Comp. Finding Available Coordinate------------------------------------------------------
			i = 0;
			found=0;
			// Checking Memory to find a match
			if(difficulty != 4){
				while(i<memoryMax-3){
					x1 = memory[0][0], Y1 = memory[1][0];
					x2 = memory[0][1], y2 = memory[1][1];
					if(memory[2][0] == memory[2][i+2] && memory[2][0] != 0 && memory[2][0] != -1 && table[x1-1][Y1-1] > 0 ){
						x1 = memory[0][0];
						Y1 = memory[1][0];
						x2 = memory[0][i+2];
						y2 = memory[1][i+2];
						memory[2][0] = -1;
						memory[2][i+2] = -1;
						i = memoryMax;
						found = 1;
					}
					else if(memory[2][1] == memory[2][i+2] && memory[2][1] != 0 && memory[2][1] != -1 && table[x2-1][y2-1] > 0){
						x1 = memory[0][1];
						Y1 = memory[1][1];
						x2 = memory[0][i+2];
						y2 = memory[1][i+2];
						memory[2][1] = -1;
						memory[2][i+2] = -1;
						i = memoryMax;
						found = 1;
					}
					else{
						i++;
					}
				}
				i=0;
				while(i<memoryMax-3 && found == 0){
					x1 = memory[0][2], Y1 = memory[1][2];
					x2 = memory[0][3], y2 = memory[1][3];
					if(memory[2][2] == memory[2][i+4] && memory[2][2] != 0 && memory[2][2] != -1 && table[x1-1][Y1-1] > 0){
						x1 = memory[0][2];
						Y1 = memory[1][2];
						x2 = memory[0][i+2];
						y2 = memory[1][i+2];
						memory[2][2] = -1;
						memory[2][i+2] = -1;
						i = memoryMax;
						found = 1;
					}
					else if(memory[2][3] == memory[2][i+4] && memory[2][3] != 0 && memory[2][3] != -1 && table[x2-1][y2-1] > 0){
						x1 = memory[0][3];
						Y1 = memory[1][3];
						x2 = memory[0][i+4];
						y2 = memory[1][i+4];
						memory[2][3] = -1;
						memory[2][i+2] = -1;
						i = memoryMax;
						found = 1;
					}
					else{
						i++;
					}
				}
			}
			// If comp. can find any match in the memory, it doesn't create a new coordinate
			i=0;
			if(found == 0){
				x1 = (rand() % difficulty) + 1;
				Y1 = (rand() % difficulty) + 1;
				while(i<memoryMax){
				// If it creates a known coordinate, it creates a new one 
					if((x1 == memory[0][i] && Y1 == memory[1][i]) || (gameTable[x1][Y1] == '-')){
						x1 = (rand() % difficulty) + 1;
						Y1 = (rand() % difficulty) + 1;
						i=0;
					}
					else{
						i++;
					}
				}
				i=0;
				while(i<memoryMax){
					if(table[x1-1][Y1-1] == memory[2][i] && memory[0][i] != x1 && memory[1][i] != Y1){
						x2 = memory[0][i];
						y2 = memory[1][i];
						found=1;
						i=memoryMax;
					}
					else{
						i++;
					}
				}
				i=0;
				if(found == 0){
					x2 = (rand() % difficulty) + 1;
					y2 = (rand() % difficulty) + 1;
					while(i<memoryMax){
					// If it creates a known coordinate creates a new one 
						if((x2 == memory[0][i]) && (y2 == memory[1][i]) || (x2 == x1 && y2 == Y1) || (gameTable[x2][y2] == '-')){
							x2 = (rand() % difficulty) + 1;
							y2 = (rand() % difficulty) + 1;
							i=0;
						}
						else{
							i++;
						}
					}
				}
			}
			// Printing Table
			for(i=0; i<difficulty+1; i++){
				printf("\t");
				for(j=0; j<difficulty+1; j++){
					if((i == x2 && j == y2) || (i == x1 && j == Y1)){
						printf("%d   ", table[i-1][j-1]);
					}
					else{printf("%c   ", gameTable[i][j]);}
				}
				printf("\n\n");
			}
		/*	printf("\n(%d,%d) - (%d, %d)", x1, Y1, x2, y2); */
			// Control Part
			if(table[x1-1][Y1-1] == table[x2-1][y2-1]){
				point2 = point2 + 1;
				printf("Computer Got a Match!\nPoint of Comp.: %d\nDevam Etmek Icin Herhangi Bir Tusa Basiniz...", point2);
				gameTable[x1][Y1] = '-';
				gameTable[x2][y2] = '-';
				table[x1-1][Y1-1] = -table[x1-1][Y1-1];
				table[x2-1][y2-1] = -table[x2-1][y2-1];
				player = 2;
				if(point2 + point1 == length){
					win = 1;
				}
			}
			else{
				printf("Computer Couldn't Got a Match!\nPoint of Comp.: %d\nDevam Etmek Icin Herhangi Bir Tusa Basiniz...", point2);
				j=0, found=0, player=1;
				while(found == 0 && memory[2][j] != 0 && j<memoryMax){
					if(x1 == memory[0][j] && Y1 == memory[1][j]){
						found = found + 2;
					}
					j++; // this is for not use a different variable, we can understand if it is odd or even number
				}
				j=0;
				while(memory[2][j] != 0 && j<memoryMax){
					if(x2 == memory[0][j] && y2 == memory[1][j]){
						found = found+1;
					}
					j++;
				}
				if(found == 0){
					for(i=memoryMax-1; i>1; i--){
							memory[0][i] = memory[0][i-2];
							memory[1][i] = memory[1][i-2];
							memory[2][i] = memory[2][i-2];
						}
					memory[2][0] = table[x1-1][Y1-1], memory[0][0] = x1, memory[1][0] = Y1;	
					memory[2][1] = table[x2-1][y2-1], memory[0][1] = x2, memory[1][1] = y2;
				}
				else if(found == 2){
					for(i=memoryMax-1; i>0; i--){
							memory[0][i] = memory[0][i-1];
							memory[1][i] = memory[1][i-1];
							memory[2][i] = memory[2][i-1];
						}
					memory[2][0] = table[x2-1][y2-1], memory[0][0] = x2, memory[1][0] = y2;
				}
				else if(found == 1){
					for(i=memoryMax-1; i>0; i--){
							memory[0][i] = memory[0][i-1];
							memory[1][i] = memory[1][i-1];
							memory[2][i] = memory[2][i-1];
						}
					memory[2][0] = table[x1-1][Y1-1], memory[0][0] = x1, memory[1][0] = Y1;
				}
			/*	for(i=0;i<memoryMax; i++){
					printf("\n(%d,%d): %d", memory[0][i], memory[1][i], memory[2][i]);
				} */
				}
			getch();
		}
		tour++;
	}
	system("cls");
	if(point1 > point2){
		printf("Congrats You Won the Game...\nPoint: %d\nTour: %d", point1, tour);
	}
	else if(point1 == point2){
		system("COLOR 0F");
		printf("Draw!!\nTour: %d", tour);
	}
	else{
		printf("Computer Won the Game...\nPoint of Comp.: %d\nTour: %d", point2, tour);
	}
	getch();
	return 0;
}
