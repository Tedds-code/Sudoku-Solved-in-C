#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **get_Sudoku(char*);
void validate_Sudoku(char**, int, int);
int validate_Cols(char**,int,int);
int validate_Rows(char**,int,int);
int validate_Box(char**,int,int);

int main(int argc, char *argv[]){
	
	if(argc == 2){
		char ** A = get_Sudoku(argv[1]);
	}
	else{
		printf("Δεν έχει συμπληρωθεί ο κατάλληλος αριθμός από ορίσματα. Απαιτούνται 2, υπάρχουν %d.\n",argc);	
		exit(1);
	}
	
	return 0;	
}


char **get_Sudoku(char* arg){
	
	char **A = (char**)malloc(sizeof(char*)*9);
	for(int i = 0; i < 9; i++){
		A[i] = (char*)malloc(sizeof(char)*9);	
	}
	
	FILE *file = fopen(arg,"r");
	if(file == NULL){
		printf("Δεν άνοιξε το αρχείο.\n");
		exit(1);
	}
	int col = 0, row = 0, ch;
	while((ch = fgetc(file)) != EOF){
		if(ch == '\n'){
			continue;	
		}
		A[row][col] = (char)ch;
		col++;
		if(col == 9){
			col = 0;
			row++;
			
		}
			
	}
	validate_Sudoku(A,row,col);
	
	return A;
}


void validate_Sudoku(char** A, int row, int col){
	char ch;
	int check;
	
	if(row < 8){
		printf("Το αρχείο δεν περιέχει 9 γραμμές, αλλά μόνο %d.\n",col);
		exit(1);
	}else if(col != 0){
		printf("Το αρχείο δεν περιέχει τον απαιτούμενο αριθμό από στοιχεία, δηλαδή 81, αλλά μόνο %d.\n",(81-(9-row)));
		exit(1);
	}
	
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if((ch = A[i][j])!= '0'){
				
				if(!(check = validate_Cols(A,i,j))){
					printf("Η στήλη %d έχει τουλάχιστον δύο φορές το %c, άρα ο πίνακας δεν είναι έγκυρο Sudoku.\n",j+1,ch);
					exit(1);	
				}
				if(!(check = validate_Rows(A,i,j))){
					printf("Η γραμμή %d έχει τουλάχιστον δύο φορές το %c, άρα ο πίνακας δεν είναι έγκυρο Sudoku.\n",i+1,ch);
					exit(1);	
				}
				if(!(check = validate_Box(A,i,j))){
					printf("Το 3Χ3 κουτί που εμπεριέχει το κελί της γραμμής %d και της στήλης %d περιέχει τουλάχιστον δύο φορές το %c, άρα δεν είναι έγκυρος πίνακας Sudoku.\n",i+1,j+1,ch);
					exit(1);
				}
			}
		}	
	}
	
	
}



int validate_Cols(char **A, int row, int col){
	char ch = A[row][col];
	for(int i = 0; i<9; i++){
		if(i == row) continue;
		if(A[i][col] == ch) return 0;	
	}
	return 1;
	
}

int validate_Rows(char **A, int row, int col){
	char ch = A[row][col];
	for(int i = 0; i<9; i++){
		if(i == col) continue;
		if(A[row][i] == ch) return 0;
	}
	return 1;
}

int validate_Box(char** A, int row, int col){
	char ch = A[row][col];
	int rowGr = row / 3;
	int colGr = col / 3;
	
	rowGr = rowGr * 3;
	colGr = colGr * 3;
	
	for(int i = rowGr; i < rowGr + 3; i++){
		for(int j = colGr; j < colGr + 3; j++){
			if(j == col && i == row) continue;
			if(ch == A[i][j]) return 0;
		}	
	}
	
	return 1;
}

