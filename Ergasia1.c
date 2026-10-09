#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **get_Sudoku(char*);
void validate_Sudoku(char**, int, int);


int main(int argc, char *argv[]){
	
	
	
	return 0;	
}


char **getSudoku(char* arg){
	
	char **A = (char**)malloc(sizeof(char*)*9);
	for(int i = 0; i < 9; i++){
		A[i] = (char*)malloc(sizeof(char)*9);	
	}
	
	FILE *file = fopen(arg,"r");
	int col = 0, row = 0, ch;
	while((ch = fgetc(file)) != EOF){
		if(ch == '\n'){
			continue;	
		}
		A[row][col] = (char)ch;
		row++;
		if(row == 9){
			row = 0;
			col++;
			
		}
			
	}
	
	
	return A;
}


void validate_Sudoku(char** A, int col, int rows){
		
	
}
