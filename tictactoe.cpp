// code by PhamVanHiep_K68-UET

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void print(char **matrix){
	for( int i = 0; i < 3; i++){
		for( int j = 0; j < 3; j++){
			printf("%c|", matrix[i][j]);
		}
		printf("\n");
	}
}

void computerChoice(char **matrix){
	int a = 0,b = 0,c = 0;
	for( int i = 0; i < 3; i++){
		for( int j = 0; j < 3; j++){
			if( i == 0){if(matrix[i][j] == ' '){a++;}}
			if( i == 1){if(matrix[i][j] == ' '){b++;}}
			if( i == 2){if(matrix[i][j] == ' '){c++;}}
		}
	}
	if ( a > 0){
		for( int i = 0; i < 3; i++){
			if(matrix[0][i] == ' '){
				matrix[0][i] = 'o';
				break;
			}
		}
	}else{
		if( b > 0){
			for( int i = 0; i < 3; i++){
				if(matrix[1][i] == ' '){
					matrix[1][i] = 'o';
					break;
				}
			}
		}else{
			if( c > 0){
				for( int i = 0; i < 3; i++){
					if(matrix[2][i] == ' '){
						matrix[2][i] = 'o';
						break;
					}
				}
			}
		}
	}
}

int checkTest( char **matrix, char choice){
	if( matrix[0][0] == choice && matrix[0][1] == choice && matrix[0][2] == choice){return -1;}
	if( matrix[1][0] == choice && matrix[1][1] == choice && matrix[1][2] == choice){return -1;}
	if( matrix[2][0] == choice && matrix[2][1] == choice && matrix[2][2] == choice){return -1;}
	if( matrix[0][1] == choice && matrix[1][1] == choice && matrix[2][1] == choice){return -1;}
	if( matrix[0][2] == choice && matrix[1][2] == choice && matrix[2][2] == choice){return -1;}
	if( matrix[0][0] == choice && matrix[1][0] == choice && matrix[2][0] == choice){return -1;}
	if( matrix[0][0] == choice && matrix[1][1] == choice && matrix[2][2] == choice){return -1;}
	if( matrix[0][2] == choice && matrix[1][1] == choice && matrix[2][0] == choice){return -1;}
}
	
int check(char **matrix){
	char choiceX = 'x';
	char choiceO = 'o';
	if (checkTest(matrix,choiceX) == -1){return 1;}
	if (checkTest(matrix,choiceO) == -1){return 2;}
	int k = 0;
	for( int i = 0; i < 3; i++){
		for( int j = 0; j < 3; j++){
			if (matrix[i][j] != ' '){
				k++;
			}
		}
	}
	if( k == 9){
		return 0;
	}
	return 3;
}
	
	//return 3 = continue
	//return 2 = computerWin
	//return 1 = humanWin
	//return 0 = Draw
	
int main(){
	//heading
	char **matrix;
		// cap phat bo nho //
	matrix = (char **)malloc(3 * sizeof(char *));
    for (int i = 0; i < 3; i++) {
        matrix[i] = (char *)malloc(3 * sizeof(char));
    }
    int ben;
	printf("[1]: player vs computer\n[2]: player vs player\n=> YourChoice: ");
	scanf("%i",&ben);
	system("cls");
    for( int i = 0; i < 3; i++){
		for( int j = 0; j < 3; j++){
			matrix[i][j] = ' '; 
		}
	}
    for( int i = 0; i < 3; i++){
		for( int j = 0; j < 3; j++){
			printf("%c|", matrix[i][j]);
		}
		printf("\n");
	}
	char choiceX = 'x';
	char choiceO = 'o';
	//gamePlay
	if( ben == 1){
		while(1){
		int m,n;
		printf("YourChoice: ");scanf("%i%i",&m,&n);
		m = m-1;
		n = n-1;
		// choice X
		matrix[m][n] = 'x';
		system("cls");
		print(matrix);
		if(check(matrix) == 0){printf("Draw");break;}
		if(check(matrix) == 1){printf("You Win");break;}
		if(check(matrix) == 2){printf("You Lost");break;}
		// choice O	
		computerChoice(matrix);
		system("cls");
		print(matrix);
			
		// endGame
		if(check(matrix) == 0){printf("Draw");break;}
		if(check(matrix) == 1){printf("You Win");break;}
		if(check(matrix) == 2){printf("You Lost");break;}
	}
	}else{
		while(1){
		int m,n,p,q;
		printf("Player 1: ");scanf("%i%i",&m,&n);
		m = m-1;
		n = n-1;
		// choice X
		matrix[m][n] = 'x';
		system("cls");
		// choice O	
		print(matrix);
		
		if(check(matrix) == 0){printf("Draw");break;}
		if(check(matrix) == 1){printf("Player 1 Win");break;}
		if(check(matrix) == 2){printf("Player 2 Win");break;}
		
		printf("Player 2: ");scanf("%i%i",&p,&q);
		matrix[p-1][q-1] = 'o';
		system("cls");
		print(matrix);
			
		// endGame
		if(check(matrix) == 0){printf("Draw");break;}
		if(check(matrix) == 1){printf("Player 1 Win");break;}
		if(check(matrix) == 2){printf("Player 2 Win");break;}
	}
	}	
}
