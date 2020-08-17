
#include<iostream>
#include<cstring>
using namespace std;
#define N 4 
void printSolution(int board[][50]) 
{ 
	static int k = 1; 
	for (int i = 0; i < N; i++) 
	{ 
		for (int j = 0; j < N; j++) 
			if(board[i][j]==1) cout<<"["<<i<<"-"<<j<<"]";
	} 
	printf("\n"); 
} 
bool isSafe(int board[][50], int row, int col) 
{ 
	int i, j; 
	for (i = 0; i < col; i++) 
		if (board[row][i]) 
			return false; 
	for (i=row, j=col; i>=0 && j>=0; i--, j--) 
		if (board[i][j]) 
			return false; 
	for (i=row, j=col; j>=0 && i<N; i++, j--) 
		if (board[i][j]) 
			return false; 

	return true; 
} 

bool solveNQUtil(int board[][50], int col) 
{ 
	if (col == N) 
	{ 
		printSolution(board); 
		return true; 
	} 
	bool res = false; 
	for (int i = 0; i < N; i++) 
	{ 
		if ( isSafe(board, i, col) ) 
		{ 
			board[i][col] = 1; 
			res = solveNQUtil(board, col + 1) || res; 
			board[i][col] = 0; // BACKTRACK 
		} 
	} 
	return res; 
} 
void solveNQ(int n) 
{ 
	int board[50][50]; 
	memset(board, 0, sizeof(board)); 

	if (solveNQUtil(board, 0) == false) 
	{ 
		printf("Solution does not exist"); 
		return ; 
	} 

	return ; 
} 

int main() 
{ 
    int n=4;
	solveNQ(n); 
	return 0; 
} 
